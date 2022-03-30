//
// Created by Michael Lynch on 30/03/2022.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace dop
{
    class CenteredCircle
    {
    public:
        CenteredCircle(float radius, const sf::Vector2f& origin = sf::Vector2f{0, 0});

        void render(sf::RenderWindow& window);

        void setPosition(const sf::Vector2f &pos);

        void setColor(const sf::Color& color);

        void rotate(float i);

    private:
        sf::CircleShape circle_;
    };
}



