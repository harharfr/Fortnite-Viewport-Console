#pragma once

static UObject* StaticFindObject(UClass* Class, UObject* InOuter, const TCHAR* Name, bool ExactClass = false)
{
    static UObject* (*OldStaticFindObject)(UClass*, UObject*, const TCHAR*, bool) = nullptr;

    if (!OldStaticFindObject)
        OldStaticFindObject = reinterpret_cast<decltype(OldStaticFindObject)>(
            uintptr_t(GetModuleHandle(NULL)) + SDK::Offsets::StaticFindObject
        );

    if (!SDK::Offsets::StaticFindObjectFix)
    {
        return OldStaticFindObject(Class, InOuter, Name, ExactClass);
    }
    else
    {
        struct
        {
            const wchar_t* Ptr;
            int Length;
        } NameStruct;

#ifdef _UNICODE
        NameStruct.Ptr = Name;
#else
        std::wstring wName(Name);
        NameStruct.Ptr = wName.c_str();
#endif
        NameStruct.Length = static_cast<int>(NoCRT::__wcslen(NameStruct.Ptr));

        using FnType = UObject* (__fastcall*)(UClass*, UObject*, void*, uint64_t);
        FnType Fn = reinterpret_cast<FnType>(OldStaticFindObject);
        return Fn(Class, InOuter, &NameStruct, 0);
    }
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
