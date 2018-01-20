//
// Created by grodin on 16/01/18.
//

#include	<iostream>
#include	<SFML/Window/Event.hpp>
#include	"LoginMenu.hpp"

LoginMenu::LoginMenu(MenuState & state) : _ip("", "../Triumph-wheels-rough.ttf", 255, 70),
			 _port("", "../Triumph-wheels-rough.ttf", 255, 220),
			 _name("", "../Triumph-wheels-rough.ttf", 255, 370),
			 _state(state)
{


  this->_whichBut = NONE;

  this->_sprites.emplace(std::make_pair("Back", Sprite("../assets/LoginMenu_Background.png")));
  this->_sprites.emplace(std::make_pair("IpAddress", Sprite("../assets/LoginMenu_Button_IP.png", 50, 100)));
  this->_sprites.emplace(std::make_pair("Port", Sprite("../assets/LoginMenu_Button_Port.png", 50, 250)));
  this->_sprites.emplace(std::make_pair("Name", Sprite("../assets/LoginMenu_Button_Name.png", 50, 400)));
  this->_sprites.emplace(std::make_pair("Start", Sprite("../assets/LoginMenu_Button_GO_KO.png", 1700, 900)));
  this->_sprites.emplace(std::make_pair("Return", Sprite("../assets/Menu_Button_Back.png", 25, 900)));

  _ip.setCharacterSize(80);
  _port.setCharacterSize(80);
  _name.setCharacterSize(80);

  this->_sprites.at("Return").setScale(0.5f, 0.5f);
}

LoginMenu::~LoginMenu()
= default;

void LoginMenu::start(Window &)
{
}

void LoginMenu::enterIP(Window &win, sf::Event &event)
{
  this->_whichBut = IPButton;
}

void LoginMenu::enterPort(Window &win, sf::Event &event)
{
  this->_whichBut = PortButton;
}

void LoginMenu::enterName(Window &win, sf::Event &event)
{
  this->_whichBut = NameButton;
}

void LoginMenu::playFunction(Window &win, sf::Event &event)
{
  this->_state = ERoomListMenu;
}

void LoginMenu::returnFunction(Window &win, sf::Event &event)
{
  this->_state = EMainMenu;
}

void LoginMenu::getSfLine(Text &text, sf::Event &event)
{
  std::string str = text.getString();

  if (event.type == sf::Event::TextEntered) {
    if (event.text.unicode == '\b') {
      if (!str.empty())
	str.erase(str.size() - 1, 1);
    }
    else
    	str += static_cast<char>(event.text.unicode);
    text.setString(str);
  }
}

void LoginMenu::update(Window &win, sf::Event &event)
{
  auto	fIp = std::bind(&LoginMenu::enterIP, this, std::placeholders::_1, std::placeholders::_2);
  auto	fPort = std::bind(&LoginMenu::enterPort, this, std::placeholders::_1, std::placeholders::_2);
  auto	fName = std::bind(&LoginMenu::enterName, this, std::placeholders::_1, std::placeholders::_2);
  auto	fGo = std::bind(&LoginMenu::playFunction, this, std::placeholders::_1, std::placeholders::_2);
  auto	fBack = std::bind(&LoginMenu::returnFunction, this, std::placeholders::_1, std::placeholders::_2);

  this->_sprites.at("IpAddress").onClick(fIp, win, event);
  this->_sprites.at("Port").onClick(fPort, win, event);
  this->_sprites.at("Name").onClick(fName, win, event);
  this->_sprites.at("Start").onClick(fGo, win, event);
  this->_sprites.at("Return").onClick(fBack, win, event);

  if (this->_whichBut == IPButton)
    getSfLine(this->_ip, event);
  if (this->_whichBut == PortButton)
    getSfLine(this->_port, event);
  if (this->_whichBut == NameButton)
    getSfLine(this->_name, event);
  if (event.type == sf::Event::Closed)
    win.close();
/*
  if (!this->_ip.getString().empty() && !this->_port.getString().empty()
      && !this->_port.getString().empty()) {
    this->_sprites.at("Start").setTexture("../assets/LoginMenu_Button_GO_OK.png");
  }
  */ //TODO Faire en sorte de check les string tapées
}

void LoginMenu::draw(Window &win)
{
  for(auto it : this->_sprites)
  {
    win.draw(it.second);
  }
  win.draw(this->_ip);
  win.draw(this->_port);
  win.draw(this->_name);
}
