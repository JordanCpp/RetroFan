enable_language(ASM)

if (UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    link_libraries(${X11_LIBRARIES})
    include_directories(${X11_INCLUDE_DIR})
endif()

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE) 

    add_compile_options(/GS- /nologo /Gm- /GR- /EHa- /Oi)
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB")

    string(REPLACE "/O2" "/Oi" CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
    string(REPLACE "/O2" "/Oi" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    string(REPLACE "/O2" "/Oi" CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}")
endif()

if (WIN32)
    set(libs gdi32 user32 winmm)
elseif (UNIX AND NOT APPLE)
    set(libs X11 dl)
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

if (WIN32)
    include_directories("LDL/include")
    add_library(LDL
    "LDL/source/Windows/MainWin.cpp"
    "LDL/source/Eventer.cpp")

    add_executable(LDL_Win "LDL_Win.cpp")
    target_link_libraries(LDL_Win LDL libc ${libs})
endif()

if (WIN32)
    add_executable(wWin "wWin.cpp")
    target_link_libraries(wWin libc ${libs})
else()
    add_executable(xWin "xWin.cpp")
    target_link_libraries(xWin libc ${libs})
endif()