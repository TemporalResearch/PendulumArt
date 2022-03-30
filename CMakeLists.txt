cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DDEBUG)

project(DoublePendulum)

find_package(libcpp_logger REQUIRED)
find_package(libtr_lang REQUIRED)

message("ARCH: ${CMAKE_HOST_SYSTEM_PROCESSOR}")


if (${APPLE} AND ${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "arm64")
    message("Configuring as arm64 Mac")
    set(SFML_DIR ../sfml/mac_apple_silicon)
    find_package(SFML 2.5.0 COMPONENTS graphics system window REQUIRED)
elseif (${APPLE})
    message("Configuring as intel Mac")
    ## TODO Set up SFML properly using our own SFMLConfig file so we don't have to do this
    set(SFML_DIR ../sfml/Frameworks/SFML.framework/Resources/CMake)
    find_package(SFML 2.5.0 COMPONENTS graphics system window REQUIRED)
else()
    message(FATAL_ERROR "Other architectures currently not supported")
endif()



find_package(double_pendulum REQUIRED)

#add_subdirectory(include)
add_subdirectory(tests)

add_executable(dop_main src/executables/main.cpp)

# Tests
#include(CTest)
include(../Catch2/contrib/ParseAndAddCatchTests.cmake)
add_subdirectory(../Catch2 catch2)
enable_testing()

target_link_libraries(dop_main
        PRIVATE libcpp_logger::libcpp_logger
        PRIVATE libtr_lang::libtr_lang
        PRIVATE double_pendulum::libdouble_pendulum
        PRIVATE sfml-graphics
        PRIVATE sfml-window
        PRIVATE sfml-system)
