//
// Created by baudet_q on 11/01/18.
//

#include <Music.hpp>
#include <MusicManager.hpp>

MusicManager::MusicManager()
{
}

void MusicManager::AddNewMusic(Music *music)
{
  this->_musicManager.push_back(music);
}
Music *MusicManager::GetRandomMusic() const
{
  std::vector<Music *> tmpMusicManager;

  srand (static_cast<unsigned int>(time(NULL)));
  tmpMusicManager = this->_musicManager;
  auto randomIndex = static_cast<int>(rand() % tmpMusicManager.size()); //TODO throw si jamais il y a pas de musique
  Music *m = tmpMusicManager.at(static_cast<unsigned long>(randomIndex));
  return m;
}

MusicManager::~MusicManager()
{

}

