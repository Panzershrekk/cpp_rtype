//
// Created by grodin on 15/01/18.
//

#ifndef 	CPP_RTYPE_MENUWINDOW_HPP_
# define 	CPP_RTYPE_MENUWINDOW_HPP_
# define	TITLE	"MenuWindow"

#include	<SFML/Graphics.hpp>
#include	<vector>
#include	<memory>
#include	"MainMenu.hpp"
#include	"Window.hpp"
#include	"MenuState.hpp"
#include	"IMenu.hpp"
#include	"LoginMenu.hpp"

class MainMenu;

class MenuWindow
{
private:
  std::shared_ptr<IMenu> _mainMenu = std::make_shared<MainMenu>();
  std::shared_ptr<IMenu> _loginMenu = std::make_shared<LoginMenu>();

  Window	_win;
  std::vector<std::shared_ptr<IMenu>> _vec;
  //std::unordered_map<int, std::shared_ptr<IMenu>>	_state;

  public:
    MenuWindow();
    ~MenuWindow();

    void start();
    void update();
};

#endif /* !CPP_RTYPE_MENUWINDOW_HPP_ */
