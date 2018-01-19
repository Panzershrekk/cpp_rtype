//
// Created by baudet_q on 18/01/18.
//

#include <gameEngine/Color.hpp>
#include "Starfield.hpp"

//starfield won't work without proper data
Starfield::Starfield(): maxSmallStars(0), maxMediumStars(0), maxLargeStars(0), x_Size(800), y_Size(600)
{
}

Starfield::Starfield(int xResolution, int yResolution)
{

  x_Size = xResolution;
  y_Size = yResolution;

  //size of the different star sizes in pixels
  int smallSize = 1;
  int mediumSize = 2;
  int largeSize = 4;

  //create the images that will be used to update the background texture
  smallStarImage.create(smallSize, smallSize, sf::Color::White); //TODO Encapsulé sf::Color
  mediumStarImage.create(mediumSize, mediumSize, sf::Color::White);
  largeStarImage.create(largeSize, largeSize, sf::Color::White);

  //init random generator
  my_distribution_x = std::uniform_int_distribution<int>(0, xResolution);
  my_distribution_y = std::uniform_int_distribution<int>(0, yResolution);

  re_x.seed(std::time(0));
  re_y.seed(std::time(0)+24);

  //The higher reduceStars the fewer stars; classDifference sets the proportionality between small, medium and large stars. The higher the number, the fewer stars in each larger class.
  int reduceStars = 20;
  int classDifference = 3;

  maxSmallStars = (xResolution / (reduceStars * 10)) * (yResolution / reduceStars);
  maxMediumStars = (xResolution / (reduceStars * 10 * classDifference)) * (yResolution / (reduceStars * classDifference));
  maxLargeStars = (xResolution / (reduceStars * 10 * classDifference * classDifference)) * (yResolution / (reduceStars * classDifference * classDifference));

  //generate a start set of stars
  while((int)smallStars.size() <= maxSmallStars){
    smallStars.push_back(Star(my_distribution_x(re_x), my_distribution_y(re_y)));
  }

  while((int)mediumStars.size() <= maxMediumStars){
    mediumStars.push_back(Star(my_distribution_x(re_x), my_distribution_y(re_y)));
  }

  while((int)largeStars.size() <= maxLargeStars){
    largeStars.push_back(Star(my_distribution_x(re_x), my_distribution_y(re_y)));
  }
}

void Starfield::updateStarfield()
{
  //remove all stars that have exceeded the lower screen border
  smallStars.erase(remove_if(smallStars.begin(), smallStars.end(), [&](Star& p_Star){
			       return (p_Star.getXPos() > x_Size);
			     }
  ), smallStars.end());

  mediumStars.erase(remove_if(mediumStars.begin(), mediumStars.end(), [&](Star& p_Star){
				return (p_Star.getXPos() > x_Size);
			      }
  ), mediumStars.end());

  largeStars.erase(remove_if(largeStars.begin(), largeStars.end(), [&](Star& p_Star){
			       return (p_Star.getXPos() > x_Size);
			     }
  ), largeStars.end());

  //move every star, according to its size to create a parallax effect
  for_each(smallStars.begin(), smallStars.end(), [&](Star& p_Star){
	     p_Star.addXPos(-1);
	   }
  );

  for_each(mediumStars.begin(), mediumStars.end(), [&](Star& p_Star){
	     p_Star.addXPos(-2);
	   }
  );

  for_each(largeStars.begin(), largeStars.end(), [&](Star& p_Star){
	     p_Star.addXPos(-4);
	   }
  );

  //create new stars until the set limit is reached
  while((int)smallStars.size() <= maxSmallStars){
    smallStars.push_back(Star(my_distribution_x(re_x), my_distribution_y(re_y)));
  }

  while((int)mediumStars.size() <= maxMediumStars){
    mediumStars.push_back(Star(my_distribution_x(re_x), my_distribution_y(re_y)));
  }

  while((int)largeStars.size() <= maxLargeStars){
    largeStars.push_back(Star(my_distribution_x(re_x), my_distribution_y(re_y)));
  }
}

//update a target texture with all stars contained in this starfield
void Starfield::drawStarfield(sf::Texture& p_Texture)
{
  for(vector<Star>::iterator it = smallStars.begin(); it != smallStars.end(); ++it){
    p_Texture.update(smallStarImage, it->getXPos(), it->getYPos());
  }

  for(vector<Star>::iterator it = mediumStars.begin(); it != mediumStars.end(); ++it){
    p_Texture.update(mediumStarImage, it->getXPos(), it->getYPos());
  }

  //system("clear"); //TODO wtf ?
  for(vector<Star>::iterator it = largeStars.begin(); it != largeStars.end(); ++it){
    p_Texture.update(largeStarImage, it->getXPos(), it->getYPos());
  }
}
