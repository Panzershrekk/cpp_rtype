//
// Created by baudet_q on 10/01/18.
//

#include "SoundSystem.hpp"

Sound::Sound()
{
}

Sound::Sound(const std::string & pathFile, const std::string & newCurrSoundName)
{
  this->_sound.setRelativeToListener(true);
  this->_sound.setVolume(100.0);
  this->loadAudio(pathFile, newCurrSoundName);
  this->setCurrentName(newCurrSoundName);
  this->setFilePath(pathFile);
}

void Sound::loadAudio(const std::string & pathFile, const std::string &  newCurrName)
{

  try
  {
    this->_sound.setBuffer(this->_buffer);
    this->setCurrentName(newCurrName);
    this->setFilePath(pathFile);
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    exit(84);
  }
}

void Sound::playAudio()
{
  _sound.play();
}

void Sound::stopAudio()
{
  _sound.stop();
}

void Sound::setAudioVolume(float newVolume)
{
  this->_sound.setVolume(newVolume);
}

float Sound::getAudioVolume() const
{
  return (_sound.getVolume());
}

sf::SoundSource::Status Sound::getStatus() const
{
  return (_sound.getStatus());
}

std::string Sound::getCurrentName() const
{
  return (this->_currSoundName);
}

void Sound::setCurrentName(const std::string &newCurrentName)
{
  this->_currSoundName = newCurrentName;
}

void Sound::setLoop(bool newLoop)
{
  this->_sound.setLoop(newLoop);
}

void Sound::setFilePath(std::string newFilePath) {
  this->_filePath  = newFilePath;
}

std::string Sound::getFilePath() const {
  return (this->_filePath);
}
Sound::~Sound() {}