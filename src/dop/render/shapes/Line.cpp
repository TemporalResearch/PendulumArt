//
// Created by Michael Lynch on 13/09/2021.
//

#include "Line.h"

dop::Line::Line(sf::Vector2f start, sf::Vector2f end, sf::Color color)
    : _lineRenderable(sf::LineStrip, 2)
{
    _lineRenderable[0].position = start;
    _lineRenderable[0].color = color;
    _lineRenderable[1].position = end;
    _lineRenderable[1].color = color;
}

dop::Line::Line()
    : dop::Line({0, 0}, {0, 0})
{

}

void dop::Line::setPosition(sf::Vector2f start, sf::Vector2f end)
{
    _lineRenderable[0].position = start;
    _lineRenderable[1].position = end;
}

void dop::Line::setColor(sf::Color color)
{
    _lineRenderable[0].color = color;
    _lineRenderable[1].color = color;
}

void dop::Line::setRotation()
{
}
