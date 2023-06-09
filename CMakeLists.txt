

# set toolchain
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER  arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-as)
set(OBJCOPY_TOOL       arm-none-eabi-objcopy)

set(CMAKE_C_COMPILER_FORCED   TURE)
set(CMAKE_CXX_COMPILER_FORCED   TURE)

set(TARGET_NAME    armv7)
set(EXECUTABLE_ELF     ${TARG_NAME}.elf)

set(CMAKE_C_FLAGS "-march=armv7-m  -g" CACHE  INTENAL  "c compiler flags" )
set(CMAKE_C_FLAGS_DEBUG   "-O0"   CACHE  INTENAL "debug flags")

set(ALL_SRCS)


add_subdirectory(
    boot
    kernel
    mm
    vfp
    mm
)

add_executable(${EXECUTABLE_ELF}  ${ALL_SRCS})

add_custom_command(
    TARGET   ${EXECUTABLE_ELF}   POST_BUILD
    COMMAND  ${OBJCOPY_TOOL}  -O   ihex "${EXE}"
)






