//
// Created by Michael Lynch on 30/03/2022.
//

#include "NPendulum.h"
#include <dop/math/VectorUtils.hpp>
#include <dop/math/RotationMatrix.h>

#define ROD_LENGTH 0.15f

dop::NPendulum::NPendulum(std::vector<float> pivotRotationSpeeds,
                          const std::function<std::pair<sf::Vector2f, sf::Vector2f>(sf::Vector2f initialPosition,
                                                                              sf::Vector2f endPosition)>& rodPostProcess)
{
//    for (int i = 0; i < pivotRotationSpeeds; i++)
//    {
//        pivots_.emplace_back();
//    }

    for (const auto& pivotRotationSpeed : pivotRotationSpeeds)
    {
        pivots_.emplace_back(pivotRotationSpeed, rodPostProcess);
    }
}

void dop::NPendulum::render(sf::RenderWindow &window)
{
//    window.clear(sf::Color::Black);

    sf::Vector2f previousPosition(0, 0);
    float rotation{0};

    for (int i = 0; i < pivots_.size(); i++)
    {
        auto positionAndRotation  = pivots_.at(i).render(
                window,
                previousPosition, rotation,
                (pivots_.size() - i < 2));

        previousPosition = positionAndRotation.first;
        rotation = positionAndRotation.second;
    }
}

dop::NPendulum::Rod::Rod(float rotationSpeed,
                         std::function<std::pair<sf::Vector2f, sf::Vector2f>(sf::Vector2f initialPosition,
                                                                             sf::Vector2f endPosition)> rodPostProcess)
    : pivot_{0.01}
    , line_{{0, 0}, {0, 0.25}}
    , rotationSpeed_{rotationSpeed}
    , rotation_{0}
    , rodPostProcess_{std::move(rodPostProcess)}
{
    pivot_.setPosition({0, 0});
    pivot_.setColor(sf::Color(0, 255, 0, 10));

    line_.setColor(sf::Color(255, 255, 255, 10));
}

std::pair<sf::Vector2f, float>
dop::NPendulum::Rod::render(sf::RenderWindow &window, const sf::Vector2f &initialPosition, float initialRotation,
                            bool display)
{
    rotation_ += rotationSpeed_;

    auto actualRotation = rotation_ + initialRotation;
    auto rotationPosition =
            createRotationMatrix(actualRotation * (M_PI / 180.0))
                .multiply({0, ROD_LENGTH});
    auto actualPosition = initialPosition + rotationPosition;

    const auto [finalStartPosition, finalEndPosition] =
            rodPostProcess_(initialPosition, actualPosition);
    pivot_.setPosition(finalEndPosition);
    line_.setPosition(finalStartPosition, finalEndPosition);

//    {
//        pivot_.setPosition({actualPosition.x, 0});
//    }

//    pivot_.render(window);
//    window.draw(line_);
    if (display)
    {
        pivot_.render(window);
//        window.draw(line_);
    }

    return {actualPosition, actualRotation};
}
