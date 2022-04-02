//
// Created by Michael Lynch on 30/03/2022.
//

#include "BouncingLine.h"
#include <dop/math/VectorUtils.hpp>
#include <dop/math/RotationMatrix.h>

#define ROD_LENGTH 0.15f

dop::BouncingLine::BouncingLine(std::vector<float> pivotRotationSpeeds)
    : nPendulum_{
        std::move(pivotRotationSpeeds),
        [this](sf::Vector2f startPos, sf::Vector2f endPos) {
            if (yGoingUp_)
            {
                yPos_ += 0.0001;
                if (yPos_ > 1)
                {
                    yGoingUp_ = false;
                }
            }
            else
            {
                yPos_ -= 0.0001;
                if (yPos_ < -1)
                {
                    yGoingUp_ = true;
                }
            }

            startPos = {startPos.x, yPos_};
            endPos = {endPos.x, yPos_};

            return std::pair<sf::Vector2f, sf::Vector2f>(startPos, endPos);
        }}
{
}

void dop::BouncingLine::render(sf::RenderWindow &window)
{
    nPendulum_.render(window);
}