// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

FString UMyBlueprintFunctionLibrary::GetAppVersion()
{
	FString AppVersion;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		AppVersion,
		GGameIni
	);
	//GConfig->SetString(TEXT("/Script/EngineSettings.GeneralProjectSettings"), TEXT("MySection"), TEXT("MyInfo"), GGameIni);
	return AppVersion;
}