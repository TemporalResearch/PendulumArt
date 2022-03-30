//
// Created by Michael Lynch on 30/03/2022.
//

#include "SinglePendulum.h"
#include <dop/math/RotationMatrix.h>
#include <cmath>

void dop::SinglePendulum::render(sf::RenderWindow &window)
{
    pivot_.render(window);

    {
        endRotation_ += 0.1;

        auto endPosition =
                createRotationMatrix(endRotation_ * (M_PI / 180.0))
                .multiply({0, 0.25});
        end_.setPosition(endPosition);
        end_.render(window);
        rod_.setPosition({0, 0}, endPosition);
    }

    window.draw(rod_);
}

dop::SinglePendulum::SinglePendulum()
    : pivot_(0.02)
    , end_(0.02)
    , rod_{{0, 0}, {0, 0.25}}
{
    pivot_.setPosition({0, 0});
    pivot_.setColor(sf::Color::Black);

    end_.setPosition({0, 0});
    end_.setColor(sf::Color::Black);
}
