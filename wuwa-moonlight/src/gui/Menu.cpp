#include "Menu.hpp"
#include <gui/assets/fonts/font.h>
#include <imgui.h>
#include <chrono>
#include <iostream>
#include <imgui_internal.h>

#include <Features/Features.h>
#include <Config/ConfigManager.h>

void Menu::Setup()
{
    if (bOnceStyle && ImGui::GetCurrentContext()) return;

    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;
    ImVec2 whole_content_size = io.DisplaySize;
    whole_content_size.x = whole_content_size.x * 0.3f;
    whole_content_size.y = whole_content_size.y * 0.2f;

    // Theme initialization
    SetUpColors(style, colors);

    ImFontConfig font_config;
    font_config.PixelSnapH = false;
    font_config.OversampleH = 5;
    font_config.OversampleV = 5;
    font_config.RasterizerMultiply = 1.2f;

    ImFontConfig icontfont_config;
    icontfont_config.MergeMode = true;
    icontfont_config.GlyphMinAdvanceX = iconFontSize;
    icontfont_config.PixelSnapH = true;

    static const ImWchar ranges[] =
    {
        0x0020, 0x00FF, // Basic Latin + Latin Supplement
        0x0400, 0x052F, // Cyrillic + Cyrillic Supplement
        0x2DE0, 0x2DFF, // Cyrillic Extended-A
        0xA640, 0xA69F, // Cyrillic Extended-B
        0xE000, 0xE226, // icons
        0 };

    //static const ImWchar iconRanges[] =
    //{
    //    ICON_MIN_FA,
    //    ICON_MAX_16_FA, // awesome font icons
    //    0,
    //};

    io.Fonts->AddFontDefault();
    font_regular = io.Fonts->AddFontFromMemoryTTF(RobotoRegular, sizeof(RobotoRegular), 15.0f, &font_config, ranges);
    font_medium = io.Fonts->AddFontFromMemoryTTF(RobotoMedium, sizeof(RobotoMedium), 15.0f, &font_config, ranges);
    font_bold = io.Fonts->AddFontFromMemoryTTF(RobotoBold, sizeof(RobotoBold), 15.0f, &font_config, ranges);
    font_title = io.Fonts->AddFontFromMemoryTTF(RobotoBold, sizeof(RobotoBold), 25.0f, &font_config, ranges);
    //icons = io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME_FAS, iconFontSize, &icontfont_config, iconRanges);

    io.FontDefault = font_regular;


    // Register event manager for menu

    this->AddStateChangeCallback([this](bool newState) {
        this->ShowCursor(newState);
    });

    bOnceStyle = true; // is initialized = true
}

void Menu::SetUpColors(ImGuiStyle& style, ImVec4* colors)
{
    ImColor hovered = { 31, 110, 171 };
    ImColor Transparented = { 0, 0, 0, 255 };
    colors[ImGuiCol_WindowBg] = ImColor(20, 23, 25);
    colors[ImGuiCol_ChildBg] = ImColor(24, 28, 30);
    colors[ImGuiCol_Text] = ImColor(255, 255, 255);

    // Header
    colors[ImGuiCol_Header] = ImColor(30, 138, 200);
    colors[ImGuiCol_HeaderHovered] = hovered;
    colors[ImGuiCol_HeaderActive] = ImColor(30, 116, 215);

    // buttons
    colors[ImGuiCol_Button] = ImColor(25, 145, 215);
    colors[ImGuiCol_ButtonHovered] = hovered;
    colors[ImGuiCol_ButtonActive] = ImColor(100, 161, 222);

    // checkboxes
    colors[ImGuiCol_CheckMark] = ImColor(0, 0, 0);
    colors[ImGuiCol_FrameBg] = ImColor(25, 158, 215, 200);
    colors[ImGuiCol_FrameBgActive] = ImColor(25, 164, 215);
    colors[ImGuiCol_FrameBgHovered] = ImColor(20, 212, 250);

    colors[ImGuiCol_Border] = Transparented;

    style.WindowRounding = 10.0f;
    style.FrameRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 2.3f;
    style.TabRounding = 2.3f;

    // style.WindowMinSize = { 600,300 };
    style.ChildRounding = 5.0f;
}

void Menu::PreventMoveOutOfWndBounds(const char* wndName)
{
    ImGuiWindow* existingWindow = ImGui::FindWindowByName(wndName);
    if (existingWindow != nullptr)
    {
        bool needsClampToScreen = false;
        ImVec2 targetPos = existingWindow->Pos;
        if (existingWindow->Pos.x < 0.0f)
        {
            needsClampToScreen = true;
            targetPos.x = 0.0f;
        }
        else if (existingWindow->Size.x + existingWindow->Pos.x > ImGui::GetMainViewport()->Size.x)
        {
            needsClampToScreen = true;
            targetPos.x = ImGui::GetMainViewport()->Size.x - existingWindow->Size.x;
        }
        if (existingWindow->Pos.y < 0.0f)
        {
            needsClampToScreen = true;
            targetPos.y = 0.0f;
        }
        else if (existingWindow->Size.y + existingWindow->Pos.y > ImGui::GetMainViewport()->Size.y)
        {
            needsClampToScreen = true;
            targetPos.y = ImGui::GetMainViewport()->Size.y - existingWindow->Size.y;
        }

        if (needsClampToScreen) // Necessary to prevent window from constantly undocking itself if docked.
        {
            ImGui::SetNextWindowPos(targetPos, ImGuiCond_Always);
        }
    }
}

void Menu::RenderMenu()
{
    if (!IsOpen()) return;

    static Headers tab = PLAYER;
    const char* tab_names[] = { "PLAYER", "ESP", "MISC", "CONFIG", /*"DEBUG"*/ };

    ImVec2 wndSize = ImGui::GetIO().DisplaySize;
    ImVec2 minSize(600, 300);
    ImVec2 maxSize(wndSize);

    // Fix the next window size
    ImGui::SetNextWindowSizeConstraints(minSize, maxSize);
    if (ImGui::Begin("Moonlight", nullptr, /*ImGuiWindowFlags_NoDecoration |*/ ImGuiWindowFlags_NoTitleBar))
    {
        ImVec2 pos = ImGui::GetWindowPos();
        ImVec2 size = ImGui::GetWindowSize();

        ImVec2 wndSize = ImGui::GetWindowSize();

        ImGuiStyle style = ImGui::GetStyle();
        ImDrawList* draw = ImGui::GetWindowDrawList();

        float minWidth = 120;

        ImVec2 mainLeftSize = ImVec2(ImGui::GetContentRegionAvail().x * 0.16f, ImGui::GetContentRegionAvail().y);
        mainLeftSize.x = ImClamp(mainLeftSize.x, minWidth, wndSize.x);

        ImGui::BeginChild("MainLeft", mainLeftSize, 0);
        {

            ImVec2 leftTopChildSize = ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y * 0.16f);
            ImGui::BeginChild("LeftSide1", leftTopChildSize, false);

            ImGui::PushFont(font_title);

            ImVec2 textSize = ImGui::CalcTextSize("Moonlight");

            float posX = (leftTopChildSize.x - textSize.x) * 0.5f;
            float posY = (leftTopChildSize.y - textSize.y) * 0.5f;

            ImGui::SetCursorPos(ImVec2(posX, posY));

            ImGui::TextColored(ImColor(84, 160, 227), "Moonlight");

            ImGui::PopFont();
            ImGui::EndChild();

            if (ImGui::BeginChild("LeftSide2", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), 0))
            {
                for (unsigned int i = 0; i < HEADERS_COUNT; ++i)
                {
                    bool selected = (tab == static_cast<Headers>(i));
                    auto windowvars = ImGuiStyleVar_SelectableTextAlign;

                    ImGui::PushStyleVar(windowvars, ImVec2(0.5f, 0.5f));

                    if (ImGui::Selectable(tab_names[i], &selected, 0, ImVec2(ImGui::GetContentRegionAvail().x, 24)))
                        tab = static_cast<Headers>(i);

                    ImGui::PopStyleVar();

                    if (selected)
                        ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndChild();
        }
        ImGui::EndChild();
    }

    ImGui::SameLine(0);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(20, 20));

    ImGui::BeginChild("RightSide", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), 0);

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Indent(10.0f);

    switch (tab)
    {
    case PLAYER:
        speedhack->Draw();
        fly->Draw();
        //gravityScale.DrawMenuItems();
        //walkFloorZ.DrawMenuItems();
        //walkFloorAngle.DrawMenuItems();
        multihit->Draw();

        break;

    case ESP:
        esp->Draw();
        break;

    case MISC:
        fpsUnlock->Draw();
        ptpsafe->Draw();

        debugComponent->Draw();
        pView->Draw();

        if (ImGui::Button("Force exit"))
            ExitProcess(0);

        break;

    case CONFIG:
        RenderConfigTab();
        break;
    }

    ImGui::Unindent();
    ImGui::Spacing();
    ImGui::Spacing();

    ImGui::EndChild();
    ImGui::PopStyleVar();

    ImGui::End();
}

void Menu::RenderConfigTab()
{
    static char configNameBuffer[256] = { 0 };
    static int selectedConfig = -1;
    
    // Получаем список всех доступных конфигов
    auto& configManager = ConfigManager::GetInstance();
    std::vector<std::string> availableConfigs = configManager.GetAvailableConfigs();
    
    // Текущий активный конфиг
    std::string currentConfig = configManager.GetCurrentConfig();
    
    // Если список конфигов изменился, обновляем выбранный индекс
    static int lastConfigCount = 0;
    if (lastConfigCount != availableConfigs.size()) {
        lastConfigCount = availableConfigs.size();
        
        // Находим индекс текущего конфига
        selectedConfig = -1;
        for (size_t i = 0; i < availableConfigs.size(); i++) {
            if (availableConfigs[i] == currentConfig) {
                selectedConfig = static_cast<int>(i);
                break;
            }
        }
    }
    
    // Секция создания нового конфига
    ImGui::Text("Create new config");
    ImGui::InputText("##ConfigName", configNameBuffer, sizeof(configNameBuffer));
    ImGui::SameLine();
    
    if (ImGui::Button("Create and save"))
    {
        if (strlen(configNameBuffer) > 0)
        {
            // Собираем все features в один вектор
            std::vector<std::shared_ptr<IFeatureFactory>> features;
            features.push_back(fpsUnlock);
            features.push_back(esp);
            features.push_back(speedhack);
            features.push_back(multihit);
            features.push_back(fly);
            features.push_back(ptpsafe);
            features.push_back(debugComponent);
            
            // Сохраняем конфиг
            bool success = configManager.SaveConfig(features, configNameBuffer);
            
            if (success)
            {
                LOG_INFO("Config created: %s", configNameBuffer);
                memset(configNameBuffer, 0, sizeof(configNameBuffer));
                // Обновляем список конфигов
                availableConfigs = configManager.GetAvailableConfigs();
                lastConfigCount = availableConfigs.size();
            }
        }
    }
    
    ImGui::Separator();
    
    // Секция управления существующими конфигами
    ImGui::Text("Config manager");
    
    if (availableConfigs.empty())
    {
        ImGui::TextColored(ImVec4(1.0f, 0.5f, 0.5f, 1.0f), "No configs");
    }
    else
    {
        if (ImGui::BeginListBox("##ConfigsList", ImVec2(-FLT_MIN, 200)))
        {
            for (int i = 0; i < static_cast<int>(availableConfigs.size()); i++)
            {
                const bool isSelected = (selectedConfig == i);
                
                // Показываем отметку для текущего активного конфига
                std::string label = availableConfigs[i];
                if (availableConfigs[i] == currentConfig)
                {
                    label += " (active)";
                }
                
                if (ImGui::Selectable(label.c_str(), isSelected))
                {
                    selectedConfig = i;
                    LOG_INFO("Selected config: %s", availableConfigs[i].c_str());
                }
                
                if (isSelected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndListBox();
        }
        
        // Кнопки действий с выбранным конфигом
        ImGui::BeginDisabled(selectedConfig == -1);
        
        if (ImGui::Button("Load"))
        {
            if (selectedConfig >= 0 && selectedConfig < static_cast<int>(availableConfigs.size()))
            {
                // Собираем все features в один вектор
                std::vector<std::shared_ptr<IFeatureFactory>> features;
                features.push_back(fpsUnlock);
                features.push_back(esp);
                features.push_back(speedhack);
                features.push_back(multihit);
                features.push_back(fly);
                features.push_back(ptpsafe);
                features.push_back(debugComponent);
                
                // Загружаем конфиг
                bool success = configManager.LoadConfig(features, availableConfigs[selectedConfig]);
                if (success) {
                    LOG_INFO("Config loaded: %s", availableConfigs[selectedConfig].c_str());
                } else {
                    LOG_ERROR("Failed to load config: %s", availableConfigs[selectedConfig].c_str());
                }
            }
        }
        
        ImGui::SameLine();
        
        if (ImGui::Button("Remove"))
        {
            if (selectedConfig >= 0 && selectedConfig < static_cast<int>(availableConfigs.size()))
            {
                std::string configToDelete = availableConfigs[selectedConfig];
                bool success = configManager.DeleteConfig(configToDelete);
                if (success) {
                    LOG_INFO("Config deleted: %s", configToDelete.c_str());
                } else {
                    LOG_ERROR("Failed to delete config: %s", configToDelete.c_str());
                }
                
                // Обновляем список конфигов
                availableConfigs = configManager.GetAvailableConfigs();
                lastConfigCount = availableConfigs.size();
                
                // Сбрасываем выбор, если список пуст
                if (selectedConfig >= static_cast<int>(availableConfigs.size()))
                {
                    selectedConfig = availableConfigs.empty() ? -1 : 0;
                }
            }
        }
        
        ImGui::SameLine();
        
        if (ImGui::Button("Save changes"))
        {
            if (selectedConfig >= 0 && selectedConfig < static_cast<int>(availableConfigs.size()))
            {
                // Собираем все features в один вектор
                std::vector<std::shared_ptr<IFeatureFactory>> features;
                features.push_back(fpsUnlock);
                features.push_back(esp);
                features.push_back(speedhack);
                features.push_back(multihit);
                features.push_back(fly);
                features.push_back(ptpsafe);
                features.push_back(debugComponent);
                
                // Сохраняем изменения в выбранный конфиг
                bool success = configManager.SaveConfig(features, availableConfigs[selectedConfig]);
                if (success) {
                    LOG_INFO("Config saved: %s", availableConfigs[selectedConfig].c_str());
                } else {
                    LOG_ERROR("Failed to save config: %s", availableConfigs[selectedConfig].c_str());
                }
            }
        }
        
        ImGui::EndDisabled();
    }
    
    ImGui::Separator();
    
    // Секция информации об активном конфиге
    ImGui::Text("Active config: %s", currentConfig.c_str());
    
    if (ImGui::Button("Save current settings"))
    {
        // Собираем все features в один вектор
        std::vector<std::shared_ptr<IFeatureFactory>> features;
        features.push_back(fpsUnlock);
        features.push_back(esp);
        features.push_back(speedhack);
        features.push_back(multihit);
        features.push_back(fly);
        features.push_back(ptpsafe);
        features.push_back(debugComponent);
        
        // Сохраняем конфиг
        bool success = configManager.SaveConfig(features);
        if (success) {
            LOG_INFO("Current settings saved to: %s", currentConfig.c_str());
        } else {
            LOG_ERROR("Failed to save current settings");
        }
    }
}

void Menu::RenderWatermark()
{
    if (!bWatermark) return;

    auto time = std::chrono::system_clock::now();
    std::time_t formatedtime = std::chrono::system_clock::to_time_t(time);

    ImGui::SetNextWindowPos(ImVec2(15, 15));
    ImGui::SetNextWindowSize({});

    ImGui::Begin("watermark", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoNav);
    ImGui::Text("Moonlight | github.com/chadlrnsn/wuwa-moonlight");
    ImGui::End();
}

bool Menu::IsOpen() const
{
    return bIsOpen;
}

void Menu::SetIsOpen(bool isOpen)
{
    this->bIsOpen = isOpen;
}

void Menu::Toggle()
{
    if (!SDK::UKuroStaticLibrary::IsForegroundWindow()) return;

    bOldState = bIsOpen;
    bIsOpen = !bIsOpen;

    if (bOldState != bIsOpen) {
        for (const auto& callback : stateChangeCallbacks) {
            callback(bIsOpen);
        }
    }
}

void Menu::HandleKey()
{
    if (GetAsyncKeyState(VK_INSERT) & 1) {
        Toggle();
    }
}

void Menu::AddStateChangeCallback(StateChangeCallback callback)
{
    stateChangeCallbacks.push_back(callback);
}

bool Menu::ShowCursor(bool show)
{
    if (!player_controller) 
    {
        LOG_WARN("Due to no pointer to player controller I can't show cursor...");
        return false;
    }

    bCurrentCursorState = player_controller->bShowMouseCursor;
    if (bIsOpen) {
        // When menu is open, show the cursor
        player_controller->bShowMouseCursor = true;
        bCurrentCursorState = true;
        LOG_INFO("Cursor shown because menu is open");
        return true;
    } else {
        // When menu is closed, keep cursor visible if it was previously open
        if (bOldState) {
            player_controller->bShowMouseCursor = true;
            bCurrentCursorState = true;
            LOG_INFO("Cursor remains visible due to previous menu state");
            return true;
        } else {
            // Otherwise, hide the cursor
            player_controller->bShowMouseCursor = false;
            bCurrentCursorState = false;
            LOG_INFO("Cursor hidden because menu is closed and was not previously open");
            return false;
        }
    }

    return false;
}

// void Menu::RenderNotify()
// {
//     // Setup style like main window

//     ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.f);
//     ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f); // Disable borders

//     // Notifications color setup
//     //ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.10f, 0.10f, 0.10f, 1.00f)); // Background color

//     // Main rendering function
//     ImGui::RenderNotifications();

//     //������������������������������� WARNING �������������������������������
//     // Argument MUST match the amount of ImGui::PushStyleVar() calls
//     ImGui::PopStyleVar(2);
//     // Argument MUST match the amount of ImGui::PushStyleColor() calls
//     //ImGui::PopStyleColor(1);
// }
