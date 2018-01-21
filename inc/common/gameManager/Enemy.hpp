//
// Created by thomas on 15/01/18.
//

#ifndef     _ENEMY__HPP_
#define     _ENEMY__HPP_

#include <boost/serialization/access.hpp>
#include "AIManager.hpp"
#include "Character.hpp"

class Enemy : public Character
{
private:
    friend class boost::serialization::access;
    AIManager   _ai;

public:
    Enemy();
    ~Enemy();
    Enemy(const Enemy &);

    void        randomizePosition();
    AIManager   getAI() const;

    void    update() override;

    template <class Archive>
    void	serialize(Archive& ar, const unsigned int version)
    {
    }
};

#endif      /* !_ENEMY__HPP_! */
