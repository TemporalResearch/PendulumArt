//
// Created by Michael Lynch on 13/09/2021.
//

#include "Line.h"

dop::Line::Line(sf::Vector2f start, sf::Vector2f end, sf::Color color)
    : lineRenderable_(sf::LineStrip, 2)
{
    lineRenderable_[0].position = start;
    lineRenderable_[0].color = color;
    lineRenderable_[1].position = end;
    lineRenderable_[1].color = color;

}

dop::Line::Line()
    : dop::Line({0, 0}, {0, 0})
{

}

void dop::Line::setPosition(sf::Vector2f start, sf::Vector2f end)
{
    lineRenderable_[0].position = start;
    lineRenderable_[1].position = end;
}

void dop::Line::setColor(sf::Color color)
{
    lineRenderable_[0].color = color;
    lineRenderable_[1].color = color;
}
