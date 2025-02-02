#pragma once

class UFortGameViewportClient : public UGameViewportClient
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/FortniteGame.FortGameViewportClient")));

		return Class;
	}
};
