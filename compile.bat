@echo off

gcc %1 -o "%~dpn1.exe" -std=c11 -static -g -Wall

REM pause