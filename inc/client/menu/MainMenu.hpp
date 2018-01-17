//
// Created by grodin on 15/01/18.
//

#ifndef CPP_RTYPE_MAINMENU_HPP_
#define CPP_RTYPE_MAINMENU_HPP_

#include	"IMenu.hpp"
#include	"Sprite.hpp"

class Window;

class MainMenu : public IMenu
{
  private:
    Sprite	_splashScreen;
    Sprite	_playButton;
    Sprite	_optionButton;
    Sprite	_quitButton;
    Sprite	_title;

  public:
    MainMenu();
    ~MainMenu();

    void draw(Window &);
    void start(Window &);
    void update(Window &);

    void playFunction(Window &);
    void quitFunction(Window &);
};


#endif /* !CPP_RTYPE_MAINMENU_HPP_ */
