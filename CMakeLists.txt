cmake_minimum_required(VERSION 3.17)

# ==================================
# Cross-project CMake configurationsjbmnbmbj
# ==================================

# Add CMake scripts (includes) into scope
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/external/cmake")

# Include cross-project preambule:
# - IDE related settings;
# - some CMake hacks.
#
# Normally, this file should be included in
# every project
include(Preambule)

# ===========================
# Global build configurations
# ===========================

project(template)

# Include cross-target interface libraries
include(StandardLibraries)
include(CodeStandards)
include(LinkerCommon)

# Helper tools
include(AddElfExecutable)
include(VersionTargetGenerator)
include(ExesGenerator)
include(MarkAsSystem)

# Enable the most useful warnings for all projects
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion"
)

# Compile libs
add_subdirectory(external)

# Compile project
add_subdirectory(src)
