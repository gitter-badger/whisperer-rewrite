#include "ScriptManager.h"

#include <iostream>

#include <fstream>
using std::ifstream;
using std::getline;

#include <sstream>
using std::stringstream;

namespace
{
    const char COMMENT_CHAR = '#';
}

void ScriptManager::RegisterCommand(string name, CommandFunction function)
{
    commandFunctions[name] = function;
}

void ScriptManager::RunCommand(string command)
{
    commands.push_front(command);
}

void ScriptManager::RunScript(string file)
{
    ifstream ifile(file.c_str());

    vector<string> lines;
    string line;

    // Extract the lines into a vector
    while (getline(ifile, line))
    {
        lines.push_back(line);
    }

    // Add the lines to the FRONT of the execution buffer
    // IN REVERSE ORDER to assure they occur sequentially
    for (auto it = lines.rbegin(); it != lines.rend(); ++it)
    {
        // Ignore empty lines and comment lines
        if (it->size() == 0) continue;
        if (it->at(0) == COMMENT_CHAR) continue;

        // Store all other lines in the buffer
        this->commands.push_front(*it);
    }

    ifile.close();
}

void ScriptManager::ProcessNextCommand(Whisperer* game)
{
    // Commands follow the following syntax:
    // [Command] [Arg1] [Arg2] ... [ArgN]
    string commandName;
    vector<string> commandArgs;

    // Retrieve the next command
    string command = this->commands.front();

    // Remove the command from the execution buffer
    this->commands.pop_front();

    // Split it by spaces
    stringstream commandStream(command);

    // The command name is the first token
    commandStream >> commandName;

    // Followed by an arbitrary number of arguments
    string nextArg;
    while (commandStream >> nextArg)
    {
        commandArgs.push_back(nextArg);
    }

    // Call the appropriate registered function using the given arguments
    CommandFunction function = this->commandFunctions[commandName];
    
    if (function == NULL)
    {
        std::cout << "Error: tried to call an invalid script command." << std::endl;
        // TODO handle the error gracefully
        return;
    }

    // Actually call the function
    function(game, commandArgs);
}
