cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 20)
project(msvc-asan-bug
    LANGUAGES CXX
)

macro(add_exe name)
    add_executable(${name} ${name}.cpp)
    target_compile_options(${name} PRIVATE -fsanitize=address)
    add_custom_target(run-${name} COMMAND ${name})
endmacro()

add_exe(repro)
add_exe(no-align-no-repro)
add_exe(no-heap-alloc-no-repro)
add_exe(no-deduce-no-repro)
