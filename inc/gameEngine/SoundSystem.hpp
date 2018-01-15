//
// Created by baudet_q on 10/01/18.
//

#ifndef CPP_RTYPE_SOUNDSYSTEM_HPP
#define CPP_RTYPE_SOUNDSYSTEM_HPP

# include "IAudio.hpp"

class Sound : public IAudio
{
  public:
    Sound();
    Sound(const std::string &, const std::string &);
    virtual ~Sound();

    void loadAudio(const std::string & , const std::string &);
    void playAudio();
    void stopAudio();
    void setAudioVolume(float volume);
    float getAudioVolume() const;
    sf::SoundSource::Status getStatus() const;
    std::string getCurrentName() const;
    void setCurrentName(const std::string &);
    void setLoop(bool);
    void setFilePath(std::string);
    std::string getFilePath() const ;

  private:
    std::string		_currSoundName;
    std::string		_filePath;
    sf::SoundBuffer	_buffer;
    sf::Sound		_sound;
};

#endif //CPP_RTYPE_SOUNDSYSTEM_HPP
