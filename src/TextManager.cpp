#include "TextManager.h"

#include <dirent.h>

namespace
{
    const string TEXT_DIR("content/text");
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
        }

        entry = readdir(dir);
    }

    closedir(dir);
}

void TextManager::LoadFile(string filename)
{
}

void TextManager::ClearText()
{
}
