#include "SFMLObject.hpp"

SFMLObject::SFMLObject(sf::RenderTarget& aRenderTarget)
  : mRenderTarget(aRenderTarget)
{

}

void 
SFMLObject::Draw()
{
  sf::CircleShape shape(100);
  shape.setFillColor(sf::Color::Green);
  shape.setPosition(getPosX(), getPosY());
  mRenderTarget.draw(shape);
}
