#pragma once

namespace SDK
{
	namespace Offsets
	{
		uintptr_t StaticFindObject = 0x0;
		uintptr_t ProcessEvent = 0x0; // UObject::ProcessEvent

		namespace Engine
		{
			namespace UEngine
			{
				uintptr_t GameViewport = 0xa20; // UEngine::GameViewport
			}

			namespace UGameViewportClient
			{
				uintptr_t ViewportConsole = 0x40; // UGameViewportClient::ViewportConsole
			}
		}
	}

	std::string GetReleaseVersion()
	{
		std::filesystem::path path = std::filesystem::current_path(); // Fortnite/FortniteGame/Binaries/Win64/

		path = path.parent_path();                                    // Fortnite/FortniteGame/Binaries/
		path = path.parent_path();                                    // Fortnite/FortniteGame/
		path = path.parent_path();                                    // Fortnite/

		path.append("Cloud");                                         // Fortnite/Cloud/
		path.append("cloudcontent.json");                             // Fortnite/Cloud/cloudcontent.json

		std::ifstream stream(path);

		if (!stream.is_open())
			return std::string();

		nlohmann::json json;
		stream >> json;
		stream.close();

		return std::string(json["BuildVersion"]) + "-" + std::string(json["Platform"]);
	}

	bool Init()
	{
		if (Beep(500, 500))
		{
			std::string ReleaseVersion = GetReleaseVersion();

			// offsets -> https://github.com/SternI/FortniteOffsets

			if (ReleaseVersion == "++Fortnite+Release-33.00-CL-38324112-Windows")
			{
				Offsets::StaticFindObject = 0x17FEE00;
				Offsets::ProcessEvent = 0x1870C8C; // (Index: 0x42)
			}

			if (ReleaseVersion == "++Fortnite+Release-33.00-CL-38504598-Windows")
			{
				Offsets::StaticFindObject = 0x17A8760;
				Offsets::ProcessEvent = 0x16497FC; // (Index: 0x16)
			}

			if (ReleaseVersion == "++Fortnite+Release-33.10-CL-38630093-Windows")
			{
				Offsets::StaticFindObject = 0x267f424;
				Offsets::ProcessEvent = 0x21A42F8; // (Index: 0x38)
			}

			if (ReleaseVersion == "++Fortnite+Release-33.11-CL-38773622-Windows")
			{
				Offsets::StaticFindObject = 0x20A0E4C;
				Offsets::ProcessEvent = 0x23B3394; // (Index: 0x2c)
			}

			if (ReleaseVersion == "++Fortnite+Release-33.20-CL-39082670-Windows")
			{
				Offsets::StaticFindObject = 0x2165B14;
				Offsets::ProcessEvent = 0x21FB80C; // (Index: 0x39)
			}

			if (ReleaseVersion == "++Fortnite+Release-33.20-CL-39277041-Windows")
			{
				Offsets::StaticFindObject = 0x2028B24;
				Offsets::ProcessEvent = 0x21232B4; // (Index: 0x43)
			}

			if (ReleaseVersion == "++Fortnite+Release-33.30-CL-39435251-Windows")
			{
				Offsets::StaticFindObject = 0x2643024;
				Offsets::ProcessEvent = 0x2511BC8; // (Index: 0x47)
			}
		}

		return Offsets::StaticFindObject != 0x0 && Offsets::ProcessEvent != 0x0;
	}
}

/* /Script/CoreUObject */
class UObject;
class UStruct;
class UClass;
class UFunction;

/* /Script/Engine */
class UEngine;
class UGameViewportClient;
class UConsole;
class UGameplayStatics;

/* /Script/FortniteGame */
class UFortEngine;
class UFortGameViewportClient;
class UFortConsole;

#include "sdk/unreal_containers.h"

/* /Script/CoreUObject */
#include "sdk/core_uobject/uobject.h"
#include "sdk/core_uobject/ustruct.h"
#include "sdk/core_uobject/uclass.h"
#include "sdk/core_uobject/ufunction.h"

/* /Script/Engine */
#include "sdk/engine/uengine.h"
#include "sdk/engine/ugame_viewport_client.h"
#include "sdk/engine/uconsole.h"
#include "sdk/engine/ugameplay_statics.h"

/* /Script/FortniteGame */
#include "sdk/fortnite_game/ufort_engine.h"
#include "sdk/fortnite_game/ufort_game_viewport_client.h"
#include "sdk/fortnite_game/ufort_console.h"
