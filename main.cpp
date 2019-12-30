#include <iostream>
#include "SFML/Graphics.hpp"

#include "object.hpp"

int main()
{
  std::cerr << "Game 1.0" << std::endl;

  sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
          window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}