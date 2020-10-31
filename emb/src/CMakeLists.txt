# Libraries can use any of these
set(BUILD_TESTS OFF CACHE BOOL "Build unit tests" FORCE)
set(ENABLE_TEST OFF CACHE BOOL "Enable unit tests" FORCE)

# Save standard
set(BACKUP_CMAKE_CXX_STANDARD ${CMAKE_CXX_STANDARD})

## --> Compile opencm3 lib
    include(Opencm3)

    add_libopencm3_for(f2)
    # This alias is needed for `cm3cpp` library
    add_library(opencm3 ALIAS Opencm3::stm32f2)
## <--

## --> Compile etl library
    set(ETL_PROFILE "PROFILE_CPP17_GENERIC" CACHE STRING "ETL_PROFILE" FORCE)

    add_subdirectory(etl)

    target_compile_features(etl INTERFACE 
        cxx_std_17
        c_std_11
    )

    target_compile_definitions(etl INTERFACE
        ETL_NO_CHECKS
    )

    mark_as_system(etl)
## <--

## --> Compile expected libary
    set(EXPECTED_BUILD_TESTS OFF CACHE BOOL "Build unit tests of expected" FORCE)
    add_subdirectory(expected)
## <--

# Add other libs
add_subdirectory(magic_enum)
add_subdirectory(named_type)
add_subdirectory(cm3cpp)
add_subdirectory(tplib)
add_subdirectory(yxml)

# Revert standard if it was chaged by libraries
set(CMAKE_CXX_STANDARD ${BACKUP_CMAKE_CXX_STANDARD}) 

## --> Compile projects
    add_subdirectory(template)
## <--
