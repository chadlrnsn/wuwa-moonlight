#pragma once
#pragma once
#include "Utils.hpp"
#include "Structs.hpp"
#include "Classes.hpp"
#include "Offsets.hpp"

using namespace Utilities::DummyFunctions;
using namespace UnrealStructs;
using namespace UC;

namespace UnrealEngine
{
	namespace Variables {
		uintptr_t UWorld, PersistentLevel, OwningGameInstance, LocalPlayer, PlayerController, AcknowledgedPawn, PlayerCameraManager, MyHUD;
	}

	namespace SDK
	{
		typedef struct __Game {
			auto GetWorld(uintptr_t ImageBase) -> uintptr_t {
				return Read<uintptr_t>(ImageBase + Offsets::UworldOffset);
			};
		} _Game, * Game;

		typedef struct __UWorld : UObject {
			auto PersistentLevel() -> uintptr_t {
				return Read<uintptr_t>(Variables::UWorld + Offsets::PersistentLevelOffset);
			};

			auto OwningGameInstance() -> uintptr_t {
				return Read<uintptr_t>(Variables::UWorld + Offsets::OwningGameInstanceOffset);
			};

			auto GameState() -> uintptr_t {
				return Read<uintptr_t>(Variables::UWorld + Offsets::GameStateOffset);
			};
		} _UWorld, * UWorld;

		typedef struct __ULevel : UObject {
			auto AActorArray() -> TArray<uintptr_t> {
				return Read<TArray<uintptr_t>>(Variables::PersistentLevel + Offsets::AllActorsArrayOffset);
			};
		} _ULevel, * ULevel;

		typedef struct __UGameInstance : UObject {
			auto LocalPlayer() -> uintptr_t {
				auto LocalPlayers = Read<uintptr_t>(Variables::OwningGameInstance + Offsets::LocalPlayersOffset);
				return Read<uintptr_t>(LocalPlayers); /* LocalPlayerArray[0] */
			};
		} _UGameInstance, * UGameInstance;

		typedef struct __UPlayer : UObject {
			auto PlayerController() -> uintptr_t {
				return Read<uintptr_t>(Variables::LocalPlayer + Offsets::PlayerControllerOffset);
			};
		} _UPlayer, * UPlayer;

		typedef struct __APlayerController : AController {
			auto PlayerCameraManager() -> uintptr_t {
				return Read<uintptr_t>(Variables::PlayerController + Offsets::PlayerCameraManagerOffset);
			};
			auto MyHUD() -> uintptr_t {
				return Read<uintptr_t>(Variables::PlayerController + Offsets::MyHUDOffset);
			};
			auto AcknowledgedPawn() -> uintptr_t {
				return Read<uintptr_t>(Variables::PlayerController + Offsets::AcknowledgedPawnOffset);
			};
		} _APlayerController, * APlayerController;

		typedef struct __APlayerCameraManager : AActor {
			auto CameraLocation() -> FVector {
				//PlayerCameraManager->CameraCachePrivate->POV->Location
				FVector Dummy = { 0, 0, 0 };
				return Dummy;
			}
			auto CameraRotation() -> FVector {
				//PlayerCameraManager->CameraCachePrivate->POV->Rotation
				FVector Dummy = { 0, 0, 0 };
				return Dummy;
			}
			auto CameraFOV() -> float {
				//PlayerCameraManager->CameraCachePrivate->POV->FOV
				return 0;
			}
		} _APlayerCameraManager, * APlayerCameraManager;

		typedef struct __USkeletalMeshComponent : USkinnedMeshComponent {
			auto BoneArray(uintptr_t Mesh) -> uintptr_t {
				auto BoneTmp = Read<uintptr_t>(Mesh + Offsets::BoneArrayOffset);
				if (BoneTmp == NULL)
				{
					BoneTmp = Read<uintptr_t>(Mesh + Offsets::BoneArrayCollectionOffset);
				}
				return BoneTmp;
			};
		} _USkeletalMeshComponent, * USkeletalMeshComponent;

		typedef struct __APawn : AActor {
			auto Mesh(uintptr_t Pawn) -> uintptr_t {
				return Read<uintptr_t>(Pawn + Offsets::MeshOffset);
			};

			auto TeamID(uintptr_t Pawn) -> int {
				auto PlayerState = Read<uintptr_t>(Pawn + Offsets::PlayerStateOffset);
				return Read<int>(PlayerState + Offsets::TeamIndexOffset); /* To Be Noted : Mostly differs depending on the game */
			};

			auto RelativeLocation(uintptr_t Pawn) -> FVector {
				auto RootComponent = Read<uintptr_t>(Pawn + Offsets::RootComponentOffset);
				return Read<FVector>(RootComponent + Offsets::RelativeLocationOffset);
			};

			auto RelativeRotation(uintptr_t Pawn) -> FVector {
				auto RootComponent = Read<uintptr_t>(Pawn + Offsets::RootComponentOffset);
				return Read<FVector>(RootComponent + Offsets::RelativeRotationOffset);
			};

			auto UniqueID(uintptr_t Pawn) -> int {
				return Read<int>(Pawn + Offsets::PawnUniqueIndexOffset);
			};

			auto FNameID(uintptr_t Pawn) -> int {
				return Read<int>(Pawn + Offsets::PawnFNameIndexOffset);
			};
		} _APawn, * APawn;
	}
}