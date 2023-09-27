<div align="center">

# 2DBallsCollisions

*Developed in September 2023*

<br>

"Simulation of 2D ball collisions, based on the Principles of Momentum and Kinetic Energy Conservation"

<br>

This simulation is developed in C and leverages the [SDL](https://www.libsdl.org/) library for graphical rendering.

<br>
<br>

</div>

---

# Building and Development
The simulation was developed on Ubuntu, a Linux-based operating system built on the Debian architecture.   
It utilizes CMake for build configuration and the gcc compiler for code compilation.   
Follow the instructions below if you wish to compile using this setup. 

<br>

## Compilation instructions (Linux-Ubuntu)

1. Install the sdl library and cmake :
    ```bash
    sudo apt-get install libsdl2-dev
    sudo apt-get install cmake
    ```

<br>

2. Navigate to the project's directory.
    
<br>

3. Create a build directory : 
    ```bash
    mkdir build
    ```
    
<br>

4. Navigate to the build directory : 
    ```bash
    cd build
    ```
    
<br>

5. Generate the makefiles (Choose between the debug and the release version) :
    ```bash
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    ```
    ```bash
    cmake -DCMAKE_BUILD_TYPE=Release ..
    ```
    
<br>

6. Compile the project :
    ```bash
    make
    ```
    
<br>

7. Run the simulation (Choose between the debug and the release version) :
    ```bash
    ./debug
    ```
    ```bash
    ./release
    ```

<br>
<br>


## Compilation instructions (Windows)

1. Install CMake and the MinGW compiler.

<br>

2. Add CMake and MinGW bin folders to your system's environment variables.

<br>

2. Navigate to the project's directory.
    
<br>

3. Create and navigate to the build directory: 
    ```powershell
    mkdir build
    cd build 
    ```

<br>

4. Add all the dll files inside the build directory :
    ```powershell
    Copy-Item "..\utils\dll-files\SDL2.dll" -Destination ".\"
    ```

    
<br>

5. Generate the makefiles (Choose between the debug and the release version) :
    ```powershell
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
    ```
    ```powershell
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
    ```
    
<br>

7. Compile the project:
    ```powershell
    mingw32-make 
    ```
    
<br>

6. Run the simulation (Choose between the debug and the release version):
    ```powershell
    ./debug
    ```
    ```powershell
    ./release
    ```

<br>
<br>