#pragma once

static UObject* StaticFindObject(UClass* Class, UObject* InOuter, const TCHAR* Name, bool ExactClass = false)
{
	static UObject* (*StaticFindObject)(UClass*, UObject*, const TCHAR*, bool) = nullptr;

	if (StaticFindObject == nullptr)
		StaticFindObject = reinterpret_cast<decltype(StaticFindObject)>(uintptr_t(GetModuleHandle(NULL)) + SDK::Offsets::StaticFindObject);

	return StaticFindObject(Class, InOuter, Name, ExactClass);
}

class UObject
{
public:
	static UClass* StaticClass()
	{
		static UClass* Class = nullptr;

		if (Class == nullptr)
			Class = reinterpret_cast<UClass*>(StaticFindObject(nullptr, nullptr, TEXT("/Script/CoreUObject.Object")));

		return Class;
	}

public:
	void ProcessEvent(UFunction* Function, void* Parms)
	{
		static void (*ProcessEvent)(UObject*, UFunction*, void*) = nullptr;

		if (ProcessEvent == nullptr)
			ProcessEvent = reinterpret_cast<decltype(ProcessEvent)>(uintptr_t(GetModuleHandle(NULL)) + SDK::Offsets::ProcessEvent);

		ProcessEvent(this, Function, Parms);
	}
};
