//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_PLAYER_HPP
#define CPP_RTYPE_PLAYER_HPP

#include "ACharacter.hpp"

class Player : public ACharacter
{
  public:
    Player();
    ~Player();
    int getScore() const;
    void setScore(int);
    void addScore(int);

  private:
    int _score;
};

#endif //CPP_RTYPE_PLAYER_HPP
