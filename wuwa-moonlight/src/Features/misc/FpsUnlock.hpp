#pragma once
#include <includes.h>
#include <globals.h>

using namespace globals;

class FpsUnlock : public FeatureFactory
{
private:
	structs::MinMax <float>FpsData = {0,1000,144};
	float fFrameRateLimitDefault = 60.0f;
	char fpsText[32];
	bool bUnlimited{ true };
	bool bShowFps{ true };

public:
	FpsUnlock() : FeatureFactory("FpsUnlock") {}
	
	void Render();
	void Draw();
	void Run();
	
	// Сериализация настроек в JSON
	nlohmann::json Serialize() const override {
	    nlohmann::json j = FeatureFactory::Serialize();
	    
	    // Сохраняем настройки FPS
	    j["unlimited"] = bUnlimited;
	    j["show_fps"] = bShowFps;
	    j["fps_data"] = {
	        {"min", FpsData.Min},
	        {"max", FpsData.Max},
	        {"current", FpsData.Current}
	    };
	    j["frame_rate_limit_default"] = fFrameRateLimitDefault;
	    
	    return j;
	}
	
	// Десериализация настроек из JSON
	void Deserialize(const nlohmann::json& json) override {
	    FeatureFactory::Deserialize(json);
	    
	    // Загружаем настройки FPS
	    if (json.contains("unlimited"))
	        bUnlimited = json["unlimited"].get<bool>();
	        
	    if (json.contains("show_fps"))
	        bShowFps = json["show_fps"].get<bool>();
	    
	    // Загружаем данные FPS
	    if (json.contains("fps_data")) {
	        auto& fps = json["fps_data"];
	        if (fps.contains("min")) FpsData.Min = fps["min"].get<float>();
	        if (fps.contains("max")) FpsData.Max = fps["max"].get<float>();
	        if (fps.contains("current")) FpsData.Current = fps["current"].get<float>();
	    }
	    
	    if (json.contains("frame_rate_limit_default"))
	        fFrameRateLimitDefault = json["frame_rate_limit_default"].get<float>();
	}
};