#include "TextManager.h"

#include <dirent.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// TODO debug
#include <iostream>

using std::ifstream;
using std::stringstream;
using std::vector;

namespace
{
    const string TEXT_DIR("content/text");
    const string INFO_FILE("info.json");

    // info file elements
    const string TITLE_KEY("title");
    const string LANGUAGE_KEY("language");
    const string AUTHOR_KEY("author");
    const string VERSION_KEY("version");
    const string MODE_KEY("mode");

    // mode codes
    map<string, PrintMode> PRINT_MODES = {
        { "lefttoright", LEFT_TO_RIGHT },
        { "rightoleft", RIGHT_TO_LEFT }
    };

    // directories to ignore
    vector<string> IGNORE_DIRECTORIES= {
        ".",
        ".."
    };
}

TextManager::TextManager()
{
    // Find the text folder and search every folder inside it for
    // a language pack
    DIR* dir = opendir(TEXT_DIR.c_str());

    struct dirent* entry = readdir(dir);

    while (entry != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            // Found a pack folder
            string packDir = entry->d_name;
            // Make sure it's not the current directory or parent directory
            if (std::find(IGNORE_DIRECTORIES.begin(), IGNORE_DIRECTORIES.end(),
                        packDir) != IGNORE_DIRECTORIES.end())
            {
                entry = readdir(dir);
                continue;
            }
            // Load the pack from info file
            LoadPack(TEXT_DIR + "/" + packDir + "/" + INFO_FILE, packDir);
        }

        entry = readdir(dir);
    }

    closedir(dir);
}

void TextManager::LoadFile(string filename)
{
    // load the file
    filename = TEXT_DIR + "/" + CurrentPack().directory + "/" + filename;
    string fileJson = this->ReadFile(filename);

    // Parse the text file as JSON
    Json::Value root;
    Json::Reader reader;

    bool success = reader.parse(fileJson, root, false);

    if (!success)
    {
        std::cout << "Error: failed to load text file " << filename << std::endl;
        std::cout << reader.getFormattedErrorMessages() << std::endl;
        //
        // TODO handle error gracefully
        return;
    }

    // Store all text inside the file in the text map
    Json::Value::Members memberNames = root.getMemberNames();
    for (auto it = memberNames.begin(); it != memberNames.end(); ++it)
    {
        this->text[*it] = GetElement(root, *it);
    }
}

void TextManager::ClearText()
{
    this->text.clear();
}

void TextManager::LoadPack(string filename, string directory)
{
    // load the file
    string packJson = this->ReadFile(filename);

    // Parse the information file as JSON
    Json::Value root;
    Json::Reader reader;

    bool success = reader.parse(packJson, root, false);

    if (!success)
    {
        std::cout << "Error: failed to parse language pack file "
            << directory << std::endl;

        std::cout << reader.getFormattedErrorMessages() << std::endl;
        // TODO handle the error gracefully
        return;
    }

    // parse out the pack info into a struct
    string title(GetElement(root, TITLE_KEY));
    this->languagePacks[title] = {
        title,
        GetElement(root, LANGUAGE_KEY),
        GetElement(root, AUTHOR_KEY),
        GetElement(root, VERSION_KEY),
        PRINT_MODES[GetElement(root, MODE_KEY)],
        directory
    };
}

string TextManager::GetElement(Json::Value root, string elementKey)
{
    return root[elementKey].asString();
}

string TextManager::ReadFile(string filename)
{
    stringstream buffer;

    ifstream file(filename);
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}
