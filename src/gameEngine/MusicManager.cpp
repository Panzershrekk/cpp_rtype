//
// Created by baudet_q on 11/01/18.
//

#include "Music.hpp"
#include "MusicManager.hpp"

MusicManager::MusicManager()
{

}

MusicManager::~MusicManager()
{

}

void MusicManager::AddNewMusic(const std::string &pathFile, const std::string &newCurrMusic)
{
  this->_musicManager.push_back(std::make_shared<Music>(pathFile, newCurrMusic));
}

std::shared_ptr<Music> &MusicManager::GetRandomMusic()
{
  srand (static_cast<unsigned int>(time(nullptr)));
  auto randomIndex = static_cast<int>(std::rand() % this->_musicManager.size()); //TODO throw si jamais il y a pas de musique
  return (this->_musicManager.at(static_cast<unsigned long>(randomIndex)));
}

Music &MusicManager::getMusicByName(const std::string &musicName)
{
  for (auto it = this->_musicManager.begin(); it != this->_musicManager.end(); ++it)
  {
    if (it->get()->getCurrentName() == musicName)
    {
      return *it->get();
    }
  }
  auto it = this->_musicManager.begin();
  return *it->get();
}