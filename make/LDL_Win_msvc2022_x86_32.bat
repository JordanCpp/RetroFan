
call "c:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"

cl ..\LDL_Win.cpp ..\LDL\source\*.cpp ..\LDL\source\Windows\*.cpp -I..\LDL\include -link kernel32.lib gdi32.lib user32.lib winmm.lib

pause
