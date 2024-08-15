#include "Feature.h"

class GravityScale : Feature
{
private:
	bool Initalized = false;

public:
	bool bEnable = false;
	float fMaxGravity = 2.0f;
	float fMinGravity = -2.0f;
	float fGravity = 1.0f;

private:
	bool bOnce = false;

public:
	GravityScale() {};

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


inline void GravityScale::DrawMenuItems()
{
	ImGui::Checkbox("Gravity Scale", &bEnable);
	if (bEnable) {
		ImGui::Text("Gravity Multiplier");
		ImGui::SliderFloat("##Gravity Multiplier", &fGravity, fMinGravity, fMaxGravity);
	}
}

inline void GravityScale::Run(void** args, size_t numArgs)
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
		Movement->GravityScale = fGravity;
		bOnce = false;
	}

	if (!bEnable && Movement && !bOnce)
	{
		Movement->GravityScale = 1.0f; // may be 2 its defautlt not mine function btw
		bOnce = true;
	}
}

inline GravityScale gravityScale;