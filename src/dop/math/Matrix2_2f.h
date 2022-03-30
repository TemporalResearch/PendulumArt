//
// Created by Michael Lynch on 30/03/2022.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace dop
{
    class Matrix2_2f
    {
    public:
        Matrix2_2f(float p00, float p01,
                   float p10, float p11);

        sf::Vector2f multiply(const sf::Vector2f& pos);
    private:
        float p00_;
        float p01_;
        float p10_;
        float p11_;
    };
}