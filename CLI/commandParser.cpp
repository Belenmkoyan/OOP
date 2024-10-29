#include "commandParser.h"
#include <iostream>

void CommandParser::parseCommand(const std::string& input) {
    if (input == "help") {
        std::cout << "Available commands: help, exit" << std::endl;
    } else if (input == "exit") {
        std::cout << "Exiting the program." << std::endl;
    } else {
        std::cout << "Unknown command: " << input << std::endl;
    }
}

