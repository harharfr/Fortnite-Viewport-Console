#pragma once

class UConsole : public UObject
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/Engine.Console")));

		return Class;
	}
};
