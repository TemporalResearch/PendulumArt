//
// Created by Michael Lynch on 30/03/2022.
//

#include "NPendulum.h"
#include <dop/math/VectorUtils.hpp>
#include <dop/math/RotationMatrix.h>

#define ROTATION_SPEED 0.1f
//#define ROTATION_SPEED 8.3f
#define ROD_LENGTH 0.15f

dop::NPendulum::NPendulum(int noOfPivots,
                          std::function<std::pair<sf::Vector2f, sf::Vector2f>(sf::Vector2f initialPosition,
                                                                              sf::Vector2f endPosition)> rodPostProcess)
{
    for (int i = 0; i < noOfPivots; i++)
    {
        pivots_.emplace_back();
    }
}

void dop::NPendulum::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    sf::Vector2f previousPosition(0, 0);
    float rotation{0};

    for (int i = 0; i < pivots_.size(); i++)
    {
        auto positionAndRotation  = pivots_.at(i).render(
                window,
                previousPosition, rotation,
                (pivots_.size() - i < 6));

        previousPosition = positionAndRotation.first;
        rotation = positionAndRotation.second;
    }
}

dop::NPendulum::Rod::Rod()
    : pivot_{0.01}
    , line_{{0, 0}, {0, 0.25}}
    , rotation_{0}
{
    pivot_.setPosition({0, 0});
    pivot_.setColor(sf::Color(0, 255, 0, 100));

    line_.setColor(sf::Color(255, 255, 255, 100));
}

std::pair<sf::Vector2f, float>
dop::NPendulum::Rod::render(sf::RenderWindow &window, const sf::Vector2f &initialPosition, float initialRotation,
                            bool display)
{
    rotation_ += ROTATION_SPEED;

    auto actualRotation = rotation_ + initialRotation;
    auto rotationPosition =
            createRotationMatrix(actualRotation * (M_PI / 180.0))
                .multiply({0, ROD_LENGTH});
    auto actualPosition = initialPosition + rotationPosition;

    pivot_.setPosition(actualPosition);
    line_.setPosition(initialPosition, actualPosition);

//    {
//        pivot_.setPosition({actualPosition.x, 0});
//    }

    pivot_.render(window);
    window.draw(line_);
    if (display)
    {
//        pivot_.render(window);
//        window.draw(line_);
    }

    return {actualPosition, actualRotation};
}
