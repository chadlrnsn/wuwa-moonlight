#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <nlohmann/json.hpp>
#include <Features/FeatureFactory.h>
#include <logger.h>

namespace fs = std::filesystem;

/**
 * @brief Configuration management class
 * 
 * This class provides functionality for saving and loading configurations
 * for all features based on FeatureFactory
 */
class ConfigManager {
private:
    std::string configDir;
    std::string currentConfig;
    std::mutex configMutex;
    
    // Private constructor for singleton
    ConfigManager() : 
        configDir("configs"),
        currentConfig("default") {
        // Create config directory if it doesn't exist
        try {
            if (!fs::exists(configDir)) {
                bool created = fs::create_directory(configDir);
                if (created) {
                    LOG_INFO("Config directory created: %s", configDir.c_str());
                } else {
                    LOG_ERROR("Failed to create config directory: %s", configDir.c_str());
                }
            } else {
                LOG_INFO("Config directory already exists: %s", configDir.c_str());
            }
            
            // Выводим текущую рабочую директорию для отладки
            LOG_INFO("Current working directory: %s", fs::current_path().string().c_str());
        } catch (const std::exception& e) {
            LOG_ERROR("Exception in ConfigManager constructor: %s", e.what());
        }
    }
    
    // Internal methods
    std::string GetConfigPath(const std::string& configName) const {
        // Use absolute path for reliability
        fs::path absolutePath = fs::absolute(configDir);
        fs::path configPath = absolutePath / (configName + ".json");
        LOG_INFO("Config path: %s", configPath.string().c_str());
        return configPath.string();
    }

public:
    // Singleton
    static ConfigManager& GetInstance() {
        static ConfigManager instance;
        return instance;
    }
    
    // Prohibit copying and assignment
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;
    
    /**
     * @brief Saves configuration of all features to a file
     * 
     * @param features Vector of feature pointers
     * @param configName Configuration name (optional)
     * @return true If saving was successful
     * @return false In case of error
     */
    bool SaveConfig(const std::vector<std::shared_ptr<IFeatureFactory>>& features, 
                    const std::string& configName = "") {
        std::lock_guard<std::mutex> lock(configMutex);
        
        std::string fileName = configName.empty() ? currentConfig : configName;
        if (!configName.empty()) {
            currentConfig = configName;
        }
        
        nlohmann::json config;
        config["version"] = 1.0;
        config["name"] = fileName;
        config["timestamp"] = std::time(nullptr);
        
        // Createing object instead feature array
        nlohmann::json featuresJson = nlohmann::json::object();
        
        for (const auto& feature : features) {
            if (!feature) continue;
            
            // Use feature as key, and data as value
            std::string featureType = feature->GetFeatureName();
            featuresJson[featureType] = feature->Serialize();
        }
        
        config["features"] = featuresJson;
        
        try {
            std::string configPath = GetConfigPath(fileName);
            std::ofstream configFile(configPath);
            if (!configFile.is_open()) {
                LOG_ERROR("Failed to open config file for writing: %s", configPath.c_str());
                return false;
            }
            
            configFile << std::setw(4) << config << std::endl;
            bool success = configFile.good();
            
            if (success) {
                LOG_INFO("Config saved successfully: %s", configPath.c_str());
            } else {
                LOG_ERROR("Failed to save config: %s", configPath.c_str());
            }
            
            return success;
        } catch (const std::exception& e) {
            LOG_ERROR("Exception in SaveConfig: %s", e.what());
            return false;
        }
    }
    
