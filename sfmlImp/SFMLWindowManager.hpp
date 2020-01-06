#ifndef __SFML_WINDOW_MANAGER_HPP__
#define __SFML_WINDOW_MANAGER_HPP__

#include "vector"
#include "memory"
#include "algorithm"

#include "SFML/Graphics.hpp"

#include "../WindowManager.hpp"
#include "SFMLObject.hpp"

class SFMLWindowManager : public WindowManager
{
  public:
    SFMLWindowManager(int windowWidth, int windowHeight);
    virtual ~SFMLWindowManager() {};

    virtual void addObject(const ObjectPtr& object) override;

    virtual void run() override;

    std::shared_ptr<sf::RenderWindow> getTargetWindow() {return mWindow;}

  private:
    void requestPressedKeys();
    void drwaObjects();

    Signal<Object, void (Object::*)(Key)> mPressSignal;
    std::shared_ptr<sf::RenderWindow>           mWindow;
    ObjectPtrs                                  mObjects;  
};

#endif // __SFML_WINDOW_MANAGER_HPP__