#include "Menu.hpp"
#include "fonts/font.h"

void Menu::RealCursorShow() {
    ImGui::GetMouseCursor();
    ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
    ImGui::GetIO().WantCaptureMouse = IsOpen;
    ImGui::GetIO().MouseDrawCursor = IsOpen;
}

void Menu::Setup()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;
    ImVec2 whole_content_size = io.DisplaySize;
    whole_content_size.x = whole_content_size.x * 0.3;
    whole_content_size.y = whole_content_size.y * 0.2;
    this->SetUpColors(style, colors);

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
        0
    };

    static const ImWchar iconRanges[] =
    {
        ICON_MIN_FA, ICON_MAX_16_FA, // awesome font icons
        0,
    };

    io.Fonts->AddFontDefault();
    regular = io.Fonts->AddFontFromMemoryTTF(RobotoRegular, sizeof(RobotoRegular), 15.0f, &font_config, ranges);
    medium  = io.Fonts->AddFontFromMemoryTTF(RobotoMedium, sizeof(RobotoMedium), 15.0f, &font_config, ranges);
    bold    = io.Fonts->AddFontFromMemoryTTF(RobotoBold, sizeof(RobotoBold), 15.0f, &font_config, ranges);
    title   = io.Fonts->AddFontFromMemoryTTF(RobotoBold, sizeof(RobotoBold), 25.0f, &font_config, ranges);
    icons   = io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME_FAS, iconFontSize, &icontfont_config, iconRanges);

    io.FontDefault = regular;
}

void Menu::SetUpColors(ImGuiStyle& style, ImVec4* colors) {

    ImColor hovered = { 31, 110, 171 };
    ImColor Transparented = { 0, 0, 0, 255 };
    colors[ImGuiCol_WindowBg] = ImColor(20, 23, 25);
    colors[ImGuiCol_ChildBg] = ImColor(24, 28, 30);
    colors[ImGuiCol_Text] = ImColor(255, 255, 255);
    
    //Header
    colors[ImGuiCol_Header] = ImColor(30, 138, 200);
    colors[ImGuiCol_HeaderHovered] = hovered;
    colors[ImGuiCol_HeaderActive] = ImColor(30, 116, 215);
    
    //buttons
    colors[ImGuiCol_Button] = ImColor(25, 145, 215);
    colors[ImGuiCol_ButtonHovered] = hovered;
    colors[ImGuiCol_ButtonActive] = ImColor(100, 161, 222);

    //checkboxes
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

    //style.WindowMinSize = { 600,300 };
    style.ChildRounding = 5.0f;
}

