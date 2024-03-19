#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Shape.hpp>


namespace mt
{
	class Triangle : public mt::Shape
	{
		float m_w, m_h;
		sf::ConvexShape shape;

	public:
		Triangle() = default;

		Triangle(float x, float y, float w, float h, float vx, float vy) : mt::Shape()
		{
			setup(x, y, w, h, vx, vy);
		}

		void setup(float x, float y, float w, float h, float vx, float vy)
		{
			m_w = w;
			m_h = h;
			m_x = x;
			m_y = y;
			m_vx = vx;
			m_vy = vy;


			shape.setPosition(m_x, m_y);
			shape.setFillColor(sf::Color::Color(187, 32, 40, 255));
		}

		void randomSetup(int board_w, int board_h)
		{
			int x = rand() % 1000;
			int y = rand() % 100;
			int r = rand() & 100 + 1;
			int vx = rand() % 80 + 1;
			int vy = rand() % 80 + 1;

			if (x < 0 || x + 2 * r > board_w)
				x = r;
			if (y < 0 || y + 2 * r > board_h)
				y = r;

			// setup(x, y, r, vx, vy);
			setBoard(board_h, board_w);
		}

		sf::ConvexShape get()
		{
			return shape;
		}

		int touchBoard() {
			if (!board_h || !board_w) return 0;

			if (m_y + m_h >= board_h || m_y <= 0) return -1;
			if (m_x + m_w >= board_w || m_x <= 0) return 1;

			return 0;
		}
	};
}