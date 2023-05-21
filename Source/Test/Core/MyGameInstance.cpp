// Fill out your copyright notice in the Description page of Project Settings.


#include "../Core/MyGameInstance.h"

#include "GameFramework/GameUserSettings.h"

UMyGameInstance::UMyGameInstance()
{
	
}

void UMyGameInstance::Init()
{
	Super::Init();
	
	GEngine->GameUserSettings->SetVSyncEnabled(true);
	GEngine->GameUserSettings->ApplySettings(true);
	GEngine->GameUserSettings->SaveSettings();
	
	GEngine->Exec(GetWorld(), TEXT("t.MaxFPS 60"));
}
