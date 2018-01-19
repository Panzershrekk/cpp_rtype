//
// Created by arthaox on 10/01/18.
//

#include		"Room.hpp"

Room::Room() {}

Room::Room(const int &size, const int &id) : _size(size), _id(id) {}

Room::~Room() {}

void	Room::join(const Player &player)
{
    this->_queue.push_back(player);
}

void	Room::leave(const Player &player)
{
    for (auto it = this->_queue.begin(); it != this->_queue.end(); it++)
    {
        if (it->getId() == player.getId())
            _queue.erase(it);
    }
}

void		Room::setSize(const int &size)
{
    this->_size = size;
}

void		Room::setId(const int &id)
{
    this->_id = id;
}

int		Room::getSize() const
{
    return(this->_size);
}

int		Room::getId() const
{
    return(this->_id);
}

std::vector<Player> Room::getPlayers() const
{
    return (this->_queue);
}