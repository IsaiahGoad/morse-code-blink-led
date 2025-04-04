set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR riscv)

set(SYSROOT $ENV{SYSROOT_RISCV64})

set(CMAKE_SYSROOT ${SYSROOT})
set(CMAKE_C_COMPILER "riscv64-unknown-linux-musl-gcc")
set(CMAKE_CXX_COMPILER "riscv64-unknown-linux-musl-g++")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)