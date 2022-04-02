//
// Created by Michael Lynch on 30/03/2022.
//

#pragma once

#include <dop/render/Scene.h>
#include <dop/render/shapes/CenteredCircle.h>
#include <dop/render/shapes/Line.h>

namespace dop
{
    class NPendulum: public dop::Scene
    {
    public:

        explicit NPendulum(std::vector<float> pivotRotationSpeeds,
                           const std::function<std::pair<sf::Vector2f, sf::Vector2f>(
                                   sf::Vector2f initialPosition, sf::Vector2f endPosition)>& rodPostProcess =
                           [](auto iP, auto eP) { return std::pair<sf::Vector2f, sf::Vector2f>{iP, eP}; });

        void render(sf::RenderWindow &window) override;
    private:
        struct Rod
        {
            explicit Rod(float rotationSpeed,
                         std::function<std::pair<sf::Vector2f, sf::Vector2f>(sf::Vector2f initialPosition,
                                                                             sf::Vector2f endPosition)> rodPostProcess);

            std::pair<sf::Vector2f, float>
            render(sf::RenderWindow &window, const sf::Vector2f &initialPosition, float initialRotation,
                   bool display);

            dop::CenteredCircle pivot_;
            dop::Line line_;

            float rotationSpeed_{0};
            float rotation_{};

            std::function<std::pair<sf::Vector2f, sf::Vector2f>(sf::Vector2f initialPosition,
                                                                sf::Vector2f endPosition)> rodPostProcess_;
        };

        std::vector<Rod> pivots_;
    };
}



