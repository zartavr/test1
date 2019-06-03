## --> Compile opencm3 lib
    include(Opencm3)

    add_libopencm3_for(f2)
    add_library(opencm3 ALIAS Opencm3::stm32f2) # this alias is needed for cm3cpp
## <--

## --> Compile etl lib
    set(BUILD_TESTS OFF CACHE BOOL "Build unit tests of ETL" FORCE)
    set(ETL_PROFILE "PROFILE_CPP17_GENERIC" CACHE STRING "ETL_PROFILE" FORCE)

    add_subdirectory(etl)

    target_compile_features(etl INTERFACE 
        cxx_std_17
        c_std_11
    )

    target_compile_definitions(etl INTERFACE
        ETL_NO_CHECKS
    )
## <--

## --> Compile projects
    add_subdirectory(template)
## <--