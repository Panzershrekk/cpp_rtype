//
// Created by grodin on 15/01/18.
//

#include 	<iostream>
#include	<gameEngine/Mouse.hpp>
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

void MainMenu::playFunction(Window &win)
{
  std::cout << "Play" << std::endl;
}

void MainMenu::quitFunction(Window &win)
{
  win.close();
}

void MainMenu::update(Window &win)
{
  auto	fPlay = std::bind(&MainMenu::playFunction, this, std::placeholders::_1);
  auto	fQuit = std::bind(&MainMenu::quitFunction, this, std::placeholders::_1);

  this->_playButton.onClick(fPlay, win);
  this->_quitButton.onClick(fQuit, win);
}

void MainMenu::draw(Window &win)
{
  win.draw(this->_splashScreen);
  win.draw(this->_playButton);
  win.draw(this->_optionButton);
  win.draw(this->_quitButton);
  win.draw(this->_title);
}