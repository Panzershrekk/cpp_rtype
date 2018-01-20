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

  std::shared_ptr<Music>		&GetRandomMusic();
  void		AddNewMusic(const std::string & , const std::string & );
  Music		&getMusicByName(const std::string &) ;

private:
  std::vector<std::shared_ptr<Music>> _musicManager;
};

#endif //CPP_RTYPE_MUSICMANAGER_HPP
