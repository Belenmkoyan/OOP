#include "tokenizer.h"
#include "syntax.h"
#include <iostream>
#include <vector>
#include <string>

void parseCommand(const std::string &input) {
    std::vector<Token> tokens = tokenize(input);

    if (!validateTokenOrder(tokens)) {
        std::cout << "Error: Invalid command syntax." << std::endl;
        return;
    }

    std::string command;
    std::vector<std::pair<std::string, std::string>> options;

    for (size_t i = 0; i < tokens.size(); ++i) {
        if (tokens[i].type == COMMAND) {
            if (command.empty()) {
                command = tokens[i].text; 
            } else {
                command += " " + tokens[i].text;
            }
        }
        else if (tokens[i].type == OPTION) {
            if (i + 1 < tokens.size() && tokens[i + 1].type == VALUE) {
                options.emplace_back(tokens[i].text, tokens[i + 1].text);
                ++i; 
            } else {
                std::cout << "Error: Option " << tokens[i].text << " requires a value." << std::endl;
                return;
            }
        }
        else if (tokens[i].type == UNKNOWN) {
            std::cout << "Error: Unrecognized token '" << tokens[i].text << "'." << std::endl;
            return;
        }
    }

    std::cout << "Command: " << command << std::endl;
    for (const auto &opt : options) {
        std::cout << "Option: " << opt.first << ", Value: " << opt.second << std::endl;
    }

    if (command == "add shape") {
        std::cout << "Adding shape with specified options..." << std::endl;
    } else if (command == "delete shape") {
        std::cout << "Deleting shape with specified options..." << std::endl;
    } else {
        std::cout << "Error: Unrecognized command '" << command << "'." << std::endl;
    }
}
