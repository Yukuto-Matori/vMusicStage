@ECHO OFF
@REM =====================================
@REM Run Project Build. ( Run UHT + UBT )
@REM =====================================
SET PJNAME=vMusicStage
SET PJDIR=%cd%
SET UPROJ="%PJDIR%\%PJNAME%.uproject"
SET UE5INST=C:\01_add\005_dev\030_Epic\UE_5.4
SET BUILD_BAT="%UE5INST%\Engine\Build\BatchFiles\Build.bat"

@REM ===== 実行 ======
%BUILD_BAT% %PJNAME% Win64 Shipping %UPROJ%

