// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TestTarget : TargetRules
{
	public TestTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		
		//DefaultBuildSettings = BuildSettingsVersion.V2; // было в 4.27
		
		DefaultBuildSettings = BuildSettingsVersion.Latest; // для совместимости с 5 анрилом должно быть так
		//IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		
		ExtraModuleNames.AddRange( new string[] { "Test" } );
	}
}
