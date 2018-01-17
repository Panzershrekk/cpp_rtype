//
// Created by grodin on 16/01/18.
//

#include	<iostream>
#include	<SFML/Window/Event.hpp>
#include	"LoginMenu.hpp"

<<<<<<< HEAD
LoginMenu::LoginMenu() : _ip("", "../Triumph-wheels-rough.ttf", 255, 70),
			 _port("", "../Triumph-wheels-rough.ttf", 255, 220),
			 _name("", "../Triumph-wheels-rough.ttf", 255, 370),
			 _ipText(),
			 _portText(),
			 _nameText()
=======
LoginMenu::LoginMenu(MenuState & state) : _state(state)
>>>>>>> Menu
{
  this->_sprites.emplace(std::make_pair("Back", Sprite("../assets/LoginMenu_Background.png")));
  this->_sprites.emplace(std::make_pair("IpAddress", Sprite("../assets/LoginMenu_Button_IP.png", 50, 100)));
  this->_sprites.emplace(std::make_pair("Port", Sprite("../assets/LoginMenu_Button_Port.png", 50, 250)));
  this->_sprites.emplace(std::make_pair("Name", Sprite("../assets/LoginMenu_Button_Name.png", 50, 400)));

  _ip.setScale(3, 3);
  _port.setScale(3, 3);
  _name.setScale(3, 3);
}

LoginMenu::~LoginMenu()
= default;

void LoginMenu::start(Window &)
{
}

void LoginMenu::enterIP(Window &win, sf::Event &event)
{
  this->_isIPCliked = true;
  this->_isPortCliked = false;
  this->_isNameCliked = false;
}

void LoginMenu::enterPort(Window &win, sf::Event &event)
{
  this->_isIPCliked = false;
  this->_isNameCliked = false;
  this->_isPortCliked = true;
}

void LoginMenu::enterName(Window &win, sf::Event &event)
{
  this->_isIPCliked = false;
  this->_isPortCliked = false;
  this->_isNameCliked = true;
}

void LoginMenu::update(Window &win, sf::Event &event)
{
  auto	fIp = std::bind(&LoginMenu::enterIP, this, std::placeholders::_1, std::placeholders::_2);
  auto	fPort = std::bind(&LoginMenu::enterPort, this, std::placeholders::_1, std::placeholders::_2);
  auto	fName = std::bind(&LoginMenu::enterName, this, std::placeholders::_1, std::placeholders::_2);

  this->_sprites.at("IpAddress").onClick(fIp, win, event);
  this->_sprites.at("Port").onClick(fPort, win, event);
  this->_sprites.at("Name").onClick(fName, win, event);

  if (this->_isIPCliked) {
    if (event.type == sf::Event::TextEntered) {
      this->_ipText += static_cast<char>(event.text.unicode);
      this->_ip.setString(this->_ipText);
    }
  }
  if (this->_isPortCliked) {
    if (event.type == sf::Event::TextEntered) {
      this->_portText += static_cast<char>(event.text.unicode);
      this->_port.setString(this->_portText);
    }
  }
  if (this->_isNameCliked) {
    if (event.type == sf::Event::TextEntered) {
      this->_nameText += static_cast<char>(event.text.unicode);
      this->_name.setString(this->_nameText);
    }
  }
  if (event.type == sf::Event::Closed)
    win.close();
}

void LoginMenu::draw(Window &win)
{
<<<<<<< HEAD
  for(auto it : this->_sprites)
  {
    win.draw(it.second);
  }
  win.draw(this->_ip);
  win.draw(this->_port);
  win.draw(this->_name);
}
=======
}

>>>>>>> Menu
