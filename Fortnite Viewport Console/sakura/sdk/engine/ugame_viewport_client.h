#pragma once

class UGameViewportClient : public UObject
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/Engine.GameViewportClient")));

		return Class;
	}

public:
	void SetViewportConsole(UConsole* ViewportConsole)
	{
		*reinterpret_cast<UConsole**>(uintptr_t(this) + SDK::Offsets::Engine::UGameViewportClient::ViewportConsole) = ViewportConsole;
	}
};
