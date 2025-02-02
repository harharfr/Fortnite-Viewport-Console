#pragma once

class UFortConsole : public UConsole
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/FortniteGame.FortConsole")));

		return Class;
	}
};
