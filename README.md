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

## Compilation instructions (Ubuntu)

1. Install the sdl library
    ```bash
    sudo apt-get install libsdl2-dev
    ```

<br>

2. Navigate to the project's directory.
    
<br>

3. Create a build directory: 
    ```bash
    mkdir build
    ```
    
<br>

4. Navigate to the build directory: 
    ```bash
    cd build 
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

6. Compile the project:
    ```bash
    make
    ```
    
<br>

7. Run the simulation (Choose between the debug and the release version):
    ```bash
    ./debug
    ```
    ```bash
    ./release
    ```

<br>
<br>