#include <SFML/Graphics.hpp>

#include "testscene.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "WAR!");
    Scene* current_scene = new TestScene(&window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
	current_scene->update();
        window.display();
    }

    return 0;
}
