#pragma once
#include <string>
#include <iostream>
#include <Rectangle.hpp>
#include <Triangle.hpp>
namespace mt 
{
	class Game 
	{
		int m_width;
		int m_height;
		std::string m_capture;
		mt::Circle* m_c;
		mt::Rectangle* m_r;
		mt::Triangle* m_t;
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

			// Create Window
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);
			m_window.setFramerateLimit(60);

			srand(time(0));


			m_c = new mt::Circle[m_n];
			m_r = new mt::Rectangle[m_n];
			m_t = new mt::Triangle[m_n];
				
			// Create Shapes...
			for (int i = 0; i < n; i++) {
				m_c[i].randomSetup(m_width, m_height);
				m_r[i].randomSetup(m_width, m_height);
				m_t[i].randomSetup(m_width, m_height);
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

				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				// Move
				for (int i = 0; i < m_n; i++) {
					m_c[i].move(dt);
					m_r[i].move(dt);
					m_t[i].move(dt);
				}

				// Border touch logic
				for (int i = 0; i < m_n; i++) {
					m_c[i].checkTouchBoard();
					m_r[i].checkTouchBoard();
					m_t[i].checkTouchBoard();
				}

				// View
				m_window.clear();
				for (int i = 0; i < m_n; i++) {
					m_window.draw(m_c[i].get());
				    m_window.draw(m_r[i].get());
					m_window.draw(m_t[i].get());
				}

				m_window.display();
			}
		}
	};
}