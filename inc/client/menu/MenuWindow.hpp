//
// Created by grodin on 15/01/18.
//

#ifndef 	CPP_RTYPE_MENUWINDOW_HPP_
# define 	CPP_RTYPE_MENUWINDOW_HPP_
# define	TITLE	"MenuWindow"

#include	"IMenu.hpp"

class MainMenu;

class MenuWindow : public IMenu
{
  private:
    MenuState	_menuState;
    MainMenu	_mainMenu;
    Window	_win;

  public:
    MenuWindow();
    ~MenuWindow() override;

    void start() override;
    void update() override;
};

#endif /* !CPP_RTYPE_MENUWINDOW_HPP_ */
