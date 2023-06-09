
cmake_minimum_required(VERSION 3.22)

# set project name
set(PROJECT_NAME    armv7)
project(${PROJECT_NAME}  C)

set(TARGET_OUT_DIR   ${CMAKE_SOURCE_DIR}/target)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${TARGET_OUT_DIR})


# set toolchain
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER  arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-as)
set(OBJCOPY_TOOL       arm-none-eabi-objcopy)

# set compile flag
set(CMAKE_C_COMPILER_FORCED   TURE)
set(CMAKE_CXX_COMPILER_FORCED   TURE)





set(EXECUTABLE_ELF     ${PROJECT_NAME}.elf)

set(CMAKE_C_FLAGS "-march=armv7-m  -g" CACHE  INTENAL  "c compiler flags" )
set(CMAKE_C_FLAGS_DEBUG   "-O0"   CACHE  INTENAL "debug flags")

set(ALL_SRCS)


add_subdirectory(boot)
add_subdirectory(kernel)
add_subdirectory(mm)
add_subdirectory(vfp)
add_subdirectory(test)


add_executable(${EXECUTABLE_ELF}  ${ALL_SRCS})

add_custom_command(
    TARGET   ${EXECUTABLE_ELF}   POST_BUILD
    COMMAND  ${OBJCOPY_TOOL}  -O   ihex "${EXE}"
)