    /**
     * @brief Loads configuration for all features from a file
     * 
     * @param features Vector of feature pointers
     * @param configName Configuration name (optional)
     * @return true If loading was successful
     * @return false In case of error
     */
    bool LoadConfig(std::vector<std::shared_ptr<IFeatureFactory>>& features, 
                   const std::string& configName = "") {
        std::lock_guard<std::mutex> lock(configMutex);
        
        std::string fileName = configName.empty() ? currentConfig : configName;
        if (!configName.empty()) {
            currentConfig = configName;
        }
        
        try {
            std::string configPath = GetConfigPath(fileName);
            if (!fs::exists(configPath)) {
                LOG_ERROR("Config file does not exist: %s", configPath.c_str());
                return false;
            }
            
            std::ifstream configFile(configPath);
            if (!configFile.is_open()) {
                LOG_ERROR("Failed to open config file for reading: %s", configPath.c_str());
                return false;
            }
            
            nlohmann::json config = nlohmann::json::parse(configFile);
            
            if (!config.contains("features") || !config["features"].is_object()) {
                LOG_ERROR("Invalid config format: %s", configPath.c_str());
                return false;
            }
            
            const auto& featuresJson = config["features"];
            
            for (auto& feature : features) {
                if (!feature) continue;
                
                std::string featureType = feature->GetFeatureName();
                
                // Check, if exist settings for this feature
                if (featuresJson.contains(featureType)) {
                    feature->Deserialize(featuresJson[featureType]);
                    LOG_INFO("Feature loaded: %s", featureType.c_str());
                } else {
                    LOG_WARN("Feature settings not found in config: %s", featureType.c_str());
                }
            }
            
            LOG_INFO("Config loaded successfully: %s", configPath.c_str());
            return true;
        } catch (const std::exception& e) {
            LOG_ERROR("Exception in LoadConfig: %s", e.what());
            return false;
        }
    }
    
    /**
     * @brief Get list of available configurations
     * 
     * @return std::vector<std::string> List of configuration names
     */
    std::vector<std::string> GetAvailableConfigs() {
        std::lock_guard<std::mutex> lock(configMutex);
        std::vector<std::string> configs;
        
        try {
            if (!fs::exists(configDir)) {
                LOG_ERROR("Config directory does not exist: %s", configDir.c_str());
                fs::create_directory(configDir);
                return configs;
            }
            
            // Перечисляем все файлы в директории
            for (const auto& entry : fs::directory_iterator(configDir)) {
                if (entry.is_regular_file() && entry.path().extension() == ".json") {
                    std::string configName = entry.path().stem().string();
                    configs.push_back(configName);
                    // LOG_INFO("Found config: %s", configName.c_str());
                }
            }
            
            // LOG_INFO("Found %d configs", (int)configs.size());
        } catch (const std::exception& e) {
            LOG_ERROR("Exception in GetAvailableConfigs: %s", e.what());
        }
        
        return configs;
    }
    
    /**
     * @brief Delete configuration
     * 
     * @param configName Configuration name
     * @return true If deletion was successful
     * @return false In case of error
     */
    bool DeleteConfig(const std::string& configName) {
        if (configName.empty()) return false;
        
        std::lock_guard<std::mutex> lock(configMutex);
        try {
            std::string filePath = GetConfigPath(configName);
            if (fs::exists(filePath)) {
                bool success = fs::remove(filePath);
                if (success) {
                    LOG_INFO("Config deleted: %s", filePath.c_str());
                    if (currentConfig == configName) {
                        currentConfig = "default";
                    }
                    return true;
                } else {
                    LOG_ERROR("Failed to delete config: %s", filePath.c_str());
                }
            } else {
                LOG_ERROR("Config file does not exist: %s", filePath.c_str());
            }
        } catch (const std::exception& e) {
            LOG_ERROR("Exception in DeleteConfig: %s", e.what());
        }
        
        return false;
    }
    
    /**
     * @brief Get current configuration name
     * 
     * @return std::string Current configuration name
     */
    std::string GetCurrentConfig() const {
        return currentConfig;
    }
    
    /**
     * @brief Set current configuration
     * 
     * @param configName Configuration name
     */
    void SetCurrentConfig(const std::string& configName) {
        if (!configName.empty()) {
            currentConfig = configName;
        }
    }
}; 