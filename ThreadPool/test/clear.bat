@echo off
forfiles /s /m *.exe /c "cmd /c del @file"
