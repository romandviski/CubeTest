// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
}

inline void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
