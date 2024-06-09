// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values
AMyPlayer::AMyPlayer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	// Выдадим игроку случайное имя и рандомно очков немного =)
	Name = GenerateRandomName(5, 10); 
	Score = UKismetMathLibrary::RandomIntegerInRange(1, 1000);
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

FString AMyPlayer::GenerateRandomName(int MinLength, int MaxLength)
{
	FString RandomName = "";

	int Length = FMath::RandRange(MinLength, MaxLength);  // Генерируем случайную длину имени

	for (int i = 0; i < Length; ++i)
	{
		TCHAR RandomChar = FMath::RandRange('A', 'Z');  // Генерируем случайную букву от 'A' до 'Z'
		RandomName.AppendChar(RandomChar);
	}

	return RandomName;
}

void AMyPlayer::ShowInfo() const
{
	// больше про логирование
	// https://www.chrismccole.com/blog/logging-in-ue4-cpp
	// https://www.unrealcommunity.wiki/logging-lgpidy6i
	
	UE_LOG(LogTemp, Warning, TEXT("Player: %s, have score %d"), *Name, Score );
	
	if(GEngine)
	{
		FString Message = FString::Printf(TEXT("Player: %s, have score %d"), *Name, Score);
		GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Yellow, Message);
	}
}

