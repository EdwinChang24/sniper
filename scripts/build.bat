if not exist "build\" mkdir build\
cmake -S . -B  build\ -DCMAKE_TOOLCHAIN_FILE="C:\\Program Files\vcpkg\scripts\buildsystems\vcpkg.cmake"
cmake --build build\ --config Release -DCMAKE_TOOLCHAIN_FILE="C:\\Program Files\vcpkg\scripts\buildsystems\vcpkg.cmake"
