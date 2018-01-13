//
// Created by grodin on 10/01/18.
//

#ifndef CPP_RTYPE_WINDOW_HPP_
#define CPP_RTYPE_WINDOW_HPP_

#include <SFML/Graphics/RenderWindow.hpp>
#include "Sprite.hpp"
#include "Text.hpp"

class Window
{
  private:
    sf::RenderWindow		_win;

  public:
    explicit Window(const std::string &, unsigned int, unsigned int);
    ~Window();
    void 	close(void);
    void 	clear(void);
    bool 	isOpen(void) const;
    void 	setTitle(const std::string &);
    void 	display(void);
    bool 	pollEvent(sf::Event &);
    void 	draw(Sprite &);
    void 	draw(Text &);
    sf::RenderWindow& getRenderWindow();
//    void 	setPosition(const Position2D &);
};


#endif /* !CPP_RTYPE_WINDOW_HPP_ */
