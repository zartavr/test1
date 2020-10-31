project(yxml C ASM)

add_library(${PROJECT_NAME} STATIC
    yxml/yxml.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR} # for output targets
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/yxml # for inner use
)

mark_as_system(${PROJECT_NAME})
