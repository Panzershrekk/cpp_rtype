//
// Created by arthaox on 21/01/18.
//

#include <common/network/core/StringSplit.hpp>

StringSplit::StringSplit()
{

}

StringSplit::~StringSplit()
{

}

std::string* StringSplit::SplitOurString(std::string str)
{
  int cpt = 0;
  int a = 0;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == ':')
    {
      cpt++;
      str[i] = ' ';
    }
  }
  cpt++;
  std::string array[cpt];
  std::stringstream ssin(str);
  while (ssin.good() && a < cpt){
    ssin >> array[a];
    ++a;
  }
  return (array);
}