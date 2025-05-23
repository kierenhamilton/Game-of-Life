# Game of Life
## Feature-list
- Variable grid
- Cells switch state upon mouse press
- Updates upon spacebar press
## Dependancies
- Raylib.h
## Build instructions
### UNIX
```
 ++ main.cpp objects.h objects.cpp -lraylib
```
### WINDOWS
```
g++ -o main.cpp objects.h objects.cpp -Ipath_to_raylib/include -Lpath_to_raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
```
## TODO
- Implement a propper buildsystem with CMake
- Refactor void update(); to make it faster
- implement auto update
- scrolling and zooming
