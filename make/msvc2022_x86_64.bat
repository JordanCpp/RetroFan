
call "c:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

cl -GS- -nologo -Gm- -GR- -EHa- -Oi ..\wWin.cpp ..\libc\*.cpp ..\libc\Windows\*.cpp ..\libcpp\*.cpp -I..\libc\include -I..\libcpp\include -I..\WinAPI -link kernel32.lib gdi32.lib user32.lib winmm.lib /NODEFAULTLIB

pause
