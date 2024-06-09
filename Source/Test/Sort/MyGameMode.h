// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayer.h"
#include "GameFramework/GameModeBase.h"

#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Для регулировки количества игроков из блюпринта
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PlayerAmount = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AMyPlayer> ClassForSpawn = nullptr;
	
	// Массив указателей на игроков, без UPROPERTY может попасть под сборщика мусора
	UPROPERTY()
	TArray<AMyPlayer*> PlayerArray;
	
};
