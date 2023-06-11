
set(CMAKE_SYSTEM_NAME   Generic)
cmake_minimum_required(VERSION  3.15)

# enable asm files
enable_language(ASM)

# set toolchain
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_OBJCOPY       arm-none-eabi-objcopy)
set(CMAAKE_OBJDUMP      arm-none-eabi-objdump)
set(CMAAKE_AR      arm-none-eabi-ar)

set(CMAKE_TRY_COMPILE_TARGET_TYPE  STATIC_LIBRARY)

# set project name
set(PROJECT_NAME    armv7)
project(${PROJECT_NAME} LANGUAGES  C ASM)

# set output
set(TARGET_OUT_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/target)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${TARGET_OUT_DIR}/bin)


# set compile flag
set(CMAKE_C_COMPILER_FORCED   TURE)
set(CMAKE_C_FLAGS  "-mcpu=cortex-m3 -mthumb -march=armv7-m -g -Wall")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -ffunction-sections -fdata-sections -fno-common")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -O0 --specs=nosys.specs")
SET(CMAKE_ASM_FLAGS "-mcpu=cortex-m3 -mthumb -march=armv7-m -g")

# set link option
set(LINK_SCRIPT   ${CMAKE_CURRENT_SOURCE_DIR}/boot/boot.ld)
set(CMAKE_EXE_LINKER_FLAGS  "--specs=nosys.specs -T ${LINK_SCRIPT}")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wl,-gc-sections -Wl,--cref")
set(CMAKE_EXE_LINKER_FLAGS  "-Wl,-Map=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.map")


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
aux_source_directory(./test  TEST_SRCS)

# add asm files
set(ASM_SRCS   ./boot/init.S)


# output file
set(EXECUTABLE_ELF     ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.elf)
set(HEX_FILE     ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex)
set(BIN_FILE     ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.bin)

add_executable(${PROJECT_NAME}.elf  ${BOOT_SRCS} ${KERNEL_SRCS} 
                    ${LIB_SRCS} ${MM_SRCS}  ${TEST_SRCS}  ${ASM_SRCS})


add_custom_command(
    TARGET   "${PROJECT_NAME}.elf"   POST_BUILD
    COMMAND  ${CMAKE_OBJCOPY}  -O   ihex   ${EXECUTABLE_ELF}   ${HEX_FILE}
    COMMAND  ${CMAKE_OBJCOPY}  -O   binary  ${EXECUTABLE_ELF}  ${BIN_FILE}
)






