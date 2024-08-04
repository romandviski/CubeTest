// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TestEditorTarget : TargetRules
{
	public TestEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		
		//DefaultBuildSettings = BuildSettingsVersion.V2; // было в 4.27
		
		DefaultBuildSettings = BuildSettingsVersion.Latest; // для 5 анрила должно быть так
		//IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		
		ExtraModuleNames.AddRange( new string[] { "Test" } );
	}
}
