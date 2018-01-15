//
// Created by baudet_q on 10/01/18.
//

#include "Music.hpp"

Music::Music()
{
  this->_music.setRelativeToListener(false);
  this->_music.setVolume(10.0);
}

Music::Music(const std::string & pathFile, const std::string & newCurrMusic)
{
  this->loadAudio(pathFile, newCurrMusic);
  this->_music.openFromFile(this->_musicFilePath);
}


void Music::loadAudio(const std::string & filename, const std::string & newCurrName)
{
  try
  {
    this->setMusicFilePath(filename);
    this->setCurrentName(newCurrName);

  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    exit(84);
  }
}

void Music::playAudio()
{
  std::cout << "The name of the music is : " << this->_currMusic << std::endl;
  try
  {
    this->_music.play();
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    exit(84);
  }
}

void Music::stopAudio()
{
  this->_music.stop();
}

void Music::setAudioVolume(float newVolume)
{
  this->_music.setVolume(newVolume);
}

float Music::getAudioVolume() const
{
  return (this->_music.getVolume());
}

sf::SoundSource::Status Music::getStatus() const
{
  return (this->_music.getStatus());
}

std::string Music::getCurrentName() const
{
  return (this->_currMusic);
}

void Music::setCurrentName(const std::string & newCurrMusic)
{
  this->_currMusic = newCurrMusic;
}

void Music::setLoop(bool newLoop)
{
  this->_music.setLoop(newLoop);
}

void Music::setMusicFilePath(std::string newMusicFilePath) {
  this->_musicFilePath = newMusicFilePath;
}
std::string Music::getMusicFilePath() const {
  return (this->_musicFilePath);
}

Music::~Music() {}
