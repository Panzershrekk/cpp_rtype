//
// Created by baudet_q on 10/01/18.
//

#ifndef CPP_RTYPE_MUSIC_HPP
#define CPP_RTYPE_MUSIC_HPP

# include "IAudio.hpp"

class Music : public IAudio
{
  public:
    Music();
    Music(const std::string &, const std::string &);
    virtual ~Music();
    void loadAudio(const std::string & filename, const std::string &);
    void playAudio();
    void stopAudio();
    void setAudioVolume(float);
    float getAudioVolume() const;
    sf::SoundSource::Status getStatus() const;
    std::string getCurrentName() const;
    void setCurrentName(const std::string &);
    void setLoop(bool);
    void setMusicFilePath(std::string);
    std::string getMusicFilePath() const;

  private:
    sf::Music		_music;
    std::string		_currMusic;
    std::string		_musicFilePath;
};


#endif //CPP_RTYPE_MUSIC_HPP
