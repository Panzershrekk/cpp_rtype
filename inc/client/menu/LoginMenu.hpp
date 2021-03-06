//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_LOGINMENU_HPP_
#define CPP_RTYPE_LOGINMENU_HPP_

#include	<unordered_map>
#include	<boost/asio.hpp>
#include	"IMenu.hpp"
#include	<memory>

enum Buttonchoice {IPButton, PortButton, NameButton, NONE};

class LoginMenu : public IMenu
{
  private:
    std::map<std::string, Sprite> 	_sprites;
    Text				_ip;
    Text				_port;
    Text				_name;
  std::vector<std::shared_ptr<IMenu>>	_vecMenu;

  //std::vector<std::function<void(Text &, sf::Event)>>	_vecButFunctions;

    MenuState				&_state;
    Buttonchoice 			_whichBut;
  TcpClient				*_client;


  void getSfLine(Text &, sf::Event &);

  public:
    explicit LoginMenu(MenuState &);
    ~LoginMenu();

  void setClient(TcpClient *&);

  TcpClient *getClient();
    void start(Window &) override;
    void update(Window &, sf::Event &) override;
    void draw(Window &) override;

    void 	enterIP(Window &, sf::Event &);
    void 	enterPort(Window &, sf::Event &);
    void 	enterName(Window &, sf::Event &);
    void 	playFunction(Window &, sf::Event &);
    void 	soloFunction(Window &, sf::Event &);
  void setMenu(std::vector<std::shared_ptr<IMenu>>&);

  void returnFunction(Window &, sf::Event &);

  std::string 	getName() const;
  TcpClient	*getClient() const;

};


#endif /* !CPP_RTYPE_LOGINMENU_HPP_ */
