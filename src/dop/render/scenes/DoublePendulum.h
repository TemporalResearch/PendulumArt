//
// Created by Michael Lynch on 30/03/2022.
//

#pragma once

#include <dop/render/Scene.h>
#include <dop/render/shapes/CenteredCircle.h>
#include <dop/render/shapes/Line.h>

namespace dop
{
    class DoublePendulum: public dop::Scene
    {
    public:
        DoublePendulum(int rodMultiplier);

        void render(sf::RenderWindow &window) override;
    private:
        dop::CenteredCircle pivot_;
        dop::CenteredCircle firstEnd_;
        dop::CenteredCircle secondEnd_;

        float firstRotation_{0};
        float secondRotation_{0};

        int rodMultiplier_{1};

        dop::Line rod_;

        dop::Line secondRod_;
    };
}



