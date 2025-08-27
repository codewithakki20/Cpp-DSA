@echo off
g++ dynmicMemoryAllo.cpp -o dynmicMemoryAllo.exe
if %errorlevel% equ 0 (
    dynmicMemoryAllo.exe
)
pause