void Menu::StyleColors(ImGuiStyle & style, ImVec4 * colors, ImVec2 windowSize) {
    // Colors
    colors[ImGuiCol_Text] = ImVec4(0.90f, 0.95f, 1.00f, 1.00f); // Светло-голубой текст
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f); // Неизмененный
    colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.30f, 0.95f); // Темно-синий фон окна
    colors[ImGuiCol_ChildBg] = ImVec4(0.12f, 0.12f, 0.35f, 0.85f); // Немного светлее фон для дочерних окон
    colors[ImGuiCol_PopupBg] = ImVec4(0.10f, 0.10f, 0.30f, 1.00f); // Темно-синий фон всплывающих окон
    colors[ImGuiCol_Border] = ImVec4(0.25f, 0.40f, 0.70f, 1.00f); // Голубая рамка
    colors[ImGuiCol_BorderShadow] = ImVec4(0.05f, 0.05f, 0.15f, 1.00f); // Темно-синий тень рамки
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.20f, 0.50f, 1.00f); // Темно-голубой фон для фреймов
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.25f, 0.30f, 0.60f, 1.00f); // Немного светлее при наведении
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.30f, 0.35f, 0.70f, 1.00f); // Ещё светлее при активном состоянии
    colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.15f, 0.40f, 1.00f); // Темно-синий фон заголовка
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.20f, 0.25f, 0.50f, 1.00f); // Светлее активный заголовок
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.10f, 0.15f, 0.40f, 1.00f); // Такой же как и обычный
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.20f, 0.45f, 1.00f); // Темно-голубой фон меню
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.50f, 1.00f); // Голубой фон для скроллбара
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.25f, 0.35f, 0.60f, 1.00f); // Посветлее цвет для скроллбара
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.30f, 0.40f, 0.70f, 1.00f); // Светло-голубой при наведении
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.35f, 0.45f, 0.80f, 1.00f); // Ещё светлее при активном состоянии
    colors[ImGuiCol_CheckMark] = ImVec4(0.15f, 0.45f, 0.85f, 1.00f); // Ярко-синий
    colors[ImGuiCol_SliderGrab] = ImVec4(0.25f, 0.35f, 0.60f, 1.00f); // Голубой
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.30f, 0.40f, 0.70f, 1.00f); // Светло-голубой
    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.30f, 0.50f, 1.00f); // Темно-голубой фон кнопки
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.30f, 0.40f, 0.70f, 1.00f); // Светло-голубой при наведении
    colors[ImGuiCol_ButtonActive] = ImVec4(0.35f, 0.45f, 0.80f, 1.00f); // Ещё светлее при активном состоянии
    colors[ImGuiCol_Header] = ImVec4(0.25f, 0.35f, 0.60f, 1.00f); // Голубой фон заголовка
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.30f, 0.40f, 0.70f, 1.00f); // Светло-голубой при наведении
    colors[ImGuiCol_HeaderActive] = ImVec4(0.35f, 0.45f, 0.80f, 1.00f); // Ещё светлее при активном состоянии
    colors[ImGuiCol_Separator] = ImVec4(0.25f, 0.35f, 0.60f, 1.00f); // Голубой цвет разделителя
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.30f, 0.40f, 0.70f, 1.00f); // Светло-голубой при наведении
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.35f, 0.45f, 0.80f, 1.00f); // Ещё светлее при активном состоянии
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.20f, 0.60f, 0.85f, 0.25f); // Полупрозрачный ярко-голубой
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.20f, 0.60f, 0.85f, 0.67f); // Ярко-голубой при наведении
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.20f, 0.60f, 0.85f, 0.95f); // Насыщенный ярко-голубой при активном состоянии
    colors[ImGuiCol_Tab] = ImVec4(0.25f, 0.35f, 0.60f, 1.00f); // Голубой для вкладки
    colors[ImGuiCol_TabHovered] = ImVec4(0.30f, 0.40f, 0.70f, 1.00f); // Светло-голубой при наведении
    colors[ImGuiCol_TabActive] = ImVec4(0.35f, 0.45f, 0.80f, 1.00f); // Ещё светлее при активном состоянии
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.25f, 0.35f, 0.60f, 1.00f); // Такой же как обычная вкладка
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.35f, 0.45f, 0.80f, 1.00f); // Такой же как активная вкладка
    //colors[ImGuiCol_DockingPreview] = ImVec4(0.20f, 0.60f, 0.85f, 0.70f); // Неизмененный
    //colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.10f, 0.10f, 0.30f, 1.00f); // Неизмененный
    colors[ImGuiCol_PlotLines] = ImVec4(0.50f, 0.60f, 0.90f, 1.00f); // Голубой для графиков
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.20f, 0.60f, 0.85f,1.00f); // Ярко-голубой при наведении
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.35f, 0.75f, 1.00f, 1.00f); // Голубой для гистограмм
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.20f, 0.60f, 0.85f, 1.00f); // Ярко-голубой при наведении
    colors[ImGuiCol_TableHeaderBg] = ImVec4(0.15f, 0.25f, 0.55f, 1.00f); // Темно-голубой для заголовка таблицы
    colors[ImGuiCol_TableBorderStrong] = ImVec4(0.25f, 0.40f, 0.70f, 1.00f); // Голубой для границы таблицы
    colors[ImGuiCol_TableBorderLight] = ImVec4(0.20f, 0.35f, 0.65f, 1.00f); // Светло-голубой для границы таблицы
    colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f); // Прозрачный
    colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.20f, 0.60f, 0.85f, 0.06f); // Полупрозрачный ярко-голубой
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.60f, 0.85f, 0.35f); // Полупрозрачный ярко-голубой для выделенного текста
    colors[ImGuiCol_DragDropTarget] = ImVec4(0.20f, 0.60f, 0.85f, 0.95f); // Насыщенный ярко-голубой для цели перетаскивания
    colors[ImGuiCol_NavHighlight] = ImVec4(0.20f, 0.60f, 0.85f, 1.00f); // Ярко-голубой для навигации
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.20f, 0.60f, 0.85f, 1.00f); // Ярко-голубой для навигации по окнам
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f); // Полупрозрачный серый для затенения фона
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.10f, 0.10f, 0.30f, 0.35f); // Полупрозрачный темно-синий для модальных окон

    // Style
    style.WindowRounding = 5.3f;
    style.FrameRounding = 2.3f;
    style.ScrollbarRounding = 0;
    style.GrabRounding = 2.3f;
    style.TabRounding = 2.3f;

    style.WindowMinSize = windowSize;
    style.ChildRounding = 5.0f;
}

