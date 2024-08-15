#include "Feature.h"

class WalkableFloorZ : Feature
{
private:
	bool Initalized = false;

public:
	bool bEnable = false;
	float fMaxZ = 2000.0f;
	float fMinZ = -2000.0f;
	float fZ = 0.574f;

private:

public:
	WalkableFloorZ() {};

	bool Setup() override
	{
		Initalized = true;

		return Initalized;
	};

	void Destroy() override
	{
		Initalized = false;
	}

	void HandleKeys() override {}

	void DrawMenuItems() override;

	void Render(void** args, size_t numArgs) override {}

	void Run(void** args, size_t numArgs) override;
};


inline void WalkableFloorZ::DrawMenuItems()
{
	ImGui::Checkbox("WalkableFloorZ", &bEnable);
	if (bEnable) {
		ImGui::Text("WalkableFloorZ");
		ImGui::SliderFloat("##WalkableFloorZ", &fZ, fMinZ, fMaxZ);
	}
}

inline void WalkableFloorZ::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		Destroy();
		return;
	}

	SDK::APawn* AcknowledgedPawn = (SDK::APawn*)args[0];
	SDK::UPawnMovementComponent* PawnMovement = AcknowledgedPawn->GetMovementComponent();
	SDK::UCharacterMovementComponent* Movement = static_cast<SDK::UCharacterMovementComponent*>(PawnMovement);

	if (bEnable && Movement)
	{
		Movement->WalkableFloorZ = fZ;
	}

	if (!bEnable && Movement)
	{
		Movement->WalkableFloorZ = 0.574f;
	}
}

inline WalkableFloorZ walkFloorZ;