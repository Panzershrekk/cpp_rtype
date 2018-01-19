//
// Created by baudet_q on 11/01/18.
//

#ifndef CPP_RTYPE_MUSICMANAGER_HPP
#define CPP_RTYPE_MUSICMANAGER_HPP

# include <memory>
# include <iostream>
# include <SFML/Audio.hpp>
# include <vector>
# include "Music.hpp"

class MusicManager
{
public:
  MusicManager();
  virtual ~MusicManager();

  Music		&GetRandomMusic();
  void		AddNewMusic(Music &); //TODO Metter Music en const & ?
  Music		&getMusicByName(const std::string &) ;

private:
  std::vector<Music> _musicManager;
};

#endif //CPP_RTYPE_MUSICMANAGER_HPP
