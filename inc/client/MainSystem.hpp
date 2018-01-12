#ifndef CPP_RTYPE_MAINSYSTEM_HPP
#define CPP_RTYPE_MAINSYSTEM_HPP

#include <vector>
#include "ISystem.hpp"

class MainSystem
{
private:
  std::vector<ISystem> _vecSystem;
public:
 MainSystem();
  ~MainSystem();

  void update();
};

#endif //CPP_RTYPE_MAINSYSTEM_HPP