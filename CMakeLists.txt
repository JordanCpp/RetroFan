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

FILE(GLOB SHARED_SOURCES "LDL/source/*.cpp" "LDL/source/Renders/*.cpp")

if (WIN32)
    FILE(GLOB PLATFORM_SOURCES "LDL/source/Windows/*.cpp")
else()
    FILE(GLOB PLATFORM_SOURCES "LDL/source/UNIX/*.cpp")
endif()

add_library(LDL ${SHARED_SOURCES} ${PLATFORM_SOURCES})

add_executable(LDL_Pal "LDL_Pal.cpp")
target_link_libraries(LDL_Pal LDL ${libs})

add_executable(LDL_Img "LDL_Img.cpp")
target_link_libraries(LDL_Img LDL ${libs})

add_executable(LDL_Win "LDL_Win.cpp")
target_link_libraries(LDL_Win LDL ${libs})

add_executable(LDL_Iso "LDL_Iso.cpp")
target_link_libraries(LDL_Iso LDL ${libs})

if (WIN32)
    add_executable(wWin "wWin.cpp")
    target_link_libraries(wWin ${libs})
else()
    add_executable(xWin "xWin.cpp")
    target_link_libraries(xWin ${libs})
endif()
