#pragma once
#include <includes.h>
#include <Features/Bindings.h>
#include <globals.h>
#include <magic_enum.hpp>
using namespace globals;

class Fly : public FeatureFactory
{
private:
	struct KeyDataToggleData {
		KeyBindToggle kb = KeyBindToggle(KeyBind::KeyCode::V);
		bool bSettingKey = false;
		bool bUpKey = false;
		bool bDownKey = false;
	};

	structs::MinMax <float>normalSpeed = {
		1000.0f,
		9999.0f,
		3000.0f
	};

	structs::MinMax <float>altSpeed = {
		1000.0f,
		9999.0f,
		5000.0f
	};

	structs::MinMax <float>speedVectical = { 700, 0.1, 1000 };
	KeyDataToggleData KeyDataToggleData;
	bool m_bEnableCollision { false };
	bool m_bTestDirect { false };
	bool m_bCheatManagerAvailable { false };
	bool m_bMovementModeChangeable { false };
	bool m_bUseGravityOverride { false };
	bool m_bUseVelocityOverride { false };
	bool m_bUseNavMeshOverride { false };
	float m_fOriginalGravityScale { 1.0f };

	bool ValidatePtr();
public:
	Fly() : FeatureFactory("Fly") {}

	void HandleKeys()
	{
		if (GetAsyncKeyState(KeyDataToggleData.kb.toInt()) & 0x1) bEnable = !bEnable;
	}

	void Draw();
	void Run();
	void HandleFlightControls();
	
	nlohmann::json Serialize() const override {
		nlohmann::json j = FeatureFactory::Serialize();
		
		// j["key_bind"] = static_cast<int>(KeyDataToggleData.kb.keyCode);
		
		j["normal_speed"] = {
			{"min", normalSpeed.Min},
			{"max", normalSpeed.Max},
			{"current", normalSpeed.Current}
		};
		
		j["alt_speed"] = {
			{"min", altSpeed.Min},
			{"max", altSpeed.Max},
			{"current", altSpeed.Current}
		};
		
		j["vertical_speed"] = {
			{"min", speedVectical.Min},
			{"max", speedVectical.Max},
			{"current", speedVectical.Current}
		};
		
		j["enable_collision"] = m_bEnableCollision;
		j["test_direct"] = m_bTestDirect;
		j["use_gravity_override"] = m_bUseGravityOverride;
		j["use_velocity_override"] = m_bUseVelocityOverride;
		j["use_nav_mesh_override"] = m_bUseNavMeshOverride;
		j["original_gravity_scale"] = m_fOriginalGravityScale;
		
		return j;
	}
	
	void Deserialize(const nlohmann::json& json) override {
		FeatureFactory::Deserialize(json);
		
		if (json.contains("key_bind")) {
			int keyCode = json["key_bind"].get<int>();
			KeyDataToggleData.kb = KeyBindToggle(static_cast<KeyBind::KeyCode>(keyCode));
		}
		
		if (json.contains("normal_speed")) {
			auto& speed = json["normal_speed"];
			if (speed.contains("min")) normalSpeed.Min = speed["min"].get<float>();
			if (speed.contains("max")) normalSpeed.Max = speed["max"].get<float>();
			if (speed.contains("current")) normalSpeed.Current = speed["current"].get<float>();
		}
		
		if (json.contains("alt_speed")) {
			auto& speed = json["alt_speed"];
			if (speed.contains("min")) altSpeed.Min = speed["min"].get<float>();
			if (speed.contains("max")) altSpeed.Max = speed["max"].get<float>();
			if (speed.contains("current")) altSpeed.Current = speed["current"].get<float>();
		}
		
		if (json.contains("vertical_speed")) {
			auto& speed = json["vertical_speed"];
			if (speed.contains("min")) speedVectical.Min = speed["min"].get<float>();
			if (speed.contains("max")) speedVectical.Max = speed["max"].get<float>();
			if (speed.contains("current")) speedVectical.Current = speed["current"].get<float>();
		}
		
		if (json.contains("enable_collision")) m_bEnableCollision = json["enable_collision"].get<bool>();
		if (json.contains("test_direct")) m_bTestDirect = json["test_direct"].get<bool>();
		if (json.contains("use_gravity_override")) m_bUseGravityOverride = json["use_gravity_override"].get<bool>();
		if (json.contains("use_velocity_override")) m_bUseVelocityOverride = json["use_velocity_override"].get<bool>();
		if (json.contains("use_nav_mesh_override")) m_bUseNavMeshOverride = json["use_nav_mesh_override"].get<bool>();
		if (json.contains("original_gravity_scale")) m_fOriginalGravityScale = json["original_gravity_scale"].get<float>();
	}
};

