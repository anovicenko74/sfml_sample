#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
	class Shape
	{
	public:
		float m_x = 0, m_y = 0;
		float m_vx, m_vy;
		float m_w, m_h;
		bool m_touching = false;
		// хочу иметь абстрактный sf::Shape (я хз как)
		// и чтобы унаследованные методы обращались к переопределенному полю shape в дочерних классах
		sf::CircleShape shape;

		float board_w;
		float board_h;

		sf::CircleShape get()
		{
			return shape;
		}

		virtual void randomSetup(int board_w, int board_h) {}
		virtual void move(float dt) {}

		bool checkTouchBoard() 
		{	
			if (!board_h || !board_w) return false;


			if (isHorizontalTouch())
			{
				setVx(-getVx());

				if (m_x <= 0) 
				{	
					setX(1);
					move(0);
				}
				else 
				{	
					setX(board_w - m_w - 1);
					move(0);
				}

				touchEffect();

				return true;
			}

			if (isVerticalTouch())
			{	
				std::cout << "vertical" << std::endl;
				setVy(-getVy());

				if (m_y <= 0)
				{
					setY(1);
					move(0);
				}
				else
				{
					setY(board_h - m_h - 1);
					move(0);
				}

				touchEffect();

				return true;
			}

			return false;
		}

		virtual void touchEffect() {};

		void setColor() {
			int r = rand() % 255;
			int g = rand() % 255;
			int b = rand() % 255;
			int a = rand() % (255 - 160 + 1) + 160; // альфа канал от 160 до 255

			shape.setFillColor(sf::Color::Color(r, g, b, a));
		}

		void setVx(float vx) {
			 m_vx = vx;
		}

		void setVy(float vy) {
			 m_vy = vy;
		}

		void setX(int x)
		{
			m_x = x;
		}

		void setY(int y)
		{	
			m_y = y;
		}

		float getVx() {
			return m_vx;
		}

		float getVy() {
			return m_vy;
		}

		void setBoard(float w, float h) {
			board_w = w;
			board_h = h;
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