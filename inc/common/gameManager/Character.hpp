//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_ACHARACTER_HPP
#define CPP_RTYPE_ACHARACTER_HPP

#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>

#include <Physic.hpp>
#include "AEntity.hpp"

class Character : public AEntity
{
public:
    friend class boost::serialization::access;

protected:
    int _hp;

public:
    Character();
    Character(const int&);
    Character(const Character &);
    ~Character();
    void setHp(const int &);

    const int &getHp() const;

    template <class Archive>
    void	serialize(Archive& ar, const unsigned int version)
    {
        ar & boost::serialization::base_object<AEntity>(*this);
        ar & _hp;
    }
};

#endif //CPP_RTYPE_ACHARACTER_HPP
