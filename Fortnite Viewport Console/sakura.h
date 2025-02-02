#pragma once

#include <nlohmann/json.hpp>

#include <string>
#include <filesystem>
#include <fstream>

#include "sakura/sdk.h"

static void InitializeViewportConsole()
{
    UFortEngine* Engine = reinterpret_cast<UFortEngine*>(UEngine::GetEngine());

    if (!Engine)
        return;

    UFortGameViewportClient* GameViewport = reinterpret_cast<UFortGameViewportClient*>(Engine->GetGameViewport());

    if (!GameViewport)
        return;

    UFortConsole* ViewportConsole = reinterpret_cast<UFortConsole*>(UGameplayStatics::SpawnObject(UFortConsole::StaticClass(), GameViewport));

    if (!ViewportConsole)
        return;

    GameViewport->SetViewportConsole(ViewportConsole);
}
