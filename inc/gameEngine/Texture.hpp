//
// Created by grodin on 11/01/18.
//

#ifndef CPP_RTYPE_TEXTURE_HPP_
#define CPP_RTYPE_TEXTURE_HPP_

#include	<SFML/Graphics/Texture.hpp>

class Texture
{
  private:
    sf::Texture		_texture;
    const std::string	_filePath;

  public:
    explicit Texture();
    Texture(const std::string &);
    Texture(const std::string &, int, int, int, int);
    ~Texture();
    void	setSmooth(bool);
    void	setRepeated(bool);

    void    loadFromImage(const sf::Image &);

    sf::Texture & getSfTexture();

    const std::string	&getFilePath(void) const;

//    Position2D getSize() : const

};


#endif /* !CPP_RTYPE_TEXTURE_HPP_ */
