#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Shape.hpp>


namespace mt
{
	class Rectangle : public mt::Shape
	{
		float m_w, m_h;
		sf::RectangleShape shape;
		float default_vx = 4000, default_vy = 4000;


	public:
		Rectangle() = default;

		Rectangle(float x, float y, float w, float h, float vx, float vy) : mt::Shape()
		{
			setup(x, y, w, h, vx, vy);
		}

		void touchEffect() {
			std::cout << "Rectangle touch";
			setColor();
		}

		void setup(float x, float y, float w, float h, float vx, float vy)
		{	
			m_w = w;
			m_h = h;
			m_x = x;
			m_y = y;
			setVx(vx);
			setVy(vy);

			shape.setSize(sf::Vector2f(m_w, m_h));
			shape.setPosition(m_x, m_y);
			shape.setFillColor(sf::Color::Color(187, 32, 40, 255));
		}

		void randomSetup(int board_w, int board_h)
		{
			int w = rand() % 100 + 100;
			int h = rand() % 100 + 100;
			int x = rand() % (board_w - w - 1) + w + 1;
			int y = rand() % (board_h - h - 1) + h + 1;
			int vx = rand() % 200 + 100;
			int vy = rand() % 200 + 100;

			setBoard(board_w, board_h);
			setup(x, y, w, h, vx, vy);
			setColor();
		}

		void setColor() {
			int r = rand() % 255;
			int g = rand() % 255;
			int b = rand() % 255;
			int a = rand() % (255 - 160 + 1) + 160; // ����� ����� �� 160 �� 255

			shape.setFillColor(sf::Color::Color(r, g, b, a));
		}

		sf::RectangleShape get()
		{
			return shape;
		}
		
		void move(float dt)
		{
			m_x += m_vx * dt;
			m_y += m_vy * dt;

			shape.setPosition(m_x, m_y);
		}

		bool isHorizontalTouch()
		{
			return (m_x + m_w >= board_w || m_x <= 0);
		}

		bool isVerticalTouch()
		{
			return (m_y + m_h >= board_h || m_y <= 0);
		}
	};
}