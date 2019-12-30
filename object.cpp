#include "object.hpp"
#include "SFML/Graphics.hpp"

SFML_Object::SFML_Object(sf::RenderTarget& aRenderTarget)
  : mRenderTarget(aRenderTarget)
{

}

void 
SFML_Object::Draw()
{
  sf::CircleShape shape(100);
  shape.setFillColor(sf::Color::Green);
  shape.setPosition(getPosX(), getPosY());
  mRenderTarget.draw(shape);
}

