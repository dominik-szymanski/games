#ifndef __BASIC_STRUCTS_HPP__
#define __BASIC_STRUCTS_HPP__

#include <iostream>

template<typename T>
struct Vec2
{
  public:
    Vec2()
    : x(0),
      y(0)
    {}

    Vec2(T aX, T aY)
    : x(aX)
    , y(aY)
    {}

    Vec2<T> operator+(const Vec2<T>& vec2d)
    {
      return Vec2<T>(x + vec2d.x, y + vec2d.y);
    }

    Vec2<T> operator-(const Vec2<T>& vec2d)
    {
      return Vec2<T>(x - vec2d.x, y - vec2d.y);
    }

    Vec2<T> operator*(double scalar)
    {
      return Vec2<T>(x * scalar, y * scalar);
    }
    
    Vec2<T> operator/(double scalar)
    {
      return Vec2<T>(x / scalar, y / scalar);
    }

    T x;
    T y;
};

typedef Vec2<double>  Vec2d;
typedef Vec2<float>   Vec2f;
typedef Vec2<int>     Vec2i;



#endif // __BASIC_STRUCTS_HPP__