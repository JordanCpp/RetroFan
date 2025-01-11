enable_language(ASM)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB")
endif()

include_directories("libc/include")
include_directories("libcpp/include")

if (WIN32)
    add_library(libc 
    "libc/Windows/Init.cpp" 
    "libc/Windows/Portable.cpp" 
    "libc/stdio.cpp" 
    "libc/string.cpp"
    "libcpp/new.cpp")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlib -nostartfiles -nodefaultlibs -nostdinc -s -O2 -fno-exceptions -fno-rtti -fno-builtin")
    add_library(libc 
    "syscall.s"
    "libc/UNIX/syscalls.cpp"
    "libc/UNIX/Init.cpp" 
    "libc/UNIX/Portable.cpp" 
    "libc/stdio.cpp" 
    "libc/string.cpp"
    "libcpp/new.cpp")
endif()


add_executable(main "main.cpp")
target_link_libraries(main libc)
