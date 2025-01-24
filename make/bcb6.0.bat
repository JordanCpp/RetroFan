
rem bcc32 -w-8027 -eLDL_Img.exe  -I..\LDL\include ..\LDL_Img.cpp


BCC32 -I"C:\Program Files\Borland\CBuilder\Include" -I..\support -I..\LDL\include -emain.exe ..\LDL\source\*.cpp ..\LDL\source\Windows\*.cpp ..\LDL_Win.cpp -L"C:\Program Files\Borland\CBuilder\lib"

pause
