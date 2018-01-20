//
// Created by thomas on 10/01/18.
//

#ifndef CPP_RTYPE_PHYSIC_HPP
#define CPP_RTYPE_PHYSIC_HPP

#include <ostream>
#include <iosfwd>

class Physic
{
private:
    int _gravity;
    unsigned int _speed;
    unsigned int _rotateSpeed;

public:
    Physic();
    ~Physic();
    Physic(int, unsigned, unsigned);

    void setGravity(int);
    void setSpeed(unsigned);
    void setRotateSpeed(unsigned);

    int getGravity() const;
    unsigned int getSpeed() const;
    unsigned int getRotateSpeed() const;

    template <class Archive>
    void	serialize(Archive& ar, const unsigned int version)
    {
        ar & _gravity;
        ar & _speed;
        ar & _rotateSpeed;
    }
};

std::ostream& operator<< (std::ostream& stream, const Physic& physic);


#endif //CPP_RTYPE_PHYSIC_HPP
