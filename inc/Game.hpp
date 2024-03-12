#pragma once
#include <string>
#include <iostream>

namespace mt 
{
	class Game 
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Circle* m_c;
		int m_n;
		sf::RenderWindow m_window;

	public: 
		Game() = default;

		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void setup(int n) {
			m_n = n;

			// Создание окна
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			srand(time(0));


			m_c = new mt::Circle[m_n];

			for (int i = 0; i < n; i++) {
				int x = rand() % 1000;
				int y = rand() % 100;
				int r = rand() & 100 + 1;
				int vx = rand() % 80 + 1;
				int vy = rand() % 80 + 1;

				if (x < 0 || x + 2 * r > m_width)
					x = r;
				if (y < 0 || y + 2 * r > m_height)
					y = r;

				m_c[i].setup(x, y, r, vx, vy);
				m_c[i].setBoard(m_height, m_width);
			}

			
		}

		void lifeCycle() {
			sf::Clock clock;

			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				// Логика
				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				// Перемещение шарика
				for (int i = 0; i < m_n; i++) {
					m_c[i].move(dt);
				}

				for (int i = 0; i < m_n; i++) {
					std::cout << m_c[i].touchBoard();
					if (m_c[i].touchHorizontal()) {
						m_c[i].setVx(-m_c[i].getVx());
					} 

					if (m_c[i].touchVertical()) {
						m_c[i].setVy(-m_c[i].getVy());
					}
				}



				// Отображение
				m_window.clear();
				for (int i = 0; i < m_n; i++) {
					m_window.draw(m_c[i].get());
				}

				m_window.display();
			}
		}
	};
}