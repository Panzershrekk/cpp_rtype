//
// Created by baudet_q on 18/01/18.
//

#ifndef CPP_RTYPE_IMAGE_HPP
#define CPP_RTYPE_IMAGE_HPP

#include <SFML/Graphics/Image.hpp>
#include <string>
#include "Color.hpp"

class Image{
public:
   explicit Image();
  Image(std::string &);
    virtual ~Image();
    void create(int, int, const sf::Color);
    sf::Image getImage() const; //TODO consst ref
    void        setImage(sf::Image);
  unsigned int getHeight();
  unsigned int getWidht();
  const sf::Uint8*  getPixelsPtr();

private:
    sf::Image _image;
};

#endif //CPP_RTYPE_IMAGE_HPP
