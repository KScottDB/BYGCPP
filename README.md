# What

BYGCPP is a rewrite of the Bad Youtube-DL GUI in C++.

Bad Youtube-DL GUI was originally written in C# / WinForms, and the project
has now been abandoned.

Hopefully this one is easier to maintain.

# How

This project uses CMake as a building system.

On most systems you should be able to run these commands to build,
provided your buildtools are in PATH or whatever.

```
cmake -S . -B bin
cd bin
make              # or whatever the equivalent is on your system
                  # e.g. "msbuild" on windows / Visual Studio
```