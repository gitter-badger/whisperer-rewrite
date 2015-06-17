#include "TextManager.h"

#include <dirent.h>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::stringstream;

namespace
{
    const string TEXT_DIR("content/text");
    const string INFO_FILE("info.json");

    // info file encoding
    const string PACK_ENCODING("UTF-8");

    // info file elements
    const string TITLE_KEY("title");
    const string LANGUAGE_KEY("language");
    const string AUTHOR_KEY("author");
    const string VERSION_KEY("version");
    const string MODE_KEY("mode");

    // mode codes
    const map<string, PrintMode> PRINT_MODES;
    PRINT_MODES["lefttoright"] = LEFT_TO_RIGHT;
    PRINT_MODES["rightoleft"] = RIGHT_TO_LEFT;
}

TextManager::TextManager()
{
    // Find the text folder and search every folder inside it for
    // a language pack
    DIR* dir = opendir(TEXT_DIR);

    struct dirent* entry = readdir(dir);

    while (entry != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            // Found a pack folder
            string packDir = entry->d_name;
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
    stringstream buffer;
    {
        ifstream file(TEXT_DIR + "/" + CurrentPack().directory + "/" + filename);
        buffer << file.rdbuf();
        file.close();
    }

    // Parse the text file as JSON
    Json::Value root;
    Json::Reader reader;

    bool success = reader.parse(buffer.str(), root, false);

    if (!success)
    {
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
    stringstream buffer;
    {
        ifstream file(filename);
        buffer << file.rdbuf();
        file.close();
    }

    // Parse the information file as JSON
    Json::Value root;
    Json::Reader reader;

    bool success = reader.parse(buffer.str(), root, false);

    if (!success)
    {
        // TODO handle the error gracefully
        return;
    }

    // parse out the pack info into a struct
    string title(GetElement(root, TITLE_KEY);
    this->languagePacks[title] = {
        title,
        getElement(root, LANGUAGE_KEY),
        getElement(root, AUTHOR_KEY),
        getElement(root, VERSION_KEY),
        PRINT_MODES[getElement(root, MODE_KEY)],
        directory
    };
}

string TextManager::GetElement(Json::Value root, string elementKey)
{
    return root.get(elementKey, PACK_ENCODING).asString();
}
