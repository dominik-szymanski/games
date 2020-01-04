#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <vector>

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

#endif // __OBJECT_HPP__