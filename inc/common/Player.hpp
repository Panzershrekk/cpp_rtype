//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_PLAYER_HPP
#define CPP_RTYPE_PLAYER_HPP

#include <iostream>
#include <boost/serialization/access.hpp>
#include "Character.hpp"

class Player : public Character
{
private:
    friend class boost::serialization::access;
    int             _score;
    std::string     _name;

public:
    Player();
    Player(const std::string &);
    ~Player();
    int getScore() const;
    void setScore(int);
    void addScore(int);

    void setName(const std::string &name);
    std::string getName() const;
};

#endif //CPP_RTYPE_PLAYER_HPP
