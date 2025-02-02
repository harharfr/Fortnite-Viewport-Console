#pragma once

class UStruct : public UObject
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/CoreUObject.Struct")));

		return Class;
	}
};
