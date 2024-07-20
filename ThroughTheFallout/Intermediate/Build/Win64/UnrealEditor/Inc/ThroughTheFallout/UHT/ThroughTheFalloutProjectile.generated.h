// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interaction/ThroughTheFalloutProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef THROUGHTHEFALLOUT_ThroughTheFalloutProjectile_generated_h
#error "ThroughTheFalloutProjectile.generated.h already included, missing '#pragma once' in ThroughTheFalloutProjectile.h"
#endif
#define THROUGHTHEFALLOUT_ThroughTheFalloutProjectile_generated_h

#define FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Interaction_ThroughTheFalloutProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Interaction_ThroughTheFalloutProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAThroughTheFalloutProjectile(); \
	friend struct Z_Construct_UClass_AThroughTheFalloutProjectile_Statics; \
public: \
	DECLARE_CLASS(AThroughTheFalloutProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ThroughTheFallout"), NO_API) \
	DECLARE_SERIALIZER(AThroughTheFalloutProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Interaction_ThroughTheFalloutProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AThroughTheFalloutProjectile(AThroughTheFalloutProjectile&&); \
	AThroughTheFalloutProjectile(const AThroughTheFalloutProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AThroughTheFalloutProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AThroughTheFalloutProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AThroughTheFalloutProjectile) \
	NO_API virtual ~AThroughTheFalloutProjectile();


#define FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Interaction_ThroughTheFalloutProjectile_h_12_PROLOG
#define FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Interaction_ThroughTheFalloutProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Interaction_ThroughTheFalloutProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Interaction_ThroughTheFalloutProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Interaction_ThroughTheFalloutProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> THROUGHTHEFALLOUT_API UClass* StaticClass<class AThroughTheFalloutProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ThroughTheFallout_Source_ThroughTheFallout_Public_Interaction_ThroughTheFalloutProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
