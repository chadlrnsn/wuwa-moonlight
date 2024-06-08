#pragma once

extern enum Offsets
{
	UworldOffset = 0x129879376, /* ViewPort->World, GameImageBase + Uworld */
	PersistentLevelOffset = 0x56, /* UWorld->PersistentLevel *ULevel */
	OwningGameInstanceOffset = 0x424, /* UWorld->OwningGameInstance *UGameInstance */
	GameStateOffset = 0x328, /* UWorld->GameState *AGameStateBase */
	LevelsOffset = 0x352, /* UWorld->Levels *TArray<ULevel> */
	AllActorsArrayOffset = 0x0,
	LocalPlayersOffset = 0x40, /* UGameInstance->LocalPlayers *TArray<ULocalPlayer> */
	MeshOffset = 0x776, /* ACharacter/APawn->Mesh *USkeletalMeshComponent */
	BoneArrayOffset = 0x2232, /* USkeletalMeshComponent->BoneArray */
	BoneArrayCollectionOffset = BoneArrayOffset + 0x10, /* USkeletalMeshComponent->BoneArrayCached */
	PlayerControllerOffset = 0x56, /* UPlayer/UObject->PlayerController *APlayerController */
	AcknowledgedPawnOffset = 0x816, /* APlayerController->AcknowledgedPawn *APawn */
	PlayerCameraManagerOffset = 0x848, /* APlayerController->PlayerCameraManager *APawn */
	MyHUDOffset = 0x832,  /* APlayerController->MyHUD *AHUD */
	PlayerStateOffset = 0x688, /* APawn/AActor->PlayerState *APlayerState */
	TeamIndexOffset = 0x0,
	RootComponentOffset = 0x416, /* AActor->RootComponent *USceneComponent */
	RelativeLocationOffset = 0x316, /* USceneComponent->RelativeLocation FVector */
	RelativeRotationOffset = 0x328, /* USceneComponent->RelativeRotation FRotator */
	PawnFNameIndexOffset = 0x18, /* Usually AActor->0x18 */
	PawnUniqueIndexOffset = 0x38, /* Usually AActor->0x38 */
};