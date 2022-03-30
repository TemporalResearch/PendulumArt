//
// Created by Michael Lynch on 30/03/2022.
//

#include "SinglePendulum.h"

void dop::SinglePendulum::render(sf::RenderWindow &window)
{
    pivot_.render(window);

    {
        endRotation_ += 0.1;
        end_.rotate(endRotation_);
        end_.render(window);
    }

    window.draw(rod_);
}

dop::SinglePendulum::SinglePendulum()
    : pivot_(0.04)
    , end_(0.04, {0, -0.5})
    , rod_{{0, 0}, {0, 0.5}}
{
    pivot_.setPosition({0, 0});
    pivot_.setColor(sf::Color::Black);

    end_.setPosition({0, 0});
    end_.setColor(sf::Color::Black);
}
