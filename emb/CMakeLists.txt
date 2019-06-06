cmake_minimum_required(VERSION 3.13)


# ==================================
# Cross-project CMake configurations
# ==================================

# Add CMake scripts (includes) into scope
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Add prebuilded libs into scope
list(APPEND CMAKE_LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")

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

add_subdirectory(src)