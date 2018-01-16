//
// Created by grodin on 15/01/18.
//

#ifndef 	CPP_RTYPE_MENUWINDOW_HPP_
# define 	CPP_RTYPE_MENUWINDOW_HPP_
# define	TITLE	"MenuWindow"

#include	<SFML/Graphics.hpp>
#include	<unordered_map>
#include	"MainMenu.hpp"
#include	"Window.hpp"
#include	"MenuState.hpp"
#include	"IMenu.hpp"

class MainMenu;

class MenuWindow
{
private:
  IMenu		_mainMenu;
  Window	_win;
  std::unordered_map<int, IMenu>	_state;

  public:
    MenuWindow();
    ~MenuWindow();

    void start();
    void update();
};

#endif /* !CPP_RTYPE_MENUWINDOW_HPP_ */
