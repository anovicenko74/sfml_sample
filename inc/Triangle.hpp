#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Shape.hpp>


namespace mt
{
	class Triangle : public mt::Shape
	{
		sf::ConvexShape shape;
		int anglesCount = 3;

	public:
		Triangle() = default;

		Triangle(float x, float y, float size, float vx, float vy) : mt::Shape()
		{
			setup(x, y, size, vx, vy);
		}

		void setup(float x, float y, int size, float vx, float vy)
		{
			m_w = size;
			m_h = size;
			setX(x);
			setY(y);
			setVy(vy);
			setVx(vx);

			checkTouchBoard();

			shape.setPosition(m_x, m_y);

			shape.setPointCount(3);
			shape.setPoint(0, sf::Vector2f(30, 0));
			shape.setPoint(1, sf::Vector2f(60, 60));
			shape.setPoint(2, sf::Vector2f(0, 60));

			setColor();
		}

		void randomSetup(int board_w, int board_h)
		{
			int size = rand() % (180 - 60 + 1) + 60; // размер от 60 до 180
			int x = rand() % (board_w - size - 1) + size + 1;
			int y = rand() % (board_h - size - 1) + size + 1;
			int vx = rand() % 100 + 100;
			int vy = rand() % 100 + 100;
			

			setup(x, y, size, vx, vy);
			setBoard(board_w, board_h);
		}

		void touchEffect() {
			setColor();

			anglesCount++;
			if (anglesCount == 11) anglesCount = 3;

			float k_w = m_w / 60;
			float k_h = m_h / 60;

			if (anglesCount == 3)
			{
				shape.setPointCount(3);
				shape.setPoint(0, sf::Vector2f(30*k_w, 0*k_h));
				shape.setPoint(1, sf::Vector2f(60*k_w, 60 * k_h));
				shape.setPoint(2, sf::Vector2f(0*k_w, 60 * k_h));
			}

			if (anglesCount == 4) 
			{
				shape.setPointCount(4);
				shape.setPoint(0, sf::Vector2f(0*k_w, 0 * k_h));
				shape.setPoint(1, sf::Vector2f(60 * k_w, 00 * k_h));
				shape.setPoint(2, sf::Vector2f(60 * k_w, 60 * k_h));
				shape.setPoint(3, sf::Vector2f(0 * k_w, 60 * k_h));
			}

			if (anglesCount == 5)
			{
				shape.setPointCount(5);
				shape.setPoint(0, sf::Vector2f(30 * k_w, 0 * k_h));
				shape.setPoint(1, sf::Vector2f(60 * k_w, 30*k_h));
				shape.setPoint(2, sf::Vector2f(40 * k_w, 60 * k_h));
				shape.setPoint(3, sf::Vector2f(20 * k_w, 60 * k_h));
				shape.setPoint(4, sf::Vector2f(0 * k_w, 30 * k_h));
			}

			if (anglesCount == 6)
			{
				shape.setPointCount(6);
				shape.setPoint(0, sf::Vector2f(20 * k_w, 0 * k_h));
				shape.setPoint(1, sf::Vector2f(40 * k_w, 0 * k_h));
				shape.setPoint(2, sf::Vector2f(60 * k_w, 30 * k_h));
				shape.setPoint(3, sf::Vector2f(40 * k_w, 60 * k_h));
				shape.setPoint(4, sf::Vector2f(20 * k_w, 60 * k_h));
				shape.setPoint(5, sf::Vector2f(0 * k_w, 30 * k_h));
			}

			if (anglesCount == 7)
			{
				shape.setPointCount(7);
				shape.setPoint(0, sf::Vector2f(30 * k_w, 0 * k_h));
				shape.setPoint(1, sf::Vector2f(50 * k_w, 10 * k_h));
				shape.setPoint(2, sf::Vector2f(60 * k_w, 30 * k_h));
				shape.setPoint(3, sf::Vector2f(40 * k_w, 60 * k_h));
				shape.setPoint(4, sf::Vector2f(20 * k_w, 60 * k_h));
				shape.setPoint(5, sf::Vector2f(0 * k_w, 30 * k_h));
				shape.setPoint(6, sf::Vector2f(10 * k_w, 10 * k_h));
			}

			if (anglesCount == 8)
			{
				shape.setPointCount(8);
				shape.setPoint(0, sf::Vector2f(20 * k_w, 0 * k_h));
				shape.setPoint(1, sf::Vector2f(40 * k_w, 0 * k_h));
				shape.setPoint(2, sf::Vector2f(60 * k_w, 20 * k_h));
				shape.setPoint(3, sf::Vector2f(60 * k_w, 40 * k_h));
				shape.setPoint(4, sf::Vector2f(40 * k_w, 60 * k_h));
				shape.setPoint(5, sf::Vector2f(20 * k_w, 60 * k_h));
				shape.setPoint(6, sf::Vector2f(0 * k_w, 40 * k_h));
				shape.setPoint(7, sf::Vector2f(0 * k_w, 20 * k_h));
			}

			if (anglesCount == 9)
			{
				shape.setPointCount(9);
				shape.setPoint(0, sf::Vector2f(30 * k_w, 0 * k_h));
				shape.setPoint(1, sf::Vector2f(50 * k_w, 10 * k_h));
				shape.setPoint(2, sf::Vector2f(60 * k_w, 30 * k_h));
				shape.setPoint(3, sf::Vector2f(50 * k_w, 50 * k_h));
				shape.setPoint(4, sf::Vector2f(40 * k_w, 60 * k_h));
				shape.setPoint(5, sf::Vector2f(20 * k_w, 60 * k_h));
				shape.setPoint(6, sf::Vector2f(10 * k_w, 50 * k_h));
				shape.setPoint(7, sf::Vector2f(0 * k_w, 30 * k_h));
				shape.setPoint(8, sf::Vector2f(10 * k_w, 10 * k_h));
			}

			if (anglesCount == 10)
			{
				shape.setPointCount(10);
				shape.setPoint(0, sf::Vector2f(20 * k_w, 0 * k_h));
				shape.setPoint(1, sf::Vector2f(40 * k_w, 0 * k_h));
				shape.setPoint(2, sf::Vector2f(50 * k_w, 10 * k_h));
				shape.setPoint(3, sf::Vector2f(60 * k_w, 30 * k_h));
				shape.setPoint(4, sf::Vector2f(50 * k_w, 50 * k_h));
				shape.setPoint(5, sf::Vector2f(40 * k_w, 60 * k_h));
				shape.setPoint(6, sf::Vector2f(20 * k_w, 60 * k_h));
				shape.setPoint(7, sf::Vector2f(10 * k_w, 50 * k_h));
				shape.setPoint(8, sf::Vector2f(0 * k_w, 30 * k_h));
				shape.setPoint(9, sf::Vector2f(10 * k_w, 10 * k_h));
			}
			
		}

		

		void setColor() {
			int r = rand() % 255;
			int g = rand() % 255;
			int b = rand() % 255;
			int a = rand() % (255 - 160 + 1) + 160; // альфа канал от 160 до 255

			shape.setFillColor(sf::Color::Color(r, g, b, a));
		}

		sf::ConvexShape get()
		{
			return shape;
		}

		void move(float dt)
		{
			m_x += m_vx * dt;
			m_y += m_vy * dt;
			shape.setPosition(m_x, m_y);
		}
	};
}