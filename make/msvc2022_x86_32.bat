
call "c:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"

cl -nologo -Gm- -GR- -EHa- -Oi ..\main.cpp ..\libc\*.cpp ..\libc\Windows\*.cpp -I..\libc\include -link kernel32.lib -nodefaultlib

pause
