//
// Created by Michael Lynch on 13/09/2021.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace dop
{
    class Line
    {
    public:
        Line(sf::Vector2f start, sf::Vector2f end, sf::Color color = sf::Color::White);
        Line();

        void setPosition(sf::Vector2f start, sf::Vector2f end);
        void setColor(sf::Color color);

        void setRotation(float rotation);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
        operator sf::VertexArray()
        {
            return _lineRenderable;
        }
#pragma clang diagnostic pop

    private:
        sf::VertexArray _lineRenderable;
    };
}
