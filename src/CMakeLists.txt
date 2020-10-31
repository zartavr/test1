cmake_minimum_required(VERSION 3.13)

project(template LANGUAGES C CXX ASM)

add_executable_elf(${PROJECT_NAME} main.cpp)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include
)

# Add inner targets
add_subdirectory(hw)

# Add ${PROJECT_NAME}::version target
add_version_target(${PROJECT_NAME})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE common::standard_libraries
            common::linker_options
            common::c11cpp17standards
            # linker script
            -T"${CMAKE_CURRENT_LIST_DIR}/ldscripts/${PROJECT_NAME}.ld"
            # Generate the Linker Map file
            -Wl,-Map="${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.map"
            # Link public libraries
            etl
            yxml
            cm3cpp
            tplib::hw
            expected
            magic_enum
            NamedType
            Opencm3::stm32f2
            # Generate version
            ${PROJECT_NAME}::version
            # Link inner targets
            ${PROJECT_NAME}::hw
)

# Post-build execs generation
generate_exes(${PROJECT_NAME} EXE_TYPES srec bin hex)
