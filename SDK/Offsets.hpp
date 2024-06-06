#pragma once
#pragma once

extern enum Offsets
{
	UworldOffset = 0x129879376, /* ViewPort->World, GameImageBase + Uworld */
	PersistentLevelOffset = 0x38, /* UWorld->PersistentLevel *ULevel */
	OwningGameInstanceOffset = 0x424, /* UWorld->OwningGameInstance *UGameInstance */
	GameStateOffset = 0x148, /* UWorld->GameState *AGameStateBase */
	LevelsOffset = 0x160, /* UWorld->Levels *TArray<ULevel> */
	AllActorsArrayOffset = 0x0,
	LocalPlayersOffset = 0x40, /* UGameInstance->LocalPlayers *TArray<ULocalPlayer> */
	MeshOffset = 0x308, /* ACharacter/APawn->Mesh *USkeletalMeshComponent */
	BoneArrayOffset = 0x40, /* USkeletalMeshComponent->BoneArray */
	BoneArrayCollectionOffset = BoneArrayOffset + 0x10, /* USkeletalMeshComponent->BoneArrayCached */
	PlayerControllerOffset = 0x38, /* UPlayer/UObject->PlayerController *APlayerController */
	AcknowledgedPawnOffset = 0x330, /* APlayerController->AcknowledgedPawn *APawn */
	PlayerCameraManagerOffset = 0x350, /* APlayerController->PlayerCameraManager *APawn */
	MyHUDOffset = 0x340,  /* APlayerController->MyHUD *AHUD */
	PlayerStateOffset = 0x688, /* APawn/AActor->PlayerState *APlayerState */
	TeamIndexOffset = 0x0,
	RootComponentOffset = 0x416, /* AActor->RootComponent *USceneComponent */
	RelativeLocationOffset = 0x0, /* USceneComponent->RelativeLocation FVector */
	RelativeRotationOffset = 0x0, /* USceneComponent->RelativeRotation FRotator */
	PawnFNameIndexOffset = 0x0, /* Usually AActor->0x18 */
	PawnUniqueIndexOffset = 0x0, /* Usually AActor->0x38 */
};