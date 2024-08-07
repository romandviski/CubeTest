// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor.h"



ATestActor::ATestActor()
{
	// Выключаем тик, если он нам не нужен
	PrimaryActorTick.bCanEverTick = false;
	
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
	/*
	// Пример_1 кода для спавна
	FVector SpawnLocation = FVector(0, 0, 0);
	FRotator SpawnRotation = FRotator(0, 0, 0);
	GetWorld()->SpawnActor<ATestActor>(ATestActor::StaticClass(), SpawnLocation, SpawnRotation);

	// Пример_2 кода для спавна
	FTransform SpawnTransform = FTransform(SpawnRotation, SpawnLocation);
	auto SpawnClass = ATestActor::StaticClass();
	GetWorld()->SpawnActor<ATestActor>(SpawnClass, SpawnTransform);
	*/
}

void ATestActor::PostInitProperties()
{
	Super::PostInitProperties();
	
	FinalDamage = BaseDamage * Multiplier;
}

#if WITH_EDITOR // код компилируется для использования в редакторе, в игре не нужен
void ATestActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FinalDamage = BaseDamage * Multiplier;

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif


void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// В нашем случае всё равно отключено в конструкторе класса
}	

void ATestActor::MyBlueprintCallableFunction()
{
	MyBlueprintImplementableEventFunction();

	// больше про логирование
	// https://www.chrismccole.com/blog/logging-in-ue4-cpp
	// https://www.unrealcommunity.wiki/logging-lgpidy6i
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

float ATestActor::AddFloats(float A, float B)
{
	return A + B;
}

void ATestActor::JustMyParameterFunction(int x, float y, FString z)
{
	// пусто...
}

void ATestActor::NewFunc()
{
	
}
