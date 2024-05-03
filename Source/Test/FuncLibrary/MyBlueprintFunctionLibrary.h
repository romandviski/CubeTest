// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */

// собственный енумератор
UENUM(BlueprintType)
enum class EMyEnumerator : uint8
{
	v1 UMETA(DisplayName = "var1"),
	v2 UMETA(DisplayName = "var2"),
	v3 UMETA(DisplayName = "var3"),
};

// Просто структура, пример пули (проджектаил)
USTRUCT(BlueprintType)
struct FProjectileInfo // название начинается с F, потому что это структура
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ToolTip = "Стартовая скорость пули"))
	float InitialSpeed = 3000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ToolTip = "Время жизни пули"))
	float LifeSpan = 10.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual", meta = (ToolTip = "Моделька пули"))
	UStaticMesh* ProjectileStaticMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual", meta = (ToolTip = "Смещение, поворот и размер"))
	FTransform MeshTransform = FTransform(FRotator(0),FVector::ZeroVector,FVector(0.15f));
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual", meta = (ToolTip = "Эффект на пуле"))
	UParticleSystem* ProjectileTrailFx = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual", meta = (ToolTip = "Смещение, поворот и размер"))
	FTransform TrailFXTransform = FTransform( FRotator(0.f, -180.f, 0.f), FVector::ZeroVector, FVector(0.5f));
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hit Effect ", meta = (ToolTip = "Звук попадания пули в стену или пол"))
	USoundBase* HitSound = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hit Effect ", meta = (ToolTip = "Отметина на стене"))
	UMaterialInterface* DecalOnHit = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hit Effect ", meta = (ToolTip = "Размер отметины"))
	float DecalSize = 30.f;
};

// Структура для создания на её основе таблицы
USTRUCT(BlueprintType)
struct FWeaponSetting : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ToolTip = "Множитель меткости"))
	float AccuracyMultiplier = 1.0f;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ToolTip = "Используется ли обойма?"))
	bool bHasClip = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ToolTip = "Размер обоймы", EditCondition = "bHasClip == true", EditConditionHides))
	int32 ClipSize = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ToolTip = "Базовое время перезарядки обоймы в секундах", EditCondition = "bHasClip == true", EditConditionHides))
	float BaseReloadTime = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX", meta = (ToolTip = "Эффект из ствола при выстреле"))
	UParticleSystem* EffectFireWeapon = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX", meta = (ToolTip = "Смещение, поворот и размер"))
	FTransform EffectTransform = FTransform(FRotator(), FVector::ZeroVector, FVector(0.2f));
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX", meta = (ToolTip = "Звук выстрела"))
	USoundBase* SoundFireWeapon = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX", meta = (ToolTip = "Звук окончания перезарядки (если надо)"))
	USoundBase* SoundReloadWeapon = nullptr;

	// Структура внутри структуры
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Settings", meta = (ToolTip = "Настройки пули"))
	FProjectileInfo ProjectileInfo;
};

UCLASS()
class TEST_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// функция доступная в любом блюпринте
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Test")
		static FString GetAppVersion();
};
