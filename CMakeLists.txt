cmake_minimum_required(VERSION 3.7)
project(CL_my_asm)

set(CMAKE_C_STANDARD 99)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
file(GLOB LIBFT
        "libft/includes/*"
        "libft/src/additional/src/*"
        "libft/src/additional/includes/*"
        "libft/src/array/src/*"
        "libft/src/array/includes/*"
        "libft/src/ctype/src/*"
        "libft/src/ctype/includes/*"
        "libft/src/error/src/*"
        "libft/src/error/includes/*"
        "libft/src/ft_printf/src/*"
        "libft/src/ft_printf/includes/*"
        "libft/src/get_next_line/src/*"
        "libft/src/get_next_line/includes/*"
        "libft/src/lists/src/*"
        "libft/src/lists/includes/*"
        "libft/src/memory/src/*"
        "libft/src/memory/includes/*"
        "libft/src/printing/src/*"
        "libft/src/printing/includes/*"
        "libft/src/string/src/*"
        "libft/src/string/includes/*"
        roller.s
        barriere.s
        op.c
        op.h
        champs/*.s
        )

set(SOURCE_FILES main.c asm.h split.c helper.c errors.c read.c get_pos.c get_type.c remove_lable.c  clear_file.c validate.c bytecode.c header.c to_file.c helper2.c helper3.c bytecode_help.c helper4.c helper5.c)
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_executable(CL_my_asm ${SOURCE_FILES} ${LIBFT})