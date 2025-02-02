#pragma once

class UClass : public UStruct
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/CoreUObject.Class")));

		return Class;
	}
};
