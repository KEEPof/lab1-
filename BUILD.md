# Build

This repository is a clean starting point for Godot 4 GDExtension work in C++.

## Requirements

- Godot 4.x
- Python 3
- SCons
- A C++ toolchain supported by `godot-cpp`

## First-time setup

Run:

```bat
setup.bat
```

This initializes the `godot-cpp` submodule and can generate `compile_commands.json`.

## Build commands

Debug:

```bat
build_debug.bat
```

Release:

```bat
build_release.bat
```

You can also call SCons directly:

```bat
scons platform=windows target=template_debug
scons platform=windows target=template_release
```

## Output

The built library is placed under `bin/<platform>/` and copied into `project/bin/<platform>/`.
