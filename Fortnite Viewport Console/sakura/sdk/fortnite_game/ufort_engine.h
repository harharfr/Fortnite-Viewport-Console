#pragma once

class UFortEngine : public UEngine
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/FortniteGame.FortEngine")));

		return Class;
	}
};
