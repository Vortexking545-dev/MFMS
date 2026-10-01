@echo off
C:\msys64\ucrt64\bin\gcc.exe main.c employee.c -o mfms.exe
echo Build complete! Launching MFMS...
mfms.exe
pause