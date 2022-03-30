//
// Created by Michael Lynch on 30/03/2022.
//

#include "NPendulum.h"
#include <dop/math/VectorUtils.hpp>
#include <dop/math/RotationMatrix.h>

//#define ROTATION_SPEED 0.1f
#define ROTATION_SPEED 8.3f
#define ROD_LENGTH 0.15f

dop::NPendulum::NPendulum(int noOfPivots, float rodMultiplier)
{
    for (int i = 0; i < noOfPivots; i++)
    {
        pivots_.emplace_back(rodMultiplier);
        rodMultiplier *= rodMultiplier;
    }
}

void dop::NPendulum::render(sf::RenderWindow &window)
{
//    window.clear(sf::Color::Black);

    sf::Vector2f previousPosition(0, 0);

    for (int i = 0; i < pivots_.size(); i++)
    {
        previousPosition = pivots_.at(i).render(
                window,
                previousPosition,
                (pivots_.size() - i < 6));
    }
}

dop::NPendulum::Rod::Rod(int rodMultiplier)
    : pivot_{0.01}
    , line_{{0, 0}, {0, 0.25}}
    , rotation_{0}
    , rodMultiplier_{rodMultiplier}
{
    pivot_.setPosition({0, 0});
    pivot_.setColor(sf::Color(0, 255, 0, 10));

    line_.setColor(sf::Color(255, 255, 255, 10));
}

sf::Vector2f dop::NPendulum::Rod::render(sf::RenderWindow &window, const sf::Vector2f &initialPosition, bool display)
{
    rotation_ += ROTATION_SPEED * rodMultiplier_;

    auto rotationPosition =
            createRotationMatrix(rotation_ * (M_PI / 180.0))
                .multiply({0, ROD_LENGTH});
    auto actualPosition = initialPosition + rotationPosition;

    pivot_.setPosition(actualPosition);
    line_.setPosition(initialPosition, actualPosition);

//    {
//        pivot_.setPosition({actualPosition.x, 0});
//    }

    pivot_.render(window);
//    window.draw(line_);
    if (display)
    {
//        pivot_.render(window);
//        window.draw(line_);
    }

    return actualPosition;
}
