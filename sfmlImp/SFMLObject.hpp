#ifndef __SFML_OBJECT_HPP__
#define __SFML_OBJECT_HPP__

#include "SFML/Graphics.hpp"
#include "../object.hpp"

class SFMLObject : public Object
{
  public:
    SFMLObject() = delete;
    SFMLObject(sf::RenderTarget& aRenderTarget);

    virtual void Draw() override;
    void go(int dx)
    {
      Move();
    }

  private:
    sf::RenderTarget& mRenderTarget;
};

#endif // __SFML_OBJECT_HPP__