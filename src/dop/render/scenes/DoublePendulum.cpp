//
// Created by Michael Lynch on 30/03/2022.
//

#include "DoublePendulum.h"
#include <dop/math/RotationMatrix.h>
#include <cmath>
#include <dop/math/VectorUtils.hpp>

void dop::DoublePendulum::render(sf::RenderWindow &window)
{
//    window.clear(sf::Color::Black);

    {
        firstRotation_ += 0.1;
        secondRotation_ += 0.1 * rodMultiplier_;

        auto endPosition =
                createRotationMatrix(firstRotation_ * (M_PI / 180.0))
                        .multiply({0, 0.25});
        firstEnd_.setPosition(endPosition);
        rod_.setPosition({0, 0}, endPosition);

        auto secondPosition = createRotationMatrix(
                secondRotation_ * (M_PI / 180.0))
                .multiply({0, 0.25});

        secondRod_.setPosition(
                endPosition,
                endPosition + secondPosition);
        secondEnd_.setPosition(endPosition + secondPosition);
    }

//    pivot_.render(window);
//    firstEnd_.render(window);
//    secondEnd_.render(window);
//    window.draw(rod_);
    window.draw(secondRod_);
}

dop::DoublePendulum::DoublePendulum(int rodMultiplier)
        : pivot_(0.02)
        , firstEnd_(0.02)
        , secondEnd_(0.02)
        , rodMultiplier_{rodMultiplier}
        , rod_{{0, 0}, {0, 0.25}}
        , secondRod_({0, 0.25}, {0, 0.5})
{
    pivot_.setPosition({0, 0});
    pivot_.setColor(sf::Color::Green);

    firstEnd_.setPosition({0, 0});
    firstEnd_.setColor(sf::Color::Green);

    firstEnd_.setPosition({0, 0});
    secondEnd_.setColor(sf::Color::Green);
}
