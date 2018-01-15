//
// Created by baudet_q on 10/01/18.
//

#ifndef CPP_RTYPE_IAUDIO_HPP
#define CPP_RTYPE_IAUDIO_HPP

# include <iostream>
# include <SFML/Audio.hpp>
//# include <IndieException.hpp> //TODO Include une lib d'execption

# include <string>
# include <map>

class IAudio
{
  public:
    virtual ~IAudio() {};
    virtual void loadAudio(const std::string &, const std::string &) = 0;
    virtual void playAudio() = 0;
    virtual void stopAudio() = 0;
    virtual void setAudioVolume(float) = 0;
    virtual float getAudioVolume() const = 0;
    virtual sf::SoundSource::Status getStatus() const = 0;
    virtual std::string getCurrentName() const = 0;
    virtual void setCurrentName(const std::string &) = 0;
    virtual void setLoop(bool) = 0;
};

#endif //CPP_RTYPE_IAUDIO_HPP
