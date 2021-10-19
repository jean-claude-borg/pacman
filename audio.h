#pragma once

#include "globals.h"

void loadAudio()
{
    InitAudioDevice();
    start = LoadMusicStream("../assets/audio/start.mp3"); 
    credit = LoadSound("../assets/audio/credit.wav"); 
    credit = LoadSound("../assets/audio/credit.wav"); 
    munch1 = LoadSound("../assets/audio/munch_1.wav"); 
    munch2 = LoadSound("../assets/audio/munch_2.wav"); 
    siren1 = LoadMusicStream("../assets/audio/siren_1.mp3"); 
    siren2 = LoadMusicStream("../assets/audio/siren_2.wav"); 
};

void playAudio(float volume)
{
    loadAudio();
    SetMasterVolume(volume);

    // theme.looping = true;
    // PlayMusicStream(theme);
    siren1.looping = true;
    PlayMusicStream(siren1);
};