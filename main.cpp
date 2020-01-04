#include <iostream>
#include "SFML/Graphics.hpp"

#include "object.hpp"
#include "sfmlImp/SFMLObject.hpp"

int main()
{
  std::cerr << "Game 1.0" << std::endl;

  sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
  
  SFMLObject o1(window);

  Signal<SFMLObject, void (SFMLObject::*)(int)> press_signal;
  press_signal.Connect(&o1, &SFMLObject::go);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
          window.close();
    }
    
    window.clear();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      press_signal(2);
    }
    o1.Draw();
    
    window.display();
  }

  return 0;
}