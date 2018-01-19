//
// Created by baudet_q on 18/01/18.
//

#include "Image.hpp"


Image::Image() {

}

void Image::create(int x, int y, const sf::Color color) {
    this->_image.create(static_cast<unsigned int>(x), static_cast<unsigned int>(y), color); //TODO staticccast
}

void Image::setImage(sf::Image image) {
    this->_image = image;
}

sf::Image Image::getImage() const {
    return this->_image;
}

Image::~Image() = default;

