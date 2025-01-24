
call "c:\msdev\bin\VCVARS32.BAT"

cl /O2 -GX -FeLDL_Win.exe -I..\support -I..\LDL\include ..\LDL_Win.cpp ..\LDL\source\*.cpp ..\LDL\source\Windows\*.cpp /link gdi32.lib winmm.lib user32.lib opengl32.lib
cl /O2 -GX -FeLDL_Img.exe -I..\support -I..\LDL\include ..\LDL_Img.cpp ..\LDL\source\*.cpp ..\LDL\source\Windows\*.cpp /link gdi32.lib winmm.lib user32.lib opengl32.lib

pause
