@ECHO OFF
@REM =====================================
@REM Run Unreal Automation Tool ( Cook )
@REM =====================================
SET PJNAME=vMusicStage
SET PJDIR=%cd%
SET UPROJ="%PJDIR%\%PJNAME%.uproject"
SET UE5INST=C:\01_add\005_dev\030_Epic\UE_5.4
SET UAT_BAT="%UE5INST%\Engine\Build\BatchFiles\RunUAT.bat"

@REM ===== 実行 ======
%UAT_BAT% Cook -project=%UPROJ% -targetplatform=Win64 -noP4 -cookall -skipeditorcontent

