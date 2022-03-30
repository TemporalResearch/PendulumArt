//
// Created by Michael Lynch on 30/03/2022.
//

#include <logging.h>
#include <SFML/Graphics.hpp>

#include <dop/render/scenes/SinglePendulum.h>
#include "dop/render/scenes/DoublePendulum.h"
#include "dop/render/scenes/NPendulum.h"

int main()
{
    INFO_LOG("Double Pendulum Viewer");

    sf::RenderWindow window(sf::VideoMode(2000, 2000), "Double Pendulum");
    window.setView(sf::View(sf::FloatRect(
            {-1, -1},
            {2, 2})));

    dop::NPendulum pendulum(5, 10);

//    window.clear(sf::Color::Green);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        pendulum.render(window);

        window.display();
    }
}