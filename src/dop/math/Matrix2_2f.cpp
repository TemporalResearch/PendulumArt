//
// Created by Michael Lynch on 30/03/2022.
//

#include "Matrix2_2f.h"

dop::Matrix2_2f::Matrix2_2f(float p00, float p01, float p10, float p11)
    : p00_{p00} , p01_{p01}
    , p10_{p10} , p11_{p11}
{

}

sf::Vector2f dop::Matrix2_2f::multiply(const sf::Vector2f &pos)
{
    return {
        (p00_ * pos.x) + (p01_ * pos.y),
        (p10_ * pos.x) + (p11_ * pos.y)
    };
}
