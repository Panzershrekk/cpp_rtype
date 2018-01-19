//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_ENNEMY_HPP
#define CPP_RTYPE_ENNEMY_HPP

#include <AIManager.hpp>
#include "Character.hpp"

class Enemy : public Character
{
private:
    AIManager _ai;
public:
    Enemy();
    ~Enemy();

    void randomizePosition();
    AIManager getAI() const;

    void update();

    template <class Archive>
    void	serialize(Archive& ar, const unsigned int version)
    {
        ar & _ai;
    }
};

#endif //CPP_RTYPE_ENNEMY_HPP
