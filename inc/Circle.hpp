#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Shape.hpp>


namespace mt
{	
	class Circle : public mt::Shape
	{
		float m_r;
		sf::CircleShape shape;
		int m_vx_temp, m_vy_temp;
		float default_vx = 400, default_vy = 400;
		int stop_counter = 0;


	public: 
		Circle() = default;

		Circle(float x, float y, float r, float vx, float vy): mt::Shape()
		{	
			setup(x, y, r, vx, vy);
		}

		void touchEffect() {
			if (stop_counter <= 0) stop_counter = 15000;
		}

		void setup(float x, float y, float r, float vx, float vy) 
		{
			m_r = r;
			m_x = x;
			m_y = y;
			m_vx = vx;
			setVy(vy);

			shape.setRadius(m_r); 
			shape.setPosition(m_x, m_y);
			setColor();
		}

		void randomSetup(int board_w, int board_h) 
		{
			int r = rand() % 100 + 20;
			int x = rand() % (board_w - r - 1) + r + 1;
			int y = rand() % (board_h - r - 1) + r + 1;
			int vx = rand() % 200 + 100;
			int vy = rand() % 200 + 100;

			if (x < 0 || x + 2 * r > board_w)
				x = r;
			if (y < 0 || y + 2 * r > board_h)
				y = r;

			setup(x, y, r, vx, vy);
			setBoard(board_w, board_h);
		}

		void setColor() {
			int r = rand() % 255;
			int g = rand() % 255;
			int b = rand() % 255;
			int a = rand() % (255 - 160 + 1) + 160; // альфа канал от 160 до 255

			shape.setFillColor(sf::Color::Color(r, g, b, a));
		}

		void setVx(float vx) {

			if (vx > default_vx || vx < -default_vx) {
				std::cout << "Ѕрат, куда гонишь по горизонтали? —бавим до " << default_vx << std::endl;
				m_vx = default_vx;
			}
			else m_vx = vx;

		}

		void setVy(float vy) {
			if (vy > default_vy || vy < -default_vy) {
				std::cout << "Ѕрат, куда гонишь по вертикали? —бавим до " << default_vy << std::endl;
				m_vy = default_vy;
			}
			else m_vy = vy;
		}

		sf::CircleShape get()
		{
			return shape;
		}

		void move(float dt)
		{	
			if (stop_counter)
			{
				stop_counter--;
				setColor();
			}
			else 
			{
				m_x += m_vx * dt;
				m_y += m_vy * dt;
				shape.setPosition(m_x, m_y);
			}
				
		}

		bool isHorizontalTouch () 
		{
			return (m_x + 2 * m_r >= board_w || m_x <= 0);
		}

		bool isVerticalTouch()
		{
			return (m_y + 2 * m_r >= board_h || m_y <= 0);
		}
	};
}