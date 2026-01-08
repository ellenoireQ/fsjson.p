# How to Build ?

![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-%23008FBA.svg?style=for-the-badge&logo=makefile&logoColor=white)

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