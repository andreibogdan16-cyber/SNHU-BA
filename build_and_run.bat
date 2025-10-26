@echo off
setlocal ENABLEDELAYEDEXPANSION

REM Change to the directory of this script so paths work no matter where it's run from
cd /d "%~dp0"

echo === Corner Grocer: Build & Run (Windows) ===

REM Check input file presence
if not exist "CS210_Project_Three_Input_File.txt" (
  echo [ERROR] Missing CS210_Project_Three_Input_File.txt in %CD%
  echo Place the file next to this .bat and try again.
  pause
  exit /b 1
)

REM Try MinGW g++ first
where g++ >nul 2>&1
if %ERRORLEVEL%==0 (
  echo [INFO] Found g++: using MinGW/GCC toolchain
  echo [BUILD] g++ -std=c++17 -O2 -Wall -Wextra -o grocer.exe main.cpp
  g++ -std=c++17 -O2 -Wall -Wextra -o grocer.exe main.cpp
  if errorlevel 1 (
    echo.
    echo [ERROR] g++ build failed. See messages above.
    pause
    exit /b 1
  )
  echo.
  echo [RUN] grocer.exe
  grocer.exe
  echo.
  echo [DONE]
  pause
  exit /b 0
)

REM If no g++, try MSVC cl (must be run from "Developer Command Prompt for VS")
where cl >nul 2>&1
if %ERRORLEVEL%==0 (
  echo [INFO] Found cl: using MSVC toolchain
  echo [BUILD] cl /nologo /EHsc /W3 /O2 main.cpp /Fe:grocer.exe
  cl /nologo /EHsc /W3 /O2 main.cpp /Fe:grocer.exe
  if errorlevel 1 (
    echo.
    echo [ERROR] cl build failed. See messages above.
    pause
    exit /b 1
  )
  echo.
  echo [RUN] grocer.exe
  grocer.exe
  echo.
  echo [DONE]
  pause
  exit /b 0
)

echo [ERROR] No compiler found.
echo - g++ not found on PATH (install MinGW-w64 or MSYS2 and reopen terminal), or
echo - cl not found (open a "Developer Command Prompt for VS" and run this .bat again).
echo.
echo Tips:
echo   * MinGW-w64: https://www.mingw-w64.org/  (add its bin folder to PATH)
echo   * MSYS2:     https://www.msys2.org/      (use "pacman -S mingw-w64-ucrt-x86_64-gcc")
echo   * Visual Studio: use the "Developer Command Prompt for VS"
pause
exit /b 1
