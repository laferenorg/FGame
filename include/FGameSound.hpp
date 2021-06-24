#ifndef _FGAME_SOUND_HPP_
#define _FGAME_SOUND_HPP_

/* Include Library C++ */
#include <memory>

/* Include Library SDL2 */
#include <SDL2/SDL_mixer.h>

/* Class for play wav */
class fgame_call_sound_wav_ {
public:
    fgame_call_sound_wav_(const std::string &fgame_path, int fgame_volume);
    void play();

private:
    std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk *)> chunk;
};

typedef class fgame_call_sound_wav_ FGameClassWAV;

/* Class for play wav */
class fgame_call_sound_music_ {
public:
    fgame_call_sound_music_(const std::string &fgame_path, int fgame_volume);
    void play(int loops);

private:
    std::unique_ptr<Mix_Music, void (*)(Mix_Music *)> chunk;
};

typedef class fgame_call_sound_music_ FGameClassMUSIC;

#endif // _FGAME_SOUND_HPP_