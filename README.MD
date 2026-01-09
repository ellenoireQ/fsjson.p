<img src='docs/logo.svg' alt="diagram" width="400">

![Cpp](https://img.shields.io/badge/c++-%2300599C?style=flat&logo=cplusplus&logoColor=white)
![Cmake](https://img.shields.io/badge/Cmake-%2300599C?style=flat&logo=cmake&logoColor=white)
![make](https://img.shields.io/badge/makefile-%2300599C?style=flat&logo=makefile&logoColor=white)
![ninja](https://img.shields.io/badge/ninja-%2300599C?style=flat&logo=ninja&logoColor=white)
![ninja](https://img.shields.io/badge/Android%20Ndk-%2300599C?style=flat&logo=ninja&logoColor=white)
![Android](https://img.shields.io/badge/Android-34A853?style=flat&logo=android&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)
![Windows](https://img.shields.io/badge/Windows-0078D7?style=flat&logo=windows&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-100000?style=flat&logo=github&logoColor=white)


# FileSystem Json Parser

A lightweight and fast Command Line Interface (CLI) tool for parsing filesystem information into JSON format. Built with modern C++, this tool allows you to read and export `/proc` filesystem data in a structured JSON format for easy processing and integration with other tools.

## Features

- **Filesystem to JSON** - Convert filesystem structure into JSON format
- **Proc Reader** - Read process information from `/proc` (comm, cmdline, state)
- **Cross-Platform** - Supports Linux, Android, and Windows
- **Fast & Lightweight** - Built with modern C++ for optimal performance
- **Flexible Output** - Output to console or save to file

## Usage
![Warning: Need Sudo](https://img.shields.io/badge/warning-sudo%20needed%20to%20access%20/proc%20-critical)
```bash
# Show help message
./main --help

# Show version
./main --version

# Read process information as JSON
./main proc comm --pid 1234 --json

# Save output to file
./main proc comm --pid 1234 --json --output result.json
```

## Options

| Option | Short | Description |
|--------|-------|-------------|
| `read` | `r` | Enable reading mode |
| `proc` | `p` | Specify proc file (cmdline, comm, state) |
| `--output` | `-o` | Output file path |
| `--pid` | `-p` | Specify PID for reading /proc |
| `--json` | `-j` | Display/Print to JSON format |
| `--version` | `-v` | Show version |
| `--help` | `-h` | Show help message |

# How to Build ?

## CMake
### Desktop
```bash
# Desktop
cmake -B build && cmake --build build
```

### Android
```bash
# Android NDK Path
export ANDROID_NDK_HOME=/path/to/android-ndk

# arm64-v8a
cmake -S . -B build-android \
            -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake \
            -DANDROID_ABI=arm64-v8a \
            -DANDROID_PLATFORM=android-33

# Build
cmake --build build-android
```

## Makefile
### Desktop
```bash
# Desktop
make 
```


### This Documentation/Project under development (WIP)
