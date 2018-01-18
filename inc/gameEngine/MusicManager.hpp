//
// Created by baudet_q on 11/01/18.
//

#ifndef CPP_RTYPE_MUSICMANAGER_HPP
#define CPP_RTYPE_MUSICMANAGER_HPP

# include <iostream>
# include <SFML/Audio.hpp>
# include <vector>

# include "Music.hpp"


class MusicManager {
  public:
    MusicManager();
    virtual ~MusicManager();
    Music *GetRandomMusic() const;
    void AddNewMusic(Music *); //TODO Metter Music en const & ?
  private:
    std::vector<Music *> _musicManager;
};

#endif //CPP_RTYPE_MUSICMANAGER_HPP
