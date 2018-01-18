//
// Created by baudet_q on 18/01/18.
//

#ifndef CPP_RTYPE_IMAGE_HPP
#define CPP_RTYPE_IMAGE_HPP

#include <SFML/Graphics/Image.hpp>
#include "Color.hpp"

class Image{
public:
    Image();
    virtual ~Image();
    void create(int, int, const sf::Color);
    sf::Image getImage() const; //TODO consst ref
    void        setImage(sf::Image);

private:
    sf::Image _image;
};

#endif //CPP_RTYPE_IMAGE_HPP
