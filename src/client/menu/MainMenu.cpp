//
// Created by grodin on 15/01/18.
//

#include 	<iostream>
#include	"Mouse.hpp"
#include	"MainMenu.hpp"

MainMenu::MainMenu() :
  _splashScreen("../assets/MainMenu_Background.png"),
  _playButton("../assets/MainMenu_Button_Play.png", 1700, 450),
  _optionButton("../assets/MainMenu_Button_Options.png", 1700, 575),
  _quitButton("../assets/MainMenu_Button_Quit.png", 1700, 700),
  _title("../assets/MainMenu_Title.png", 200, 100)
{
  this->_title.setScale(3, 3);
}

MainMenu::~MainMenu()
{
}

void MainMenu::playFunction(Window &win, sf::Event &)
{
  std::cout << "Play" << std::endl;
}

void MainMenu::quitFunction(Window &win, sf::Event &)
{
  win.close();
}

void MainMenu::update(Window &win, sf::Event &event)
{
  auto	fPlay = std::bind(&MainMenu::playFunction, this, std::placeholders::_1, std::placeholders::_2);
  auto	fQuit = std::bind(&MainMenu::quitFunction, this, std::placeholders::_1, std::placeholders::_2);

  this->_playButton.onClick(fPlay, win, event);
  this->_quitButton.onClick(fQuit, win, event);
}

void MainMenu::start(Window &win)
{
}

void MainMenu::draw(Window &win)
{
  win.draw(this->_splashScreen);
  win.draw(this->_playButton);
  win.draw(this->_optionButton);
  win.draw(this->_quitButton);
  win.draw(this->_title);
}