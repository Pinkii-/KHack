#include "ObstacleManager.hpp"

void ObstacleManager::initObstacles() {
  obstacles.clear();
  maxTime = constant::maxTimeObstacles;
  minTime = constant::minTimeObstacles;
}

ObstacleManager::ObstacleManager(int initX, int initY) :
  initX(initX),
  initY(initY),
  timer(0)
{
  initObstacles();
}

void ObstacleManager::update(float deltaTime) {
  timer -= deltaTime;
  if (timer < 0) {
      int newObstacle = rand()%obstacle::qtt;
      obstacles.push_back(new Obstacle(static_cast<obstacle::obsType>(newObstacle), initX+300, initY));
      timer = minTime + (rand()%int(maxTime-minTime));
    }
  for (auto it = obstacles.begin(); it != obstacles.end();++it) {
      (*it)->update(deltaTime);
    }
  if (obstacles.size() > 0) {
      Obstacle* obs = (*obstacles.begin());
      if (obs->isOutOfWindow()) {
          delete obs;
          obstacles.erase(obstacles.begin());
        }
    }
}


void ObstacleManager::draw(sf::RenderWindow &window) {
  for (auto it = obstacles.begin(); it != obstacles.end();++it) {
      (*it)->draw(window);
    }
}
