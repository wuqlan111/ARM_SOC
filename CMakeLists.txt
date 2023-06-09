

# set toolchain
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER  arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-as)

set(CMAKE_C_COMPILER_FORCED   TURE)
set(CMAKE_CXX_COMPILER_FORCED   TURE)


set(CMAKE_C_FLAGS "-march=armv7-m  -g" CACHE  INTENAL  "c compiler flags" )
set(CMAKE_C_FLAGS_DEBUG   "-O0"   CACHE  INTENAL "debug flags")







