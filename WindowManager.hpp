#ifndef __WINDOW_MANAGER_HPP__
#define __WINDOW_MANAGER_HPP__

#include "vector"
#include "memory"
#include "algorithm"

#include "object.hpp"

typedef std::shared_ptr<Object> ObjectPtr;
typedef std::vector<ObjectPtr>  ObjectPtrs;

class WindowManager
{
  public:
    WindowManager(int windowWidth, int windowHeight)
    : mWindowWidth(windowWidth),
      mWindowHeight(windowHeight)
      {};

    virtual ~WindowManager() {};

    virtual void addObject(const ObjectPtr& object) = 0;

    virtual void run() = 0;

  private:
    int mWindowWidth;
    int mWindowHeight;
};

#endif // __WINDOW_MANAGER_HPP__