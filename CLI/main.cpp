#include "commandParser.h"
#include <iostream>
#include <string>

int main() {
    std::string input;
    CommandParser commandParser;

    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, input);

        commandParser.parseCommand(input); 

        if (input == "exit") {
            break;
        }
    }

    return 0;
}
