// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"

AMyGameMode::AMyGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Спавним немного игроков в мире
	if (ClassForSpawn)
	{
		for (int i = 0; i < PlayerAmount; i++)
		{
			FVector SpawnLocation(0.f, 0.f, 50.f);
			FRotator SpawnRotation(0.f, 0.f, 0.f);
			auto TempPlayer = GetWorld()->SpawnActor<AMyPlayer>(ClassForSpawn, SpawnLocation, SpawnRotation);
			// Добавляем игрока в массив
			PlayerArray.Add(TempPlayer);
		}
	}

	// Сортируем игроков пузырьковой сортировкой
	for (int32 i = 0; i < PlayerArray.Num() - 1; ++i)
	{
		for (int32 j = 0; j < PlayerArray.Num() - i - 1; ++j)
		{
			if (PlayerArray[j]->Score < PlayerArray[j + 1]->Score)
			{
				// Меняем местами, если элементы в неправильном порядке
				AMyPlayer* Temp = PlayerArray[j];
				PlayerArray[j] = PlayerArray[j + 1];
				PlayerArray[j + 1] = Temp;
			}
		}
	}
	
	// метод Sort из класса TArray, который принимает лямбда-выражение в качестве аргумента.
	// Лямбда-выражение сравнивает объекты типа AMyPlayer по их полям Score для упорядочивания их по убыванию.
	//PlayerArray.Sort([](const AMyPlayer& A, const AMyPlayer& B) {	return A.Score > B.Score; });

	// Просим игроков показать своё инфо в цикле for each
	for (AMyPlayer* Player : PlayerArray)
	{
		Player->ShowInfo();
	}
}

void AMyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
