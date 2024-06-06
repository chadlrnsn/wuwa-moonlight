#pragma once
#pragma once

namespace UnrealStructs
{
	struct FVector
	{
		/*https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FVector/*/
		float X;
		float Y;
		float Z;
	};

	struct FMinimalViewInfo {
		FVector Location;
		FVector Rotation;
		float FOV;
	};

	struct FCameraCacheEntry {
		float Timestamp;
		char pad;
		struct FMinimalViewInfo POV;
	};
}