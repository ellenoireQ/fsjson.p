![logo](docs/logo.png)

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-%23008FBA.svg?style=for-the-badge&logo=makefile&logoColor=white)
![Android](https://img.shields.io/badge/Android-34A853?style=flat&logo=android&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)
![GitHub](https://img.shields.io/badge/GitHub-100000?style=flat&logo=github&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D7?style=flat&logo=windows&logoColor=white)
![Version](https://img.shields.io/badge/windows?style=flat&logo=1.0.0&logoColor=white)

# FileSystem Json Parser

A lightweight and fast Command Line Interface (CLI) tool for parsing filesystem information into JSON format. Built with modern C++, this tool allows you to read and export `/proc` filesystem data in a structured JSON format for easy processing and integration with other tools.

## Features

- **Filesystem to JSON** - Convert filesystem structure into JSON format
- **Proc Reader** - Read process information from `/proc` (comm, cmdline, state)
- **Cross-Platform** - Supports Linux, Android, and Windows
- **Fast & Lightweight** - Built with modern C++ for optimal performance
- **Flexible Output** - Output to console or save to file

## Usage

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
export ANDROID_NDK=/path/to/android-ndk

# arm64-v8a
cmake -B build-android \
  -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
  -DANDROID_ABI=arm64-v8a \
  -DANDROID_PLATFORM=android-24

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
