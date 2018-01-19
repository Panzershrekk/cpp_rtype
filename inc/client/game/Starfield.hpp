//
// Created by baudet_q on 17/01/18.
//

#ifndef STARFIELD_STARFIELD_HPP
#define STARFIELD_STARFIELD_HPP

#include "Star.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <random>
#include <vector>
#include <ctime>

using std::vector;

class Starfield
{
  public:
    Starfield();
    Starfield(int, int);
    ~Starfield() {}

    void updateStarfield();
    void drawStarfield(sf::Texture&);

  protected:

    int maxSmallStars;
    int maxMediumStars;
    int maxLargeStars;

    int x_Size;
    int y_Size;

    vector<Star> smallStars;
    vector<Star> mediumStars;
    vector<Star> largeStars;

    std::default_random_engine re_x;
    std::default_random_engine re_y;
    std::uniform_int_distribution<int> my_distribution_x;
    std::uniform_int_distribution<int> my_distribution_y;

    sf::Image smallStarImage;
    sf::Image mediumStarImage;
    sf::Image largeStarImage;
};

#endif //STARFIELD_STARFIELD_HPP
