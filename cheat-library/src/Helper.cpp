#include "Helper.h"


namespace Helper {

	bool ContainsSubstring(const std::string& str, const std::string& sub)
	{
		auto it = std::search(
			str.begin(), str.end(),
			sub.begin(), sub.end(),
			[](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
		);
		return (it != str.end());
	}

	void devlog(const char* fmt, ...)
	{
#ifdef _DEBUG
		va_list args;
		char buf[1024];
		va_start(args, fmt);
		vsnprintf(buf, sizeof(buf), fmt, args);
		va_end(args);
		std::cout << buf;
#endif
	}

	bool IsFullyLoaded(SDK::UWorld* World) noexcept {
		if (!World) return false;

		SDK::UGameInstance* gInstance = World->OwningGameInstance;
		if (!gInstance) return false;
		GameInstance = gInstance;

		SDK::ULocalPlayer* localPlayer = gInstance->LocalPlayers[0];
		if (!localPlayer) return false;
		LocalPlayer = localPlayer;


		SDK::APlayerController* playerController = localPlayer->PlayerController;
		if (!playerController) return false;
		PlayerController = playerController;

		SDK::APawn* acknowledgedPawn = playerController->AcknowledgedPawn;
		if (!acknowledgedPawn) return false;
		AcknowledgedPawn = acknowledgedPawn;

		return true;
	}


	void UE_RenderText(
		UCanvas* canvas,
		UFont* font,
		FString text,
		FVector2D Position,
		FVector2D Scale,
		FLinearColor color
	)
	{
		canvas->K2_DrawText(
			font,
			text,
			Position,
			Scale, // text offset
			color, // Text color
			false,
			FLinearColor(0, 0, 0, 1), // Shadow color
			FVector2D(0, 0), // Shadow offset
			false,
			false,
			false,
			FLinearColor(0, 0, 0, 1)
		);
	}

	void UE_RenderTextEx(
		UCanvas* canvas,
		UFont* font,
		FString text,
		FVector2D Position,
		FVector2D Scale,
		FLinearColor color,
		bool centeredX,
		bool centeredY,
		bool outline,
		FLinearColor outlineColor
	)
	{
		canvas->K2_DrawText(
			font,
			text,
			Position,
			Scale, // text offset
			color, // Text color
			false,
			FLinearColor(0, 0, 0, 1), // Shadow color
			FVector2D(0, 0), // Shadow offset
			centeredX,
			centeredY,
			outline,
			outlineColor
		);
	}
}