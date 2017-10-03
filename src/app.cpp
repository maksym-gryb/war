#include "app.h"

App::App()
{
	_window = new sf::RenderWindow(sf::VideoMode(200, 200), "WAR!");
	_current_scene = new TestScene(_window);
}

App::~App()
{}

int App::run()
{
    while (_window->isOpen())
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window->close();
        }

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sf::View view = _window->getView();

		view.move(0, -0.1);

		_window->setView(view);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sf::View view = _window->getView();

		view.move(0.1, 0);

		_window->setView(view);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sf::View view = _window->getView();

		view.move(0, 0.1);

		_window->setView(view);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sf::View view = _window->getView();

		view.move(-0.1, 0);

		_window->setView(view);
	}

	_current_scene->update();
    }

    return 0;
}
