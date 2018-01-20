//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_LOBBYMENU_HPP_
#define CPP_RTYPE_LOBBYMENU_HPP_

#include "IMenu.hpp"
#include "ItemLobbyMenu.hpp"
#include "TcpClient.hpp"

class LobbyMenu : public IMenu
{
  private:
  MenuState 	&_state;
  Sprite	_back;
  Sprite	_return;
  TcpClient	*_client;

  std::vector<std::shared_ptr<ItemLobbyMenu>>	_players;

public:
    explicit LobbyMenu(MenuState & ,TcpClient *);
    ~LobbyMenu() override;

    void start(Window &) override;
    void draw(Window &) override;
    void update(Window &, sf::Event &) override;

    void drawItems(Window &, ItemLobbyMenu &);
    void setActivePlayers(int);

  void returnFunction(Window &, sf::Event &);
};

#endif /* !CPP_RTYPE_LOBBYMENU_HPP_ */
