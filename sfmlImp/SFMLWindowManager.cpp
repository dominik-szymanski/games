#include "SFMLWindowManager.hpp"

SFMLWindowManager::SFMLWindowManager(int windowWidth, int windowHeight)
  : WindowManager(windowWidth, windowHeight),
    mWindow(std::make_shared<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "Game 1.0"))
{

}

void
SFMLWindowManager::addObject(const ObjectPtr& object)
{
  mObjects.push_back(object);
  mPressSignal.Connect(object.get(), &Object::onKeyPress);
}

void
SFMLWindowManager::requestPressedKeys()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    mPressSignal(Key::LEFT);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    mPressSignal(Key::RIGHT);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    mPressSignal(Key::UP);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    mPressSignal(Key::DOWN);
  }
}

void 
SFMLWindowManager::drwaObjects()
{
  std::for_each(mObjects.begin(), mObjects.end(),
  [](ObjectPtr& object)
  {
    object->Draw();
  });
}

void
SFMLWindowManager::run()
{      
  while (mWindow->isOpen())
  {
    sf::Event event;
    while (mWindow->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
          mWindow->close();
    }
    
    mWindow->clear();
    
    requestPressedKeys();
    drwaObjects();
    
    mWindow->display();
  }
}