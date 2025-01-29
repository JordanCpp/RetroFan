if(FALSE)
enable_language(ASM)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE) 

    add_compile_options(/GS- /nologo /Gm- /GR- /EHa- /Oi)
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB")

    string(REPLACE "/O2" "/Oi" CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
    string(REPLACE "/O2" "/Oi" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    string(REPLACE "/O2" "/Oi" CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}")
endif()

include_directories("libc/include")
include_directories("libcpp/include")

if (WIN32)
    include_directories("WinAPI")
    add_library(libc 
    "libc/Windows/Init.cpp" 
    "libc/Windows/Portable.cpp" 
    "libc/stdio.cpp"
    "libc/stdlib.cpp"
    "libc/string.cpp"
    "libcpp/new.cpp")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlib -nostartfiles -nodefaultlibs -s -O2 -fno-exceptions -fno-rtti -fno-builtin")
    add_library(libc 
    "libc/UNIX/x86_64.s"
    "libc/UNIX/syscalls.cpp"
    "libc/UNIX/Init.cpp" 
    "libc/UNIX/Portable.cpp" 
    "libc/stdio.cpp" 
    "libc/stdlib.cpp" 
    "libc/string.cpp"
    "libcpp/new.cpp")
endif()

add_executable(main "main.cpp")
target_link_libraries(main libc)
endif()

# LDL - Little DirectMedia Layer

if (UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    link_libraries(${X11_LIBRARIES})
    include_directories(${X11_INCLUDE_DIR})
endif()

if (WIN32)
    set(libs gdi32 user32 winmm msimg32)
elseif (UNIX AND NOT APPLE)
    set(libs X11 dl)
endif()

include_directories("LDL/include")

if (WIN32)
    add_library(LDL
    "LDL/source/Windows/MainWin.cpp"
    "LDL/source/Windows/GdiRndr.cpp"
    "LDL/source/Windows/GdiTex.cpp"
    "LDL/source/Windows/GdiUtils.cpp"
    "LDL/source/Eventer.cpp"
    "LDL/source/BaseRndr.cpp"
    "LDL/source/BaseWin.cpp"
    "LDL/source/Result.cpp"
    "LDL/source/PixConv.cpp"
    "LDL/source/ColorKey.cpp"
    "LDL/source/Palette.cpp")
else()
    add_library(LDL
    "LDL/source/UNIX/MainWin.cpp"
    "LDL/source/UNIX/XLibRndr.cpp"
    "LDL/source/Eventer.cpp"
    "LDL/source/BaseRndr.cpp"
    "LDL/source/BaseWin.cpp"
    "LDL/source/Result.cpp"
    "LDL/source/PixConv.cpp"
    "LDL/source/ColorKey.cpp"
    "LDL/source/Palette.cpp")
endif()

add_executable(LDL_Pal "LDL_Pal.cpp")
target_link_libraries(LDL_Pal LDL ${libs})

add_executable(LDL_Img "LDL_Img.cpp")
target_link_libraries(LDL_Img LDL ${libs})

add_executable(LDL_Win "LDL_Win.cpp")
target_link_libraries(LDL_Win LDL ${libs})

if (WIN32)
    add_executable(wWin "wWin.cpp")
    target_link_libraries(wWin ${libs})
else()
    add_executable(xWin "xWin.cpp")
    target_link_libraries(xWin ${libs})
endif()
