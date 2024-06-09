// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlayer.generated.h"

UCLASS()
class TEST_API AMyPlayer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// использование static для функции влияет на область видимости функции
	// и существующие правила доступа к ней
	static FString GenerateRandomName(int MinLength, int MaxLength);

public:
	FString Name = "Default";
	int32 Score = 777;

	void ShowInfo() const;
};
