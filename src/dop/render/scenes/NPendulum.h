//
// Created by Michael Lynch on 30/03/2022.
//

#pragma once

#include <dop/render/Scene.h>
#include <dop/render/shapes/CenteredCircle.h>
#include <dop/render/shapes/Line.h>

namespace dop
{
    class NPendulum: public dop::Scene
    {
    public:

        explicit NPendulum(int noOfPivots, float rodMultiplier);

        void render(sf::RenderWindow &window) override;
    private:
        struct Rod
        {
            explicit Rod(int rodMultiplier);

            sf::Vector2f render(sf::RenderWindow &window, const sf::Vector2f &initialPosition, bool display);

            dop::CenteredCircle pivot_;
            dop::Line line_;

            float rotation_{};
            int rodMultiplier_{};
        };

        std::vector<Rod> pivots_;
    };
}



