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
    std::string	_str;
    Font	*_font;

  public:
    explicit Text();
    Text(const std::string &, const std::string &);
    Text(const std::string &, const std::string &, float, float);
    ~Text();

    void 	setFont(const std::string &);
    void 	setString(const std::string &);
    void 	setCharacterSize(unsigned int);
    void 	setPosition(int, int);
    void 	setScale(int, int);
    void 	setColor(int, int, int, int);

    sf::Text	&getSfText(void);
    std::string	getString(void) const;
};


#endif /* !CPP_RTYPE_TEXT_HPP_ */
