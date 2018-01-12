//
// Created by grodin on 11/01/18.
//

#ifndef CPP_RTYPE_FONT_HPP_
#define CPP_RTYPE_FONT_HPP_

#include	<SFML/Graphics/Font.hpp>

class Font
{
  private:
    sf::Font	*_font;
    std::string	_fontPath;

  public:
    explicit Font();
    Font(const std::string &);
    ~Font();

    std::string	getFontPath(void) const;
    void 	setFontPath(const std::string &);
    sf::Font	*getSfFont(void);
};


#endif /* !CPP_RTYPE_FONT_HPP_ */
