#include "Debug_menu.h"

#include <SDK.hpp>
#include <globals.h>
#include "Features.h"
#include <SDKTools/SDKTools.hpp>

using namespace SDK;

float fDefaultFOV = 90;
float fDefaultFOVOverride = 90;
bool bChangeFOV = false;

bool bChangeWorldTimeDilation = false;
float fWorldSpeed = 1;
float fCustomWorldSpeed = 1;

bool bFpsUnlock = false;

void DebugMenu::DebugMainPage()
{

	UEngine* Engine = UEngine::GetEngine();
	UWorld* World = UWorld::GetWorld();
	
	if (!SDKTools::Player::IsPlayerLoaded(World) || !SDKTools::World::IsPersistentLevelLoaded(World))
		return;

	ULocalPlayer* LocalPlayer = World->OwningGameInstance->LocalPlayers[0];
	APlayerController* PlayerController = LocalPlayer->PlayerController;
	APawn* AcknowledgedPawn = PlayerController->AcknowledgedPawn;



	ImGui::Text("Build %s", &BuildInfo);
	ImGui::Text("GWorld -> 0x%d", &World);
	ImGui::Text("GEngine -> 0x%d", &Engine);
	ImGui::Text("LocalPlayer -> 0x%d", &LocalPlayer);
	ImGui::Text("APlayerController -> 0x%d", &PlayerController);
	ImGui::Text("APawn -> 0x%d", &AcknowledgedPawn);

	static bool bAlwaysSunny = false;
	ImGui::Checkbox("Always sunny not implemented yet", &bAlwaysSunny);
	if (bAlwaysSunny) {}

	FVector pos = AcknowledgedPawn->K2_GetActorLocation();
	ImGui::InputFloat("X", &pos.X);
	ImGui::InputFloat("Y", &pos.Y);
	ImGui::InputFloat("Z", &pos.Z);

	
	ImGui::SeparatorText("CharacterMovement");
	UCharacterMovementComponent* CharacterMovement = PlayerController->Character->CharacterMovement;
	ImGui::BeginGroup();
	{
		ImGui::InputFloat("AirControl", &CharacterMovement->AirControl);

		FVector vel = CharacterMovement->Velocity;
		ImGui::Text("Velocity");
		ImGui::InputFloat("VX", &CharacterMovement->Velocity.X);
		ImGui::InputFloat("VY", &CharacterMovement->Velocity.Y);
		ImGui::InputFloat("VZ", &CharacterMovement->Velocity.Z);

	}
	ImGui::EndGroup();


	static bool bEsp = false;
	static struct FESP
	{
		float Distance;
		float Min;
		float Max;
	};

	FESP esp;
	esp.Distance = 10000;
	esp.Min = 1;
	esp.Max = 100000;

	static struct ActorInfo
	{
		const char* Name;
		std::string ClassName;
		FVector Position;
		FString HP;
	};

	ImGui::Checkbox("ESP", &bEsp);
	if (bEsp)
	{
		ImGui::Text("Im not done ESP yet");
		ImGui::SliderFloat("Render Distance", &esp.Distance, esp.Min, esp.Max);
		
		ULevel* Level = World->PersistentLevel;
		if (Level)
		{
			// Создаем массив для хранения объектов
			TArray<AActor*> FoundActors;

			// Получаем список всех объектов заданного типа на уровне
			
			UGameplayStatics::GetAllActorsOfClass(World, AActor::StaticClass(), &FoundActors);

			// Вывести имена всех найденных объектов
			for (AActor* Actor : FoundActors)
			{
				if (Actor)
				{
					ActorInfo Info;
					Info.Name = Actor->GetName().c_str();
					Info.ClassName = Actor->Class->GetName();
					Info.Position = Actor->K2_GetActorLocation();

					if (ImGui::Selectable(Info.Name, false))
					{
						
					}
					// Попытка получить здоровье, если объект поддерживает интерфейс здоровья
					//if (Actor->Implements<UHealthInterface>())
					//{
					//	IHealthInterface* HealthInterface = Cast<IHealthInterface>(Actor);
					//	if (HealthInterface)
					//	{
					//		Info.HP = HealthInterface->GetHealth();
					//	}
					//}
					//else
					//{
					//	Info.HP = -1.0f; // Указать, что HP недоступно
					//}

				}
			}
		}
	}
}
