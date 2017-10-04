#include "app.h"

App::App()
{
	_clock_input.restart();
}

App::~App()
{}

int App::run()
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

		if(_clock_input.getElapsedTime().asMilliseconds()
			> INPUT_RATE)
		{
			_clock_input.restart();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sf::View view = window.getView();

		view.move(0, -SCREEN_MOVE_SPEED);

		window.setView(view);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sf::View view = window.getView();

		view.move(SCREEN_MOVE_SPEED, 0);

		window.setView(view);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sf::View view = window.getView();

		view.move(0, SCREEN_MOVE_SPEED);

		window.setView(view);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sf::View view = window.getView();

		view.move(-SCREEN_MOVE_SPEED, 0);

		window.setView(view);
	}
		}

	current_scene->update();
    }

    return 0;
}
