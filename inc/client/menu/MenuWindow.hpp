//
// Created by grodin on 15/01/18.
//

#ifndef 	CPP_RTYPE_MENUWINDOW_HPP_
# define 	CPP_RTYPE_MENUWINDOW_HPP_
# define	TITLE	"MenuWindow"

#include	<SFML/Graphics.hpp>
#include	"MainMenu.hpp"
#include	"Window.hpp"
#include	"MenuState.hpp"

class MainMenu;

class MenuWindow
{
  private:
    MenuState	_menuState;
    MainMenu	_mainMenu;
    Window	_win;

  public:
    MenuWindow();
    ~MenuWindow();

    void start();
    void update();
};

#endif /* !CPP_RTYPE_MENUWINDOW_HPP_ */
