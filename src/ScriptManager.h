#pragma once

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <string>
using std::string;

#include <map>
using std::map;

class Whisperer;


typedef void (*CommandFunction)(Whisperer*, vector<string>);

class ScriptManager
{
    public:
        // Registers a new script command whose execution is defined
        // by the given function
        void RegisterCommand(string name, CommandFunction function);

        // Adds the given command to the front of the execution buffer
        void RunCommand(string command);

        // Adds the commands stored in the given file to the front
        // of the execution buffer.
        void RunScript(string file);

        // Processes the next script command in the execution buffer.
        void ProcessNextCommand(Whisperer* game);

        // Whether there are any commands remaining in the execution buffer
        bool HasNextCommand() { return !commands.empty(); }
    private:
        map<string, CommandFunction> commandFunctions;
        deque<string> commands;
};
