#pragma once

#include <string>
#include <map>

using std::string;
using std::map;

// Contains information about a language pack
struct PackInfo
{
    public:
        string title;
        string language;
        string author;
        string version;
        bool lefttoright;
};

// This class is used for reading game text from the file system
// in the desired language.
class TextManager
{
    public:
        // Constructs a TextManager by loading all available language packs
        TextManager();

        // Sets the current language pack to be used
        void SetPack(string title);
        // Loads the version of the given filename in the proper language
        void LoadFile(string filename);
        // Clears all text loaded in the TextManager
        void ClearText();
    private:
        // maps the directories of all available languages packs by title
        map<string, string> languagePacks;
        // the title of the current language pack
        string languagePack;
        // text currently loaded by the manager, mapped by identifier
        map<string, string> text;
};
