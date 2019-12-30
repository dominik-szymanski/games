#include "object.hpp"
#include "SFML/Graphics.hpp"

void 
SFML_Object::Draw()
{
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
}

void 
SFML_Object::Move()
{

}
