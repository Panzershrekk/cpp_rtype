#include "MainSystem.hpp"

MainSystem::MainSystem()
{

}

MainSystem::~MainSystem()
{

}

void MainSystem::update()
{
  for (auto &system : _vecSystem)
    system.update();
}
