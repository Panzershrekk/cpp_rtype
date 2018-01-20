//
// Created by thomas on 10/01/18.
//

#ifndef CPP_RTYPE_POSITION2D_HPP
#define CPP_RTYPE_POSITION2D_HPP

#include <SFML/System/Vector2.hpp>

class Position2D
{
private:
    sf::Vector2<float>  _vector2;
    int               _x;
    int               _y;

public:
    Position2D();
    Position2D(int, int);
    Position2D(const Position2D&);

    Position2D operator+(const Position2D&) const;
    Position2D operator-(const Position2D&) const;
    Position2D operator+=(const Position2D&);
    Position2D operator-=(const Position2D&);


    bool operator==(const Position2D&) const;
    bool operator!=(const Position2D&) const;

    int getX() const;
    int getY() const;

    sf::Vector2<float> getVector() const;

    template <class Archive>
    void	serialize(Archive& ar, const unsigned int version)
    {
        ar & _x;
        ar & _y;
    }

};

#endif //CPP_RTYPE_POSITION2D_HPP
