add_library(dop_src_all
        dop/render/scenes/SinglePendulum.cpp
        dop/render/shapes/CenteredCircle.cpp
        dop/render/shapes/Line.cpp
        dop/math/Matrix2_2f.cpp
        dop/math/RotationMatrix.cpp
        dop/render/scenes/DoublePendulum.cpp dop/render/scenes/DoublePendulum.h dop/render/scenes/NPendulum.cpp dop/render/scenes/NPendulum.h dop/render/scenes/BouncingLine.cpp dop/render/scenes/BouncingLine.h)
target_link_libraries(dop_src_all
        PUBLIC libtr_lang::libtr_lang
        PUBLIC libcpp_logger::libcpp_logger
        PUBLIC sfml-graphics
        PUBLIC sfml-window
        PUBLIC sfml-system
        )
target_include_directories(dop_src_all
        PUBLIC ./)