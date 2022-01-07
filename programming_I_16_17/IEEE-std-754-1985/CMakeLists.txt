# Almost all CMake files should start with this.
cmake_minimum_required(VERSION 3.10)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# ------------------------------------------------------------------------------
# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables.
project(IEEE-std-754-1985
        VERSION 1.0
        DESCRIPTION "IEEE Standard for Binary Floating-Point Arithmetic."
        LANGUAGES C)

# ------------------------------------------------------------------------------
# Add include directories to the build.
include_directories(include)

# ------------------------------------------------------------------------------
# Add the source files for the main executable.
set(SOURCE_FILES_1
    tests/main.c

    src/float_t.c
    src/toolbox.c
    )

# ------------------------------------------------------------------------------
# Add the main executable.
add_executable(test-main ${SOURCE_FILES_1})

# ------------------------------------------------------------------------------
# Add this command, for <math.h> or any standard library is similar.
target_link_libraries(test-main -lm)

# ------------------------------------------------------------------------------
# The C standard whose features are requested to build this target.
set_property(TARGET test-main PROPERTY C_STANDARD 99)
