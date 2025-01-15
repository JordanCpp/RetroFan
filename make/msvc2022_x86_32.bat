
call "c:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"

cl -O2 ..\wWin.cpp -link kernel32.lib gdi32.lib user32.lib winmm.lib

pause
