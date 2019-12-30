#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

namespace sf
{
  class RenderTarget;
};

class IDrawable
{
  public:
    virtual void Draw() = 0;
};

class IMovable
{
  public:
    virtual void Move() = 0;
};

class Object : public IDrawable, IMovable
{
  public:
    Object()
      : mPosX(0),
        mPosY(0)
    {}
    virtual void Move() override
    {
      mPosX += 0.01;
    }

    float getPosX() {return mPosX;}
    float getPosY() {return mPosY;}

  private:
    float mPosX;
    float mPosY;
};

class SFML_Object : public Object
{
  public:
    SFML_Object() = delete;
    SFML_Object(sf::RenderTarget& aRenderTarget);

    virtual void Draw() override;

  private:
    sf::RenderTarget& mRenderTarget;
};

#endif // __OBJECT_HPP__