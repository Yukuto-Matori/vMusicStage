@ECHO OFF
@REM ===================================
@REM Run Project Build.(UBT) 不要っぽい
@REM ===================================
SET PJNAME=vMusicStage
SET PJDIR=%cd%
SET UPROJ="%PJDIR%\%PJNAME%.uproject"
SET UE5INST=C:\Program Files\Epic Games\UE_5.4\
SET UBT_EXE="%UE5INST%\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"

@REM ===== 実行 ======
%UBT_EXE% -Mode=Build -Project=%UPROJ% -Target=%PJNAME% Development Win64

