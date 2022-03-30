//
// Created by Michael Lynch on 30/03/2022.
//

#include "CenteredCircle.h"

dop::CenteredCircle::CenteredCircle(float radius, const sf::Vector2f& origin)
    : circle_(radius)
{
    circle_.setOrigin({origin.x + radius, origin.y + radius});
}

void dop::CenteredCircle::setPosition(const sf::Vector2f &pos)
{
    circle_.setPosition(pos);
}

void dop::CenteredCircle::render(sf::RenderWindow &window)
{
    window.draw(circle_);
}

void dop::CenteredCircle::setColor(const sf::Color &color)
{
    circle_.setFillColor(color);
}

void dop::CenteredCircle::rotate(float i)
{
    circle_.setRotation(i);
}

