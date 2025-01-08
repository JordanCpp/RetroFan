
if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB")
endif()

include_directories("libc/include")
add_library(libc "libc/Windows/Init.cpp" "libc/Windows/Portable.cpp" "libc/stdio.cpp" "libc/string.cpp")

add_executable(main "main.cpp")
target_link_libraries(main libc)
