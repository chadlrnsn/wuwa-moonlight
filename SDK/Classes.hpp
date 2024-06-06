#pragma once
#include <cstdint>
#include <string>
#include <locale>

namespace UC {
	/* Inheritance Hierarchy */
	class UObjectBase {};
	class UObjectBaseUtility : UObjectBase {};
	class UObject : UObjectBaseUtility {};
	class AActor : UObject {};
	class AController : AActor {};
	class UActorComponent : UObject {};
	class USceneComponent : UActorComponent {};
	class UPrimitiveComponent : USceneComponent {};
	class UMeshComponent : UPrimitiveComponent {};
	class USkinnedMeshComponent : UMeshComponent {};

	template<class T>
	class TArray {

		friend struct FString;

		/*https://docs.unrealengine.com/5.0/en-US/API/Runtime/Core/Containers/TArray/*/
	public:
		TArray() {
			Data = NULL;
			Count = 0;
			Max = 0;
		};

		T operator[](uint64_t i) const {
			return Utilities::DummyFunctions::Read<uintptr_t>(((uintptr_t)Data) + i * sizeof(T));
		};

		T* Data;
		unsigned int Count;
		unsigned int Max;
	};

	struct FString : private TArray<wchar_t>
	{
		FString() {};

		FString(const wchar_t* str)
		{
			Max = Count = *str ? std::wcslen(str) + 1 : 0;

			if (Count)
			{
				Data = const_cast<wchar_t*>(str);
			}
		}

		bool IsValid() const
		{
			return Data != nullptr;
		}

		const wchar_t* c_str() const
		{
			return Data;
		}

		std::string ToString() const
		{
			auto length = std::wcslen(Data);

			std::string str(length, '\0');

			std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

			return str;
		}

	};

}