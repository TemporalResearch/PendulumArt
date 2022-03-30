//
// Created by Michael Lynch on 30/03/2022.
//

#include "RotationMatrix.h"

#include <cmath>

dop::Matrix2_2f dop::createRotationMatrix(float rotation)
{
    return { std::cos(rotation), -std::sin(rotation),
            std::sin(rotation), std::cos(rotation)};
}
