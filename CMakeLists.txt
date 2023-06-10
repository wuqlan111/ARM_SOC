
set(CMAKE_SYSTEM_NAME   Generic)
cmake_minimum_required(VERSION 3.22)

# enable asm files
enable_language(ASM)

# set toolchain
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_OBJCOPY       arm-none-eabi-objcopy)
set(CMAAKE_OBJDUMP      arm-none-eabi-objdump)
set(CMAAKE_AR      arm-none-eabi-ar)

set(CMAKE_TRY_COMPILE_TARGET_TYPE   STATIC_LIBRARY)


# set project name
set(PROJECT_NAME    armv7)
project(${PROJECT_NAME} LANGUAGES  C ASM)

set(TARGET_OUT_DIR   ${CMAKE_SOURCE_DIR}/target)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${TARGET_OUT_DIR}/bin)


# set compile flag
set(CMAKE_C_COMPILER_FORCED   TURE)
set(CMAKE_CXX_COMPILER_FORCED   TURE)


add_compile_options(-mcpu=cortex-m3 -mthumb)
add_compile_options(-ffunction-sections -fdata-sections -fno-common)

set(EXECUTABLE_ELF     ${PROJECT_NAME}.elf)


aux_source_directory(./boot   BOOT_SRCS)
aux_source_directory(./kernel  KERNEL_SRCS)
aux_source_directory(./lib  LIB_SRCS)
aux_source_directory(./mm  MM_SRCS)


add_executable(${EXECUTABLE_ELF}  ${BOOT_SRCS} ${KERNEL_SRCS} 
                    ${LIB_SRCS} ${MM_SRCS})

INCLUDE_DIRECTORIES(
    ./include
    ./include/asm
)

add_custom_command(
    TARGET   ${EXECUTABLE_ELF}   POST_BUILD
    COMMAND  ${OBJCOPY_TOOL}  -O   ihex "${EXE}"
)






