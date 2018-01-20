//
// Created by thomas on 15/01/18.
//

#ifndef CPP_RTYPE_PLAYER_HPP
#define CPP_RTYPE_PLAYER_HPP

#include <iostream>
#include <boost/serialization/access.hpp>
#include <common/network/core/Endpoint.hpp>
#include "Character.hpp"

class Player : public Character
{
private:
    friend class boost::serialization::access;
    int                             _score;
    std::string                     _name;
    Network::Core::Endpoint         _endpoint;

public:
    Player();
    Player(const std::string &);
    ~Player();
    int getScore() const;
    void setScore(int);
    void addScore(int);
    const Network::Core::Endpoint  &getEndpoint() const;

    void            setName(const std::string &name);
    const std::string     &getName() const;



    template <class Archive>
    void	serialize(Archive& ar, const unsigned int version)
    {
        ar & _score;
        ar & _name;
        ar & _endpoint;
    }
};

#endif //CPP_RTYPE_PLAYER_HPP
