#pragma once
#include <SDK.hpp>
#include <globals.h>

using namespace SDK;


namespace Helper {

	bool ContainsSubstring(const std::string& str, const std::string& sub);

	void UpdateGlobals() noexcept;
	bool IsGameExploitable();

	bool IsAddressReadable(const void* ptr, size_t size);

	template<typename T>
	bool IsPointerReadable(const T* ptr) {
		return IsAddressReadable(ptr, sizeof(T));
	}

}


namespace ue4 {
	void UE_RenderText(
		UCanvas* canvas,
		UFont* font,
		FString text,
		FVector2D Position = { 0, 0 },
		FVector2D Scale = { 1, 1 },
		FLinearColor color = { 1, 1, 1, 1 }
	);

	void UE_RenderTextEx(
		UCanvas* canvas,
		UFont* font,
		FString text,
		FVector2D Position = { 0, 0 },
		FVector2D Scale = { 1, 1 },
		FLinearColor color = { 1, 1, 1, 1 },
		bool centeredX = false,
		bool centeredY = false,
		bool outline = false,
		FLinearColor outlineColor = { 0, 0, 0, 1 }
	);
}