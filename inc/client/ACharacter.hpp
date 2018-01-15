//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_ACHARACTER_HPP
#define CPP_RTYPE_ACHARACTER_HPP

class ACharacter
{
  public:
    ACharacter();
    ACharacter(int);
    void setHp(int);
    int getHp() const;

  protected:
    int _hp;
};

#endif //CPP_RTYPE_ACHARACTER_HPP
