#ifndef __SFML_OBJECT_HPP__
#define __SFML_OBJECT_HPP__

#include "SFML/Graphics.hpp"
#include "../object.hpp"

class SFMLObject : public Object
{
  public:
    SFMLObject() = delete;
    SFMLObject(int posX, int posY, sf::RenderTarget& aRenderTarget);

    virtual void Draw() override;
    virtual void move(Direction direction) override;
    virtual void onKeyPress(Key key) override;

  private:
    sf::RenderTarget& mRenderTarget;
};

#endif // __SFML_OBJECT_HPP__