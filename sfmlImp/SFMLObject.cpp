#include "SFMLObject.hpp"

SFMLObject::SFMLObject(int posX, int posY, sf::RenderTarget& aRenderTarget)
  : Object(posX, posY),
    mRenderTarget(aRenderTarget)
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

void 
SFMLObject::onKeyPress(Key key)
{
  switch (key)
  {
  case Key::UP:
    move(Direction::UP);
    break;

  case Key::DOWN:
    move(Direction::DOWN);
    break;

  case Key::LEFT:
    move(Direction::LEFT);
    break;

  case Key::RIGHT:
    move(Direction::RIGHT);
    break;

  default:
    break;
  }
}

void 
SFMLObject::move(Direction direction)
{
  switch (direction)
  {
  case Direction::UP:
    setPosY(getPosY() - 0.1);
    break;

  case Direction::DOWN:
    setPosY(getPosY() + 0.1);
    break;

  case Direction::LEFT:
    setPosX(getPosX() - 0.1);
    break;

  case Direction::RIGHT:
    setPosX(getPosX() + 0.1);
    break;

  default:
    break;
  }
}