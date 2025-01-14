# Greetings

This is a series of articles on programming in C++ for old and new platforms.

We write legacy from scratch in C++ without raising suspicions among orderlies.

# Lesson 01 - Small program
# Lesson 02 - Drawing in Windows

# LDL - Little Directmedia Layer, HOL - Header only library
1. Free for everyone.
2. Consider and accept all ideas.
3. We do not limit the developer.
4. We support old and new platforms.
5. Cross-platform.
6. Simple API.

# Library Features
1. Creating a window.
2. Event management.
3. Drawing 2D graphics. (OpenGL, Software)
4. Supports all versions of OpenGL (1.0 - 4.6).

# Build for Linux
1. sudo apt-get install libx11-dev
2. sudo apt-get install libgl1-mesa-dev
3. git clone https://github.com/JordanCpp/LDL.git
4. cd Lib-LDL
5. cmake. or cmake -Bout
6. make

# Integration into your project (CMake Linux or Windows)
add_subdirectory("LDL")
include_directories("LDL/include")
target_link_libraries(${CMAKE_PROJECT_NAME} LDL)

# Support platforms.
1. Windows 95 and higher. (32 and 64 bit)
2. Linux (Debian 3) and higher.(32 and 64 bit)
3. MS-DOS (16 and 32 bit)

# Support graphics API.
1. OpenGL >= 1.0 and <= 4.6

# Support 2D renders.
1. OpenGL 1.2
2. Software

# The main idea is to write an analogue of the SDL library. 
Accessible to everyone, without exception. 
Under a free license. Add interesting functionality.

# License.
Boost Software License - Version 1.0 - August 17th, 2003

# Support compillers (C++ any standarts)
1. MinGW (gcc 3) and higher
2. GCC 3 and higher
3. Visual C++ 5.0 and higher
4. Open Watcom V2
5. Borland C++ 2.0 and higher

# Example OpenGL 3.3 - Triangle
![0](screenshots/01_GL3_Triangle.png)  
