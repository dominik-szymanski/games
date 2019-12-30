#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

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
  
};

class SFML_Object : public Object
{
  public:
    virtual void Draw() override;
    virtual void Move() override;
};

#endif // __OBJECT_HPP__