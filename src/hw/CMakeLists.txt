## hw library

# Add interface inner target
add_library(${PROJECT_NAME}_hw INTERFACE)

# Add sources to inner target
target_sources(${PROJECT_NAME}_hw
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/HwStub.cpp
)

# Add "namespaced" alias for inner target
add_library(${PROJECT_NAME}::hw ALIAS ${PROJECT_NAME}_hw)
