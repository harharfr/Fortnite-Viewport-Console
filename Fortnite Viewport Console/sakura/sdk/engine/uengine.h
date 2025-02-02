#pragma once

class UEngine : public UObject
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/Engine.Engine")));

		return Class;
	}

public:
	static UEngine* GetEngine()
	{
		static UEngine* Engine = nullptr;

		for (UC::int32 i = 2147482000; Engine == nullptr; i++)
		{
			Engine = reinterpret_cast<UEngine*>(StaticFindObject(nullptr, nullptr, std::format(TEXT("/Engine/Transient.FortEngine_{}"), i).c_str()));
		}

		return Engine;
	}

public:
	UGameViewportClient* GetGameViewport()
	{
		return *reinterpret_cast<UGameViewportClient**>(uintptr_t(this) + SDK::Offsets::Engine::UEngine::GameViewport);
	}
};
