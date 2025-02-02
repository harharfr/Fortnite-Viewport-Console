#pragma once

class UFunction : public UStruct
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/CoreUObject.Function")));

		return Class;
	}
};
