# Godot C++ Template

Clean template for starting a new Godot 4 lab or prototype with GDExtension and C++.

## What stays in the template

- `godot-cpp` submodule integration
- SCons build scripts
- a minimal registered C++ class: `ExampleClass`
- a minimal Godot project in `project/`
- generated class docs for the example class

## Project structure

```text
src/                 C++ sources for the extension
project/             Godot project
doc_classes/         XML docs used by Godot class reference generation
bin/                 Native build output
SConstruct           Main build script
build_debug.bat      Debug build helper
build_release.bat    Release build helper
setup.bat            Submodule/bootstrap helper
```

## Starting a new lab

1. Create a branch from `master`.
2. Replace `ExampleClass` with your own classes in `src/`.
3. Register your classes in `src/register_types.cpp`.
4. Update the Godot scene and scripts in `project/`.
5. Build with `build_debug.bat` and open the `project/` folder in Godot.

## Notes

- `master` is intended to stay generic.
- Lab-specific code, reports, screenshots, and generated study materials should live in separate branches.
