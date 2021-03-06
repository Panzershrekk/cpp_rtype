//
// Created by grodin on 15/01/18.
//

#ifndef 	CPP_RTYPE_MENUWINDOW_HPP_
# define 	CPP_RTYPE_MENUWINDOW_HPP_
# define	TITLE	"R-TYPE"

#include	<SFML/Graphics.hpp>
#include	<vector>
#include	<memory>
#include	<exception>
#include	<boost/asio.hpp>
#include	<boost/array.hpp>
#include	"MainMenu.hpp"
#include	"Window.hpp"
#include	"MenuState.hpp"
#include	"IMenu.hpp"
#include	"LoginMenu.hpp"
#include	"RoomListMenu.hpp"
#include	"LobbyMenu.hpp"
#include	"Image.hpp"

class MainMenu;


class MenuWindow
{
protected:
  TcpClient				*_client;
  MenuState 	_state;


private:
  std::shared_ptr<IMenu> _mainMenu = std::make_shared<MainMenu>(_state);
  std::shared_ptr<IMenu> _loginMenu = std::make_shared<LoginMenu>(_state);
  std::shared_ptr<IMenu> _roomListMenu = std::make_shared<RoomListMenu>(_state);
  std::shared_ptr<IMenu> _lobbyMenu = std::make_shared<LobbyMenu>(_state);

  std::vector<std::shared_ptr<IMenu>>	_vecMenu;
  Window	_win;



public:
    MenuWindow();
    ~MenuWindow();

    void start();
    void update(sf::Event &);

  void setClient(TcpClient *);
};

#endif /* !CPP_RTYPE_MENUWINDOW_HPP_ */
