#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{	
	class Circle 
	{
		float m_r;
		float m_x, m_y;
		float m_vx, m_vy;
		sf::CircleShape shape;

		float board_w;
		float board_h;

	public: 
		Circle() = default;

		Circle(float x, float y, float r, float vx, float vy)
		{
			setup(x, y, r, vx, vy);
		}

		void setup(float x, float y, float r, float vx, float vy) 
		{
			m_r = r;
			m_x = x;
			m_y = y;
			m_vx = vx;
			m_vy = vy;
			shape.setRadius(r);
			shape.setPosition(m_x, m_y);
			shape.setFillColor(sf::Color::Color(187, 32, 40, 255));
		}

		sf::CircleShape get() 
		{
			return shape;
		}

		void move(float dt) 
		{	
			m_x += m_vx*dt;
			m_y += m_vy*dt;
			shape.setPosition(m_x, m_y);
		}

		void setVx(float vx) {
			m_vx = vx;
		}

		void setVy(float vy) {
			m_vy = vy;
		}

		float getVx() {
			return m_vx;
		}

		float getVy() {
			return m_vy;
		}

		void setBoard(float h, float w) {
			board_h = h;
			board_w = w;
		}

		int touchBoard() {
			if (!board_h || !board_w) return 0;

			if (m_y + 2*m_r >= board_h || m_y <= 0) return -1;
			if (m_x + 2*m_r >= board_w || m_x <= 0) return 1;

			return 0;
		}

		bool touchHorizontal() {
			return touchBoard() == 1;
		}

		bool touchVertical() {
			return touchBoard() == -1;
		}
	};
}