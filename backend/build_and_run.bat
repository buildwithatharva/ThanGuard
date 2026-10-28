@echo off
cd /d "%~dp0"
gcc main.c machine_data.c graph.c machine_graph.c -std=c99 -Wall -Wextra -o thanguard.exe
if errorlevel 1 (
  echo Build failed. Check the compiler errors above.
  pause
  exit /b 1
)
thanguard.exe
pause
