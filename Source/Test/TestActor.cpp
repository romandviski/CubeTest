// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}	

void ATestActor::MyBlueprintCallableFunction()
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

int32 ATestActor::MyBlueprintPureFunction()
{
	return 666;
}	

void ATestActor::MyBlueprintNativeEventFunction_Implementation()
{
	// больше про логирование
	// https://www.chrismccole.com/blog/logging-in-ue4-cpp
	// https://www.unrealcommunity.wiki/logging-lgpidy6i
	
	UE_LOG(LogTemp, Warning, TEXT("MyBlueprintImplementableEventFunction called"));
	
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

int32 ATestActor::MyBlueprintCallableParameterReturnFunction(int x, float y, FString z)
{

	return 0;
}

int32 ATestActor::MyBlueprintPureParameterReturnFunction(int x, float y, FString z)
{

	return 0;
}

void ATestActor::JustMyParameterFunction(int x, float y, FString z)
{
	
}
