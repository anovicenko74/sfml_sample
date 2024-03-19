#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
	class Shape
	{
	public:
		float m_x, m_y;
		float m_vx, m_vy;
		float default_vx = 4000, default_vy = 4000;
		bool m_touching = false;
		// хочу иметь абстрактный sf::Shape (€ хз как)
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
		virtual bool isHorizontalTouch() = 0 {}
		virtual bool isVerticalTouch() = 0 {}
		bool checkTouchBoard() 
		{	
			if (!board_h || !board_w) return false;

			bool frame_touch = false;

			if (isHorizontalTouch())
			{
				frame_touch = true;

				if (!m_touching)
				{
					setVx(-getVx());
				}
			}

			if (isVerticalTouch())
			{	
				frame_touch = true;

				if (!m_touching)
				{
					setVy(-getVy());
				}
			}

			if (frame_touch && !m_touching)
			{ 
				touchEffect();
				m_touching = true;
			};
			if (!frame_touch) m_touching = false;
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
	};
}