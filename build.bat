@echo off

REM Build script for Pezzza's transitions

echo Setting up environment...
set PATH=C:\raylib\w64devkit\bin;%PATH%

REM Create bin directory if it doesn't exist
if not exist "bin" mkdir bin

echo Compiling...
"C:\raylib\w64devkit\bin\gcc.exe" -o bin\circle-transitions.exe src\main.c  src\circle.c src\easings.c ^
    -I"C:\raylib\w64devkit\include" ^
    -I"C:\raylib\raylib\src" ^
    -L"C:\raylib\w64devkit\lib" ^
    -lraylib -lopengl32 -lgdi32 -lwinmm -Wl,--subsystem,windows

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful! Executable created in bin\circle-transitions.exe
    echo.
    echo Starting the application...
    start "" "bin\circle-transitions.exe"
) else (
    echo.
    echo Build failed with error code %ERRORLEVEL%
    pause
    exit /b %ERRORLEVEL%
)
