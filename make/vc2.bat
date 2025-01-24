
rem C:\MSVC20\BIN\CL.exe

C:\MSVC20\BIN\CL.exe -IC:\MSVC20\BIN\INCLUDE -I..\support -I..\LDL\include  ..\LDL_Win.cpp ..\LDL\source\*.cpp ..\LDL\source\Windows\*.cpp /link gdi32.lib winmm.lib user32.lib opengl32.lib
rem C:\MSVC20\BIN\CL cl /O2 -GX -FeLDL_Img.exe -I..\support -I..\LDL\include ..\LDL_Img.cpp ..\LDL\source\*.cpp ..\LDL\source\Windows\*.cpp /link gdi32.lib winmm.lib user32.lib opengl32.lib

pause
