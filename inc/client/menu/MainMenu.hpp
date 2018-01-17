//
// Created by grodin on 15/01/18.
//

#ifndef CPP_RTYPE_MAINMENU_HPP_
#define CPP_RTYPE_MAINMENU_HPP_

#include	"IMenu.hpp"
#include	"Sprite.hpp"
#include	"MenuState.hpp"

class Window;

class MainMenu : public IMenu
{
  private:
    Sprite	_splashScreen;
    Sprite	_playButton;
    Sprite	_optionButton;
    Sprite	_quitButton;
    Sprite	_title;
  MenuState	&_state;

  public:
  explicit MainMenu(MenuState &);
    ~MainMenu();

    void draw(Window &);
    void start(Window &);
    void update(Window &);

    void playFunction(Window &);
    void quitFunction(Window &);
};


#endif /* !CPP_RTYPE_MAINMENU_HPP_ */
