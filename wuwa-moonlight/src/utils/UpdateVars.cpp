#include "UpdateVars.h"
#include "globals.h"
#include <logger.h>

using namespace globals;
using namespace SDK;

void utils::UpdateGlobals() noexcept
{
    UEngine* _engine = UEngine::GetEngine();
    if (_engine == nullptr)
    {
        LOG_WARN("No engine");
        return;
    }
    engine = _engine;
    
    UWorld* _world = UWorld::GetWorld();
    if (_world == nullptr)
    {
        LOG_WARN("No world");
        return;
    }
    world = _world;

    if (!IsPointerReadable(&world->OwningGameInstance))
    {
        LOG_ERROR("Pointer on OwningGameInstance not readable!");
        return;
    }

    game_instance = world->OwningGameInstance;

    if (!game_instance)
    {
        LOG_WARN("no game_instance");
        return;
    }

    if (!IsPointerReadable(&game_instance->LocalPlayers))
    {
        LOG_ERROR("Pointer on LocalPlayer not readable!");
        return;
    }

    local_players = game_instance->LocalPlayers;

    if (!local_players)
    {
        LOG_WARN("no local_players");
        return;
    }

    uint32_t numPlayers = local_players.Num();
    if (numPlayers < 1)
    {
        LOG_WARN("LocalPlayers array is empty");
        return;
    }

    if (!local_players.IsValidIndex(0))
    {
        LOG_ERROR("LocalPlayer not valid at index 0");
        return;
    }

    if (!IsAddressReadable(&local_players[0], sizeof(TArray<ULocalPlayer*>)))
    {
        LOG_ERROR("Player array not readable!");
        return;
    }

    local_player = local_players[0];

    if (!local_player)
    {
        LOG_WARN("no self");
        return;
    }

    viewport = local_player->ViewportClient;

    if (!viewport)
    {
        LOG_ERROR("No ViewPort");
        return;
    }

    if (!IsPointerReadable(&local_player->PlayerController))
    {
        LOG_ERROR("Pointer on OwningGameInstance not readable!");
        return;
    }

    player_controller = local_player->PlayerController;

    if (!player_controller)
    {
        LOG_WARN("no player controller");
        return;
    }

    if (!IsPointerReadable(&player_controller->AcknowledgedPawn))
    {
        LOG_ERROR("Pointer on OwningGameInstance not readable!");
        return;
    }

    pawn = player_controller->AcknowledgedPawn;

    if (!pawn)
    {
        LOG_WARN("no pawn");
        return;
    }
}

bool utils::IsGameExploitable()
{
    if (!pawn)
        return false;

    return true;
}

bool utils::IsAddressReadable(const void* ptr, size_t size)
{
    MEMORY_BASIC_INFORMATION mbi;
    if (VirtualQuery(ptr, &mbi, sizeof(mbi)) == 0)
        return false;
    if (mbi.State != MEM_COMMIT)
        return false;
    if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS))
        return false;
    return (reinterpret_cast<uintptr_t>(ptr) + size) <= (reinterpret_cast<uintptr_t>(mbi.BaseAddress) + mbi.RegionSize);
}
