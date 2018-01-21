//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_PROJECTILE_HPP
#define CPP_RTYPE_PROJECTILE_HPP

#include <AIManager.hpp>
#include <boost/serialization/base_object.hpp>
#include "AEntity.hpp"

class Projectile : public AEntity
{
  private:
   AIManager _ai;
public:
  explicit Projectile();
  ~Projectile();

  void update();

  template <class Archive>
  void	serialize(Archive& ar, const unsigned int version)
  {
    ar & boost::serialization::base_object<AEntity>(*this);
  }
};

#endif //CPP_RTYPE_PROJECTILE_HPP