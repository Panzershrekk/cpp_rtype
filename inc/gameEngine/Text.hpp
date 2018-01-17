//
// Created by grodin on 11/01/18.
//

#ifndef CPP_RTYPE_TEXT_HPP_
#define CPP_RTYPE_TEXT_HPP_

#include	<SFML/Graphics/Text.hpp>
#include	"Font.hpp"

class Text
{
  private:
    sf::Text	_text;
    Font	*_font;

  public:
    explicit Text();
    Text(const std::string &, const std::string &);
    ~Text();

    void 	setFont(const std::string &);
    void 	setString(const std::string &);
    void 	setCharacterSize(unsigned int);
    void 	setPosition(int, int);
    void 	setScale(int, int);

    sf::Text	&getSfText(void);
};


#endif /* !CPP_RTYPE_TEXT_HPP_ */
