/*******************************************************************//*
 * Singleton class that manages all audio code. Supports loading,
 * playing, pausing, and stopping music/chunks.
 *
 * @author      Brandon To
 * @version     1.0
 * @since       2015-02-17
 * @modified    2015-02-20
 *********************************************************************/
#ifndef SPACESHOOTER_AUDIOSYSTEM_H_
    #define SPACESHOOTER_AUDIOSYSTEM_H_

#ifdef _WIN32
	#include <SDL_mixer.h>
#endif

#ifdef __linux
	#include <SDL2/SDL_mixer.h>
#endif

#include <map>
#include <string>

class AudioSystem
{
    private:
        static AudioSystem* instance;
        std::map<std::string, Mix_Music*> musicTable;
        std::map<std::string, Mix_Chunk*> soundTable;
        Mix_Music* currentMusic;

        bool musicPlayingState;

        bool musicEnabled;
        bool soundEnabled;

        int musicVolume;
        int soundVolume;

        AudioSystem();

    public:
        static AudioSystem* getInstance()
        {
            if (instance == NULL) instance = new AudioSystem();
            return instance;
        };

        void initialize();

        void setMusicPlayingState(bool status);

        void toggleMusic();
        void toggleSound();

        bool getMusicStatus();
        bool getSoundStatus();

        void loadMusic(std::string id);

        void playMusic();
        void pauseMusic();
        void stopMusic();

        void playSound(std::string id);
        void pauseSound();
        void stopSound();

        void terminate();
};

#endif
