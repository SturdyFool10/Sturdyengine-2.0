@echo off
echo If you have not already, please go into the SturdyEngine 2.0 subfolder and run GetDependancies.ps1 with the newest powershell version(7.2.4 or newer)
pause
REM run cmake for visual studio 2022 and build the project
cmake -B build -G "Visual Studio 17 2022" -A x64
pause