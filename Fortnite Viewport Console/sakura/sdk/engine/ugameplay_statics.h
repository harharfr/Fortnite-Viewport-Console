#pragma once

class UGameplayStatics : public UObject
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/Engine.GameplayStatics")));

		return Class;
	}

public:
	static UObject* SpawnObject(UClass* ObjectClass, UObject* Param_Outer)
	{
		static UGameplayStatics* GameplayStatics = reinterpret_cast<UGameplayStatics*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/Engine.Default__GameplayStatics")));
		static UFunction* Function = reinterpret_cast<UFunction*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/Engine.GameplayStatics.SpawnObject")));

		struct GameplayStatics_SpawnObject
		{
			UClass* ObjectClass;
			UObject* Param_Outer;
			UObject* ReturnValue;
		};

		GameplayStatics_SpawnObject Params;

		Params.ObjectClass = ObjectClass;
		Params.Param_Outer = Param_Outer;

		GameplayStatics->ProcessEvent(Function, &Params);

		return Params.ReturnValue;
	}
};
