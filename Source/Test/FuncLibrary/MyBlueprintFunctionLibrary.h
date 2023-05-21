// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

UCLASS()
class TEST_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// функция доступная в любом блюпринте
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Test")
		static FString GetAppVersion();
};
