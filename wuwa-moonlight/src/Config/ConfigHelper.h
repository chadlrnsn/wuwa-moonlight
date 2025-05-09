#pragma once
#include <Config/ConfigManager.h>
#include <Features/Features.h>
#include <vector>
#include <memory>
#include <logger.h>

/**
 * @brief Class-helper for work with configs
 */
class ConfigHelper {
public:
    /**
     * @brief Initializes configurations by loading the last used one
     * 
     * This function should be called when starting the application
     */
    static void Initialize() {
        auto& configManager = ConfigManager::GetInstance();
        
        // Get all available features
        std::vector<std::shared_ptr<IFeatureFactory>> features = GetAllFeatures();
        
        // Check if there are available configs
        auto configs = configManager.GetAvailableConfigs();
        if (configs.empty()) {
            LOG_INFO("No configs found, creating default config");
            // Create test config
            CreateTestConfig();
        }
        
        // Load last configuration
        if (!configManager.LoadConfig(features)) {
            LOG_INFO("Failed to load config, saving current settings as default");
            // If loading failed - save current as default
            configManager.SaveConfig(features, "default");
        }
    }
    
    /**
     * @brief Creates a test config to verify system operation
     */
    static void CreateTestConfig() {
        auto& configManager = ConfigManager::GetInstance();
        auto features = GetAllFeatures();
        
        for (auto& feature : features) {
            nlohmann::json testData;
            testData["enabled"] = true;
            feature->Deserialize(testData);
        }
        
        // Сохраняем тестовый конфиг
        bool success = configManager.SaveConfig(features, "test_config");
        if (success) {
            LOG_INFO("Test config created successfully");
        } else {
            LOG_ERROR("Failed to create test config");
        }
    }
    
    /**
     * @brief Collects pointers to all features into a single list
     * 
     * @return std::vector<std::shared_ptr<IFeatureFactory>> List of all features
     */
    static std::vector<std::shared_ptr<IFeatureFactory>> GetAllFeatures() {
        std::vector<std::shared_ptr<IFeatureFactory>> features;
        
        features.push_back(fpsUnlock);
        features.push_back(esp);
        features.push_back(speedhack);
        features.push_back(multihit);
        features.push_back(fly);
        features.push_back(ptpsafe);
        features.push_back(debugComponent);
        
        return features;
    }
    
    /**
     * @brief Quick configuration save
     * 
     * @param configName Configuration name (optional)
     * @return true If saving was successful
     * @return false In case of error
     */
    static bool QuickSave(const std::string& configName = "") {
        auto& configManager = ConfigManager::GetInstance();
        return configManager.SaveConfig(GetAllFeatures(), configName);
    }
    
    /**
     * @brief Quick configuration load
     * 
     * @param configName Configuration name
     * @return true If loading was successful
     * @return false In case of error
     */
    static bool QuickLoad(const std::string& configName) {
        if (configName.empty()) return false;
        
        auto& configManager = ConfigManager::GetInstance();
        auto features = GetAllFeatures();
        return configManager.LoadConfig(features, configName);
    }
}; 