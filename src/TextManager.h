#pragma once

#include <string>
#include <map>

using std::string;
using std::map;

// Contains information about a language pack
struct PackInfo
{
};

// This class is used for reading game text from the file system
// in the desired language.
class TextManager
{
    public:
        TextManager();

        void LoadFile(string filename);
        void ClearText();
    private:
        // maps the directories of all available languages packs by title
        map<string, string> languagePacks;
        // the title of the current language pack
        string languagePack;
        // text currently loaded by the manager, mapped by identifier
        map<string, string> text;
};
