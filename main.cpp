#include <iostream>
#include "SFML/Graphics.hpp"

#include "object.hpp"

int main()
{
  std::cerr << "Game 1.0" << std::endl;

  sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
  
  SFML_Object o1(window);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
          window.close();
    }

    window.clear();
    
    o1.Draw();
    o1.Move();
    
    window.display();
  }

  return 0;
}