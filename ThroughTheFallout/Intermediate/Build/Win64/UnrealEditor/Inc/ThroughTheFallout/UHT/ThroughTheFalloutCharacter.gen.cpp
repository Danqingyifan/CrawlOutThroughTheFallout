// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ThroughTheFallout/Public/Character/ThroughTheFalloutCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeThroughTheFalloutCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet_NoRegister();
THROUGHTHEFALLOUT_API UClass* Z_Construct_UClass_AThroughTheFalloutCharacter();
THROUGHTHEFALLOUT_API UClass* Z_Construct_UClass_AThroughTheFalloutCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_ThroughTheFallout();
// End Cross Module References

// Begin Class AThroughTheFalloutCharacter
void AThroughTheFalloutCharacter::StaticRegisterNativesAThroughTheFalloutCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AThroughTheFalloutCharacter);
UClass* Z_Construct_UClass_AThroughTheFalloutCharacter_NoRegister()
{
	return AThroughTheFalloutCharacter::StaticClass();
}
struct Z_Construct_UClass_AThroughTheFalloutCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/ThroughTheFalloutCharacter.h" },
		{ "ModuleRelativePath", "Public/Character/ThroughTheFalloutCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/ThroughTheFalloutCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeSet_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/ThroughTheFalloutCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeSet;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AThroughTheFalloutCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AThroughTheFalloutCharacter, AbilitySystemComponent), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComponent_MetaData), NewProp_AbilitySystemComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::NewProp_AttributeSet = { "AttributeSet", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AThroughTheFalloutCharacter, AttributeSet), Z_Construct_UClass_UAttributeSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeSet_MetaData), NewProp_AttributeSet_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::NewProp_AbilitySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::NewProp_AttributeSet,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_ThroughTheFallout,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(AThroughTheFalloutCharacter, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::ClassParams = {
	&AThroughTheFalloutCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AThroughTheFalloutCharacter()
{
	if (!Z_Registration_Info_UClass_AThroughTheFalloutCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AThroughTheFalloutCharacter.OuterSingleton, Z_Construct_UClass_AThroughTheFalloutCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AThroughTheFalloutCharacter.OuterSingleton;
}
template<> THROUGHTHEFALLOUT_API UClass* StaticClass<AThroughTheFalloutCharacter>()
{
	return AThroughTheFalloutCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AThroughTheFalloutCharacter);
AThroughTheFalloutCharacter::~AThroughTheFalloutCharacter() {}
// End Class AThroughTheFalloutCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Character_ThroughTheFalloutCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AThroughTheFalloutCharacter, AThroughTheFalloutCharacter::StaticClass, TEXT("AThroughTheFalloutCharacter"), &Z_Registration_Info_UClass_AThroughTheFalloutCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AThroughTheFalloutCharacter), 1590485476U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Character_ThroughTheFalloutCharacter_h_3729554941(TEXT("/Script/ThroughTheFallout"),
	Z_CompiledInDeferFile_FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Character_ThroughTheFalloutCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Character_ThroughTheFalloutCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
