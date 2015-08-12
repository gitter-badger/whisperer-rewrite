#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;

#include "../Whisperer.h"
#include "../State.h"


/* SOUND EFFECTS */

// Load a simple sound effect
State* LoadSound(Whisperer* game, vector<string> args)
{
    // Syntax: LoadSound [key] [path]
    string key = args.at(0);
    string path = args.at(1);

    game->soundManager()->loadSound(key, path.c_str());
    return NULL;
}

// Free a sound effect
State* FreeSound(Whisperer* game, vector<string> args)
{
    // Syntax: FreeSound [key]
    string key = args.at(0);

    game->soundManager()->freeSound(key);
    return NULL;
}

// Play a sound effect by referencing its key
State* PlaySound(Whisperer* game, vector<string> args)
{
    // Syntax: PlaySound [key]
    string key = args.at(0);

    game->soundManager()->playSound(key);
    return NULL;
}

// Load a sound effect into a sound effect group
State* LoadGroupSound(Whisperer* game, vector<string> args)
{
    // Syntax: LoadGroupSound [group] [path]
    string group = args.at(0);
    string path = args.at(1);

    game->soundManager()->loadGroupSound(group, path.c_str());
    return NULL;
}

// Free all sound effects in a sound effect group
State* FreeSoundGroup(Whisperer* game, vector<string> args)
{
    // Syntax: FreeSoundGroup [group]
    string group = args.at(0);

    game->soundManager()->freeSoundGroup(group);
    return NULL;
}

// Play a random sound effect from a sound effect group
State* PlaySoundGroup(Whisperer* game, vector<string> args)
{
    // Syntax: PlaySoundGroup [group]
    string group = args.at(0);

    game->soundManager()->playSoundGroup(group);
    return NULL;
}

// Play a random sound effect from a group. Once it's finished, play
// another random one, and so on.
State* LoopSoundGroup(Whisperer* game, vector<string> args)
{
    // Syntax: LoopSoundGroup [key]
    string key = args.at(0);

    game->soundManager()->loopSoundGroup(key);
    return NULL;
}

// Stop looping a sound effect group
State* StopLoopingGroup(Whisperer* game, vector<string> args)
{
    // Syntax: StopLoopingGroup [key] // stop just one group
    // OR      StopLoopingGroup       // stop every looping group
    if (args.empty())
    {
        game->soundManager()->stopLoopingGroup();
    }
    else
    {
        string key = args.at(0);

        game->soundManager()->stopLoopingGroup(key);
    }

    return NULL;
}

// Set the volume of all sound effects
State* SetSoundVolume(Whisperer* game, vector<string> args)
{
    // Syntax: SetSoundVolume [volume (float 0-1)]
    float volume = atof(args.at(0).c_str());

    game->soundManager()->setSoundVolume(volume);
    return NULL;
}


/* MUSIC */

// Load a music track
State* LoadTrack(Whisperer* game, vector<string> args)
{
    // Syntax: LoadTrack [key] [path]
    string key = args.at(0);
    string path = args.at(1);

    game->soundManager()->loadTrack(key, path.c_str());
    return NULL;
}

// Free a music track
State* FreeTrack(Whisperer* game, vector<string> args)
{
    // Syntax: FreeTrack [key]
    string key = args.at(0);

    game->soundManager()->freeTrack(key);
    return NULL;
}

// Play a music track on loop
State* PlayTrack(Whisperer* game, vector<string> args)
{
    // Syntax: PlayTrack [key]
    string key = args.at(0);

    game->soundManager()->playTrack(key);
    return NULL;
}

// Fade in a music track on loop
State* FadeInTrack(Whisperer* game, vector<string> args)
{
    // Syntax: FadeInTrack [key] [fadeMS]
    string key = args.at(0);
    int fadeMS = atoi(args.at(1).c_str());

    game->soundManager()->fadeInTrack(key, fadeMS);
    return NULL;
}

// Stop the currently looping music track
State* StopTrack(Whisperer* game, vector<string> args)
{
    game->soundManager()->stopTrack();
    return NULL;
}

// Fade out the currently looping music track
State* FadeOutTrack(Whisperer* game, vector<string> args)
{
    // Syntax: FadeOutTrack [fadeMS]
    int fadeMS = atoi(args.at(0).c_str());

    game->soundManager()->fadeOutTrack(fadeMS);
    return NULL;
}

// Pause the currently looping music track
State* PauseTrack(Whisperer* game, vector<string> args)
{
    game->soundManager()->pauseTrack();
    return NULL;
}

// Resume the currently paused music track
State* ResumeTrack(Whisperer* game, vector<string> args)
{
    game->soundManager()->resumeTrack();
    return NULL;
}

// Set the volume of all music tracks
State* SetMusicVolume(Whisperer* game, vector<string> args)
{
    // Syntax: SetMusicVolume [volume (float 0-1)]
    float volume = atof(args.at(0).c_str());

    game->soundManager()->setMusicVolume(volume);
    return NULL;
}
