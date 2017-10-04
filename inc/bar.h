#pragma once

#include <SFML/Graphics.hpp>

class Bar{
	public:
		Bar();
		Bar(sf::RenderWindow* p_window,
			int p_max = 0,
			int p_amount = 0);
		~Bar();

		void draw();

		void setMax(int p_num);
		int getMax();

		void setAmount(int p_num);
		int getAmount();

		void setPosition(sf::Vector2f p_pos);
		void move(sf::Vector2f p_vector);
		sf::Vector2f getPosition();

	private:
		sf::RenderWindow* _window;

		int _max;
		int _amount;

		sf::RectangleShape _background;
		sf::RectangleShape _fill;
		sf::RectangleShape _outline;
};
