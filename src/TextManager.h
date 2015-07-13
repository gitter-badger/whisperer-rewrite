#pragma once

#include <string>
#include <map>

#include "json/json.h"

using std::string;
using std::map;

// Contains different modes for the process of printing text
enum PrintMode
{
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT
};

// Contains information about a language pack
struct PackInfo
{
    public:
        string title;
        string language;
        string author;
        string version;
        PrintMode mode;

        string directory;
};

// This class is used for reading game text from the file system
// in the desired language.
class TextManager
{
    public:
        // Constructs a TextManager by loading all available language packs
        TextManager();

        // GETTERS

        // Map containing every language pack's configuration
        map<string, PackInfo> LanguagePacks() { return languagePacks; }
        // The current language pack's configuration
        PackInfo CurrentPack() { return languagePacks[currentPack]; }

        // Retrieve a string of text from a loaded text file
        string GetText(string key);

        // ^GETTERS

        // Sets the current language pack to be used
        void SetPack(string title) { currentPack = title; }
        // Loads the version of the given filename in the proper language
        void LoadFile(string filename);
        // Clears all text loaded in the TextManager
        void ClearText();
    private:
        // Loads a language pack's configuration
        void LoadPack(string filename, string directory);

        // Helper--Gets an element as UTF-8 string
        string GetElement(Json::Value root, string elementKey);
        // Helper--loads a file as a string
        string ReadFile(string filename);

        // maps all available languages packs by title
        map<string, PackInfo> languagePacks;
        // the title of the current language pack
        string currentPack;
        // text currently loaded by the manager, mapped by identifier
        map<string, string> text;
};
