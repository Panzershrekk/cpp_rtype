//
// Created by arthaox on 17/01/18.
//

#ifndef _EVENTMANAGER_HPP_
#define _EVENTMANAGER_HPP_

//#include	"Player.hpp";
//#include	"Bots.hpp";
//#include	"GameObject.hpp";
#include    "common/gameManager/Room.hpp";

#include	<vector>;

class EventManager
{
  private:
  public:
    EventManager();
    ~EventManager();

    void	RefreshPlayer(Room &room, Player &player);
    void	RefreshBot(Room &room, std::vector<Bots> &bots);
    void	RefreshEntities(Room &room, std::vector<GameObject> &entities);
    void	RefreshEndOfGame(Room &room);
    void	RefreshStartOfGame(Room &room);
    void	RefreshIsAlive(Player &player);
};

#endif //_EVENTMANAGER_HPP_
