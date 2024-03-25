#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Shape.hpp>


namespace mt
{	
	class Circle : public mt::Shape
	{
		sf::CircleShape shape;
		int stop_counter = 0;


	public: 
		Circle() = default;

		Circle(float x, float y, float r, float vx, float vy): mt::Shape()
		{	
			setup(x, y, r, vx, vy);
		}

		void touchEffect() {
			if (stop_counter <= 0) stop_counter = 150;
		}

		void setup(float x, float y, float r, float vx, float vy) 
		{
			m_w = r * 2;
			m_h = r * 2;

			setX(x);
			setY(y);
			setVx(vx);
			setVy(vy);
			
			checkTouchBoard();

			shape.setRadius(r); 
			shape.setPosition(m_x, m_y);
			setColor();
		}

		void randomSetup(int board_w, int board_h) 
		{
			int r = rand() % 100 + 20;
			int x = rand() % (board_w - r - 1) + r + 1;
			int y = rand() % (board_h - r - 1) + r + 1;
			int vx = rand() % 100000000 + 200;
			int vy = rand() % 100000000 + 200;

			setBoard(board_w, board_h);
			setup(x, y, r, vx, vy);

		}

		void setColor() {
			int r = rand() % 255;
			int g = rand() % 255;
			int b = rand() % 255;
			int a = rand() % (255 - 160 + 1) + 160; // альфа канал от 160 до 255

			shape.setFillColor(sf::Color::Color(r, g, b, a));
		}

		sf::CircleShape get()
		{
			return shape;
		}

		void move(float dt)
		{	
		
				setX(m_x + m_vx * dt);
				setY(m_y + m_vy * dt);
				
				shape.setPosition(m_x, m_y);
		}
	};
}