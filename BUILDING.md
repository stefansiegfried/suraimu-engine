# Building

## Linux

### Dependencies

- CMake 3.14
- SDL2
- nlohmann_json (automatically downloaded)
- googletest (automatically downloaded)

### Compiling

``` bash
mkdir build && cd build
cmake ..
make
```

### Testing

A testrunner binary is available under tests/ after performing the compilation step.

### Usage

Link your game against libsuraimuengine.a
