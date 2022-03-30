//
// Created by Michael Lynch on 30/03/2022.
//

#pragma once

#include <dop/render/Scene.h>
#include <dop/render/shapes/CenteredCircle.h>
#include <dop/render/shapes/Line.h>

namespace dop
{
    class SinglePendulum: public dop::Scene
    {
    public:
        SinglePendulum();

        void render(sf::RenderWindow &window) override;
    private:
        dop::CenteredCircle pivot_;
        dop::CenteredCircle end_;

        float endRotation_{0};

        dop::Line rod_;
    };
}



