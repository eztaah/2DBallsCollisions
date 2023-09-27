# CMake minimum version and project details
cmake_minimum_required(VERSION 3.10)
project(ball)

# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# Fichiers source
set(SOURCE_FILES
    src/main.c
    src/application/collisions_manager.c
    src/engine/ebase.c
    src/engine/eglobals.c
    src/engine/emath.c
    src/engine/erenderer.c)

# Include directories
set(INCLUDE_DIRS
    src/engine
    src/application

    if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
        src/3rdparty/SDL/include
    endif()
)



if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    #Find SDL2
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
endif()




################################ DEBUG ################################
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Create the executable from the sources files
    add_executable(debug ${SOURCE_FILES})

    # Indicate where are all the header files
    target_include_directories(debug PRIVATE ${INCLUDE_DIRS})

    # Link external libraries 
    if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
        target_link_directories(debug PRIVATE src/3rdparty/SDL/lib) # Indicate where is the .a file of the libraries 
        target_link_libraries(debug PRIVATE SDL2 mingw32) # Indicate which library we need
    endif()
    if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
        target_link_libraries(debug PRIVATE ${SDL2_LIBRARIES} m)
    endif()

    # Add compilation options
    target_compile_options(debug PRIVATE -Wall -Wextra -g) # -g -> give informations to the debugger
endif()
########################################################################



################################ RELEASE ################################
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Create the executable from the sources files
    add_executable(release ${SOURCE_FILES})

    # Indicate where are all the header files
    target_include_directories(release PRIVATE ${INCLUDE_DIRS})

    # Link external libraries 
    if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
        target_link_directories(release PRIVATE src/3rdparty/SDL/lib) # Indicate where is the .a file of the libraries 
        target_link_libraries(release PRIVATE SDL2 mingw32) # Indicate which library we need
    endif()
    if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
        target_link_libraries(release PRIVATE ${SDL2_LIBRARIES} m)
    endif()

    # Add compilation options
    target_compile_options(release PRIVATE -O3) # Optimize the program (takes longer to compile but runs faster)
endif()
########################################################################