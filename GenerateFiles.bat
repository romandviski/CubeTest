echo off

:: <- this commented string
:: original video -> https://youtu.be/eqKVuLcLduM
:: Special thanks to Yuri Popov

set VersionSelector=U:\Epic Games\Launcher\Engine\Binaries\Win64\UnrealVersionSelector.exe
set ProjectName=Test.uproject
set ProjectPath=%CD%\%ProjectName%

:: for UE 5
::set EnginePath=U:\UNREAL_ENGINE\UE_5.2
::set UBTRelativePatch=Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe

:: for UE 4
set EnginePath=U:\UNREAL_ENGINE\UE_4.27
set UBTRelativePatch=Engine\Binaries\DotNET\UnrealBuildTool.exe

::Start version selector
"%VersionSelector%" -switchversionsilent %ProjectPath% %EnginePath%
"%EnginePath%\%UBTRelativePatch%" -projectfiles -progress -project=%ProjectPath% 

:: flags for builds from source: -game -engine

::echo %ProjectPath%
pause