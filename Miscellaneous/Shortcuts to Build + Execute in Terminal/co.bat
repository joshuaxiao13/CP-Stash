@echo off

echo [1] - Compiling	.....	%1
g++ -std=c++0x %1.cpp -Wall -O2 -o %1.exe

if %errorlevel% == 0 (
    echo [2] - Compilation Successful ..... %1
    echo:
)
echo:
