
call "c:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

cl /O2 /EHsc -FeLDL_Img.exe -I..\LDL\include ..\LDL_Img.cpp ..\LDL\source\*.cpp ..\LDL\source\Windows\*.cpp /link gdi32.lib winmm.lib user32.lib

pause
