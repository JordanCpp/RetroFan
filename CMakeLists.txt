# LDL - Little DirectMedia Layer

if (UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    link_libraries(${X11_LIBRARIES})
    include_directories(${X11_INCLUDE_DIR})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s -O2 -fno-exceptions -fno-rtti -fno-builtin")

    add_definitions(-DLDL_RENDER_XLIB)
    #add_definitions(-DLDL_RENDER_XCB)
    #add_definitions(-DLDL_RENDER_WAYLAND)
endif()

if (WIN32)
    set(libs gdi32 user32 winmm msimg32)
elseif (UNIX AND NOT APPLE)
    set(libs X11 dl xcb)
endif()

#add_definitions(-DLDL_RENDER_BUFFER_RGB)
#add_definitions(-DLDL_RENDER_BUFFER_PALETTE)
add_definitions(-DLDL_RENDER_NATIVE_RGB)
#add_definitions(-DLDL_RENDER_NATIVE_PALETTE)

include_directories("LDL/include")

FILE(GLOB SHARED_SOURCES "LDL/source/*.cpp" "LDL/source/Renders/*.cpp")

if (WIN32)
    FILE(GLOB PLATFORM_SOURCES "LDL/source/Windows/*.cpp")
else()
    FILE(GLOB PLATFORM_SOURCES 
    "LDL/source/UNIX/XLib/*.cpp" 
    "LDL/source/UNIX/Xcb/*.cpp"
    "LDL/source/UNIX/Wayland/*.cpp")
endif()

add_library(LDL ${SHARED_SOURCES} ${PLATFORM_SOURCES})
target_link_libraries(LDL ${libs})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/make/img24.bmp        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/make/SeasonsTiles.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(LDL_Pal "LDL_Pal.cpp")
target_link_libraries(LDL_Pal LDL)

add_executable(LDL_Img "LDL_Img.cpp")
target_link_libraries(LDL_Img LDL)

add_executable(LDL_Win "LDL_Win.cpp")
target_link_libraries(LDL_Win LDL)

add_executable(LDL_Iso "LDL_Iso.cpp" "Isometrc.cpp")
target_link_libraries(LDL_Iso LDL)

if (WIN32)
    add_executable(wWin "wWin.cpp")
    target_link_libraries(wWin ${libs})
else()
    add_executable(xWin "xWin.cpp")
    target_link_libraries(xWin ${libs})

    add_executable(xcbWin "xcbWin.cpp")
    target_link_libraries(xcbWin ${libs})
endif()

FILE(GLOB FALLOUT_SOURCES "Fallout/*.cpp")
add_executable(Fallout  ${FALLOUT_SOURCES})
target_link_libraries(Fallout LDL)