void Menu::PreventMoveOutOfWndBounds(const char* wndName) {
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

void Menu::Render()
{
    static Headers tab{ PLAYER };
    const char* tab_name = tab == PLAYER ? "Player" 
        : tab == ESP ? "ESP" 
        : tab == MISC ? "MISC" 
        : tab == CONFIG ? "CONFIG" 
        : tab == DEBUG ? "DEBUG" 
        : 0;


    if (ImGui::Begin("Moonlight", nullptr, /*ImGuiWindowFlags_NoDecoration |*/ ImGuiWindowFlags_NoTitleBar))
    {
        ImVec2 pos = ImGui::GetWindowPos();
        ImVec2 size = ImGui::GetWindowSize();

        ImVec2 wndSize = ImGui::GetWindowSize();

        ImGuiStyle style = ImGui::GetStyle();
        ImDrawList* draw = ImGui::GetWindowDrawList();

        // Определение минимальных размеров для MainLeft
        float minWidth = 120;

        // Ограничение размеров для MainLeft
        ImVec2 mainLeftSize = ImVec2(ImGui::GetContentRegionAvail().x * 0.16f, ImGui::GetContentRegionAvail().y);
        mainLeftSize.x = ImClamp(mainLeftSize.x, minWidth, wndSize.x);

        // Левое основное окно
        ImGui::BeginChild("MainLeft", mainLeftSize, 0);
        {

            ImVec2 leftTopChildSize = ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y * 0.16f);
            ImGui::BeginChild("LeftSide1", leftTopChildSize, false);

            ImGui::PushFont(title);

            ImVec2 textSize = ImGui::CalcTextSize(ProjectName);

            float posX = (leftTopChildSize.x - textSize.x) * 0.5f;
            float posY = (leftTopChildSize.y - textSize.y) * 0.5f;

            ImGui::SetCursorPos(ImVec2(posX, posY));

            ImGui::TextColored(ImColor(84, 160, 227), ProjectName);

            ImGui::PopFont();
            ImGui::EndChild();


            if (ImGui::BeginChild("LeftSide2", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), 0))
            {
                for (unsigned int i = 0; i < Buttons.size(); ++i) 
                {
                    bool selected = (page == i);
                    auto windowvars = ImGuiStyleVar_SelectableTextAlign;

                    ImGui::PushStyleVar(windowvars, ImVec2(0.5f, 0.5f));

                    if (ImGui::Selectable(Buttons[i].btnLable, &selected, 0, ImVec2(ImGui::GetContentRegionAvail().x, 24)))
                        page = i;

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
    switch (page) 
    {
        case 0: // Player
            god.DrawMenuItems();
            speedhack.DrawMenuItems();
            fly.DrawMenuItems();
            gravityScale.DrawMenuItems();
            walkFloorZ.DrawMenuItems();
            walkFloorAngle.DrawMenuItems();

            break;

        case 1: // Esp
            ImGui::Text("in dev.");
            break;

        case 2: // Misc
            fpsUnlock.DrawMenuItems();
            if (ImGui::Button("Force exit"))
                ExitProcess(0);

            if (ImGui::Button("Success"))
                ImGui::InsertNotification({ ImGuiToastType::Success, 3000, "That is a success! %s", "(Format here)" });
            if (ImGui::Button("Warning"))
                ImGui::InsertNotification({ ImGuiToastType::Warning, 3000, "Hello World! This is a warning! %d", 0x1337 });
            //ImGui::InsertNotification({ ImGuiToastType::Error, 3000, "Hello World! This is an error! 0x%X", 0xDEADBEEF });
            //ImGui::InsertNotification({ ImGuiToastType::Info, 3000, "Hello World! This is an info!" });

            break;

        case 3: // Config 
            ImGui::Text("in dev.");
            break;

        case 4: // Debug
            ImGui::Text("Debug Page");
            DebugMenu::DebugMainPage();
            break;

    } // Switch
    ImGui::EndChild();
    ImGui::PopStyleVar();

    ImGui::End(); // Render end
}

void Menu::RenderWatermark()
{
    if (!this->bWatermark)
        return;


    auto time = std::chrono::system_clock::now();
    std::time_t formatedtime = std::chrono::system_clock::to_time_t(time);


    ImGui::SetNextWindowPos(ImVec2(15, 15));
    ImGui::SetNextWindowSize(ImVec2());

    ImGui::Begin("watermark", nullptr,
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoBackground |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoBackground |
        ImGuiWindowFlags_NoNavFocus |
        ImGuiWindowFlags_NoNav
    );

    ImGui::Text("By chadlrnsn | Moonlight | %s | %s", std::ctime(&formatedtime), BuildInfo);
    ImGui::End();
}

void Menu::RenderNotify()
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f); // Disable round borders
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f); // Disable borders

    // Notifications color setup
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.10f, 0.10f, 0.10f, 1.00f)); // Background color


    // Main rendering function
    ImGui::RenderNotifications();


    //——————————————————————————————— WARNING ———————————————————————————————
    // Argument MUST match the amount of ImGui::PushStyleVar() calls 
    ImGui::PopStyleVar(2);
    // Argument MUST match the amount of ImGui::PushStyleColor() calls 
    ImGui::PopStyleColor(1);
}
