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
  this->_sprites.emplace(std::make_pair("Solo", Sprite("../assets/MainMenu_Button_Single.png", 1600, 800)));
  this->_sprites.emplace(std::make_pair("Multi", Sprite("../assets/MainMenu_Button_Multi.png", 1600, 900)));
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

void LoginMenu::soloFunction(Window &win, sf::Event &event)
{
  std::cout << "Play Solo" << std::endl;;
}

void LoginMenu::playFunction(Window &win, sf::Event &event)
{
  if (_ip.getString() != "" && _port.getString() != "" && _name.getString() != "") {
    std::cout << "in play" << std::endl;
    if (_client == nullptr || (_client != nullptr && _client->isConnected())) {
      try {
    if (_client == nullptr|| (_client != nullptr && _client->isConnected())) {
	try {
	boost::asio::ip::tcp::endpoint endpoint(
	  boost::asio::ip::address::from_string(_ip.getString()),
	  static_cast<unsigned short>(std::stoi(_port.getString())));
	std::cout << "in play out" << std::endl;
	std::cout << _ip.getString() << std::endl;
	std::cout << static_cast<unsigned short>(std::stoi(_port.getString()))
		  << std::endl;
	  _client = new TcpClient(endpoint, _state);
	  _client->setMenu(_vecMenu);
	  _client->getVecMenu().at(2)->setClient(_client);
	  _client->getVecMenu().at(3)->setClient(_client);

	std::cout << "fin du scope" << std::endl;
      }
      catch (std::exception &e) {
	std::cout << e.what() << std::endl;
      }
    }
  }
}

void LoginMenu::returnFunction(Window &win, sf::Event &event)
{
  if (_client != nullptr) {
    _client->disconnect();
    _client = nullptr;
  }
  this->_state = EMainMenu;
}

void LoginMenu::getSfLine(Text &text, sf::Event &event)
{
  std::string str = text.getString();

  if (event.type == sf::Event::TextEntered) {
    if ((event.text.unicode > 30 && (event.text.unicode < 128 || event.text.unicode > 159)))
      str += static_cast<char>(event.text.unicode);
    else if (event.text.unicode == '\b') {
      if (!str.empty())
	str.erase(str.size() - 1, 1);
    }
    text.setString(str);
  }
}

std::string LoginMenu::getName() const
{
  return (this->_name.getString());
}

void LoginMenu::update(Window &win, sf::Event &event)
{
  auto	fIp = std::bind(&LoginMenu::enterIP, this, std::placeholders::_1, std::placeholders::_2);
  auto	fPort = std::bind(&LoginMenu::enterPort, this, std::placeholders::_1, std::placeholders::_2);
  auto	fName = std::bind(&LoginMenu::enterName, this, std::placeholders::_1, std::placeholders::_2);
  auto	fGo = std::bind(&LoginMenu::playFunction, this, std::placeholders::_1, std::placeholders::_2);
  auto	fSolo = std::bind(&LoginMenu::soloFunction, this, std::placeholders::_1, std::placeholders::_2);
  auto	fBack = std::bind(&LoginMenu::returnFunction, this, std::placeholders::_1, std::placeholders::_2);

  this->_sprites.at("IpAddress").onClick(fIp, win, event);
  this->_sprites.at("Port").onClick(fPort, win, event);
  this->_sprites.at("Name").onClick(fName, win, event);
  this->_sprites.at("Multi").onClick(fGo, win, event);
  this->_sprites.at("Solo").onClick(fSolo, win, event);
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

void LoginMenu::setClient(TcpClient *&client) {
  _client = client;
}

void LoginMenu::setMenu(std::vector<std::shared_ptr<IMenu>> &menu)
{
  std::cout << "menu = " << menu.size() << std::endl;
  _vecMenu = menu;
  std::cout << "menu = " << _vecMenu.size() << std::endl;

}

TcpClient *LoginMenu::getClient()
{
  return _client;
}

