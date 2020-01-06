#include <iostream>
#include <memory>

#include "object.hpp"
#include "WindowManager.hpp"
#include "sfmlImp/SFMLWindowManager.hpp"
#include "sfmlImp/SFMLObject.hpp"

#include "box2d/box2d.h"
#include "basicStructs.hpp"

int main()
{
  std::cerr << "Game 1.0" << std::endl;

  Vec2d vec(2.0, 4.0);
  Vec2d vec2(1.0, 5.0);

  Vec2d vec3 = vec+vec2;
  std::cerr << "vec3: " << vec3.x << ", " << vec3.y << std::endl;

  SFMLWindowManager windowManager(640, 480);
  std::shared_ptr<Object> object1 = std::make_shared<SFMLObject>(0, 0, *windowManager.getTargetWindow().get());
  std::shared_ptr<Object> object2 = std::make_shared<SFMLObject>(200, 200, *windowManager.getTargetWindow().get());
  std::shared_ptr<Object> object3 = std::make_shared<SFMLObject>(400, 400, *windowManager.getTargetWindow().get());

  windowManager.addObject(object1);
  windowManager.addObject(object2);
  windowManager.addObject(object3);

  windowManager.run();

  return 0;
}