//
// Created by Michael Lynch on 30/03/2022.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace dop
{
    class Scene
    {
    public:
        virtual void render(sf::RenderWindow& window) = 0;
    };
}