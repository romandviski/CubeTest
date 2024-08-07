// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TestTarget : TargetRules
{
	public TestTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		
		//DefaultBuildSettings = BuildSettingsVersion.V2; // было в 4.27
		
		DefaultBuildSettings = BuildSettingsVersion.Latest; // для 5.4 анрила должно быть так
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest; // для 5.4 анрила должно быть так
		
		ExtraModuleNames.AddRange( new string[] { "Test" } );
	}
}
