//
// Created by Michael Lynch on 30/03/2022.
//

#pragma once

#include <dop/render/Scene.h>
#include <dop/render/shapes/CenteredCircle.h>
#include <dop/render/shapes/Line.h>
#include <dop/render/scenes/NPendulum.h>

namespace dop
{
    class BouncingLine: public dop::Scene
    {
    public:

        explicit BouncingLine(std::vector<float> pivotRotationSpeeds);

        void render(sf::RenderWindow &window) override;
    private:
        bool yGoingUp_{false};
        float yPos_{-1};
        NPendulum nPendulum_;
    };
}



