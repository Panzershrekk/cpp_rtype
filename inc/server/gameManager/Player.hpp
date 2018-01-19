//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_PLAYER_HPP
#define CPP_RTYPE_PLAYER_HPP

#include <iostream>
#include "Character.hpp"

class Player : public Character
{
  public:
    Player();
    Player(const std::string &);
    ~Player();
    int getScore() const;
    void setScore(int);
    void addScore(int);

    void setName(const std::string &name);
    std::string getName() const;

    void update();

  private:
    int _score;
    std::string _name;
};

#endif //CPP_RTYPE_PLAYER_HPP
