#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <vector>

namespace sf
{
  class RenderTarget;
};

enum class Direction
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

class IDrawable
{
  public:
    virtual void Draw() = 0;
};

class IMovable
{
  public:
    virtual void move(Direction direction) = 0;
};

template<typename F, typename FUNC_TYPE>
class Signal
{
  public:
    void Connect(F* aConnector, FUNC_TYPE aMethod)
    {
      method = aMethod;

      connectors.push_back(aConnector);
    }
    template<typename ... ARGS>
    void operator()(ARGS... args)
    {
      for (auto connector : connectors)
      {
        (connector->*method)(args...);
      }
    }

  private:
    std::vector<F*>     connectors;
    FUNC_TYPE           method;
};

enum class Key
{
  UP = 0,
  DOWN,
  LEFT,
  RIGHT
};

class Object : public IDrawable, IMovable
{
  public:
    Object()
      : mPosX(0),
        mPosY(0)
    {}

    Object(int posX, int posY)
      : mPosX(posX),
        mPosY(posY)
    {}

    virtual void move(Direction direction) override
    {}

    virtual void onKeyPress(Key key) = 0;

    float getPosX() {return mPosX;}
    float getPosY() {return mPosY;}

    void setPosX(float PosX) {mPosX = PosX;}
    void setPosY(float PosY) {mPosY = PosY;}

  private:
    float mPosX;
    float mPosY;
};

#endif // __OBJECT_HPP__