// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ThroughTheFallout/Public/Game/ThroughTheFalloutGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeThroughTheFalloutGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
THROUGHTHEFALLOUT_API UClass* Z_Construct_UClass_AThroughTheFalloutGameMode();
THROUGHTHEFALLOUT_API UClass* Z_Construct_UClass_AThroughTheFalloutGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_ThroughTheFallout();
// End Cross Module References

// Begin Class AThroughTheFalloutGameMode
void AThroughTheFalloutGameMode::StaticRegisterNativesAThroughTheFalloutGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AThroughTheFalloutGameMode);
UClass* Z_Construct_UClass_AThroughTheFalloutGameMode_NoRegister()
{
	return AThroughTheFalloutGameMode::StaticClass();
}
struct Z_Construct_UClass_AThroughTheFalloutGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Game/ThroughTheFalloutGameMode.h" },
		{ "ModuleRelativePath", "Public/Game/ThroughTheFalloutGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AThroughTheFalloutGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AThroughTheFalloutGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ThroughTheFallout,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AThroughTheFalloutGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AThroughTheFalloutGameMode_Statics::ClassParams = {
	&AThroughTheFalloutGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AThroughTheFalloutGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AThroughTheFalloutGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AThroughTheFalloutGameMode()
{
	if (!Z_Registration_Info_UClass_AThroughTheFalloutGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AThroughTheFalloutGameMode.OuterSingleton, Z_Construct_UClass_AThroughTheFalloutGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AThroughTheFalloutGameMode.OuterSingleton;
}
template<> THROUGHTHEFALLOUT_API UClass* StaticClass<AThroughTheFalloutGameMode>()
{
	return AThroughTheFalloutGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AThroughTheFalloutGameMode);
AThroughTheFalloutGameMode::~AThroughTheFalloutGameMode() {}
// End Class AThroughTheFalloutGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Game_ThroughTheFalloutGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AThroughTheFalloutGameMode, AThroughTheFalloutGameMode::StaticClass, TEXT("AThroughTheFalloutGameMode"), &Z_Registration_Info_UClass_AThroughTheFalloutGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AThroughTheFalloutGameMode), 1559080133U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Game_ThroughTheFalloutGameMode_h_4183266628(TEXT("/Script/ThroughTheFallout"),
	Z_CompiledInDeferFile_FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Game_ThroughTheFalloutGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Game_ThroughTheFalloutGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
