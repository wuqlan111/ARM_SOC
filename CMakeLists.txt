
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

# set output
set(TARGET_OUT_DIR   ${CMAKE_SOURCE_DIR}/target)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${TARGET_OUT_DIR}/bin)


# set compile flag
set(CMAKE_C_COMPILER_FORCED   TURE)
set(CMAKE_C_FLAGS  "-mcpu=cortex-m3 -mthumb -g -Wall")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -ffunction-sections -fdata-sections -fno-common")

# set link option
set(LINK_SCRIPT   ./boot/boot.lds)
add_link_options(-Wl,-gc-sections --printf-memory-usage,
                    -Map=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m3  -mthumb  -T {LINK_SCRIPT})


# add include dir
INCLUDE_DIRECTORIES(
    ./include
    ./include/asm
)

# add src files
aux_source_directory(./boot   BOOT_SRCS)
aux_source_directory(./kernel  KERNEL_SRCS)
aux_source_directory(./lib  LIB_SRCS)
aux_source_directory(./mm  MM_SRCS)


# output file
set(EXECUTABLE_ELF     ${PROJECT_NAME}.elf)
set(HEX_FILE     ${PROJECT_NAME}.hex)
set(BIN_FILE     ${PROJECT_NAME}.bin)

add_executable(${EXECUTABLE_ELF}  ${BOOT_SRCS} ${KERNEL_SRCS} 
                    ${LIB_SRCS} ${MM_SRCS})


add_custom_command(
    TARGET   ${EXECUTABLE_ELF}   POST_BUILD
    COMMAND  ${CMAKE_OBJCOPY}  -O   ihex  ${PROJECT_NAME}.elf  ${HEX_FILE}
    COMMAND  ${CMAKE_OBJCOPY}  -O   binary  ${PROJECT_NAME}.elf  ${BIN_FILE}
)






