//
// Created by grodin on 15/01/18.
//

#include 	<iostream>
#include <SFML/Window/Event.hpp>
#include	"Mouse.hpp"
#include	"MainMenu.hpp"

MainMenu::MainMenu(MenuState &state) :
_splashScreen("../assets/MainMenu_Background.png"),
  _soloButton("../assets/MainMenu_Button_Single.png", 1600, 325),
  _playButton("../assets/MainMenu_Button_Multi.png", 1600, 450),
  _optionButton("../assets/MainMenu_Button_Options.png", 1700, 575),
  _quitButton("../assets/MainMenu_Button_Quit.png", 1700, 700),
  _title("../assets/MainMenu_Title.png", 200, 100),
_state(state)
{
  this->_title.setScale(3, 3);
}

MainMenu::~MainMenu()
{
}

void MainMenu::playMultiFunction(Window &win, sf::Event &)
{
  _state = ELoginMenu;
}

void MainMenu::playSoloFunction(Window &win, sf::Event &)
{
  std::cout << "Play Solo" << std::endl;
}

void MainMenu::quitFunction(Window &win, sf::Event &)
{
  win.close();
}

void MainMenu::update(Window &win, sf::Event &event)
{
  auto	fPlay = std::bind(&MainMenu::playMultiFunction, this, std::placeholders::_1, std::placeholders::_2);
  auto	fPlaySolo = std::bind(&MainMenu::playSoloFunction, this, std::placeholders::_1, std::placeholders::_2);
  auto	fQuit = std::bind(&MainMenu::quitFunction, this, std::placeholders::_1, std::placeholders::_2);

  this->_playButton.onClick(fPlay, win, event);
  this->_soloButton.onClick(fPlaySolo, win, event);
  this->_quitButton.onClick(fQuit, win, event);

  if (event.type == sf::Event::Closed)
    win.close();
}

void MainMenu::start(Window &win)
{
}

void MainMenu::draw(Window &win)
{
  win.draw(this->_splashScreen);
  win.draw(this->_playButton);
  win.draw(this->_soloButton);
  win.draw(this->_optionButton);
  win.draw(this->_quitButton);
  win.draw(this->_title);
}

