# C++ Project Starter Code
Create a clean Visual Studio C++ project pipeline using cmake. 

Example code structure.
```
root/
 - build/
 - include/
   - <project include files>
 - lib/
   - include/
     - <external include files>
 - src/
   - <project source files>
 - main.cpp
 - CMakeLists.txt
```

## Guide
- You can rename the project by changing the following line in `CMakeLists.txt`:
  ```
  project(myproject)
  ```
- Each time you clone the repo, just run the following:
  ```
  mkdir build
  cd build
  cmake ..
  ```
- Now you can treat the project as a normal Visual Studio project:
  - You can build/run your project in Release or Debug using just the one `build` directory. 
  - The executable will be located at `build/<BUILD_TYPE>/myproject.exe`. 
  - You can add/delete files as you see fit. As long as your files are in one of the three directories indicated above (`include`, `lib/include`, or `src`), the project will keep track of them. 
  - You can run 
    ```
    cmake ..
    ```
    from the `build` directory at any time to update the Visual Studio solution.
  - Files in any of the `include` directories above can by included without prefixes.
  - You can even create additional directories under the given ones to organize your code and they will be added to the solution next time you run `cmake ..`
  
