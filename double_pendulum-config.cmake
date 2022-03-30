if (TARGET double_pendulum::libdouble_pendulum)
    message("double_pendulum target already exists")
    return()
endif()

set(CMAKE_CXX_STANDARD 20)

find_package(libcpp_logger REQUIRED)
find_package(libtr_lang REQUIRED)

add_library(double_pendulum::libdouble_pendulum INTERFACE IMPORTED)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src libdouble_pendulum)

target_link_libraries(double_pendulum::libdouble_pendulum
        INTERFACE dop_src_all)