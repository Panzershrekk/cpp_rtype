//
// Created by grodin on 15/01/18.
//

#ifndef CPP_RTYPE_MAINMENU_HPP_
#define CPP_RTYPE_MAINMENU_HPP_

#include	<Window.hpp>
#include	"Sprite.hpp"

class MainMenu
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
    void update(Window &);

    void playFunction(void);
};


#endif /* !CPP_RTYPE_MAINMENU_HPP_ */
