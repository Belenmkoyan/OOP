#include "tokenizer.h"
#include <vector>
#include <iostream>

bool validateTokenOrder(const std::vector<Token>& tokens) {
    bool foundFirstCommand = false;
    bool foundSecondCommand = false;
    bool expectingOption = true; 
    bool expectingValue = false;

    for (size_t i = 0; i < tokens.size(); ++i) {
        if (tokens[i].type == COMMAND) {
            if (!foundFirstCommand) {
                foundFirstCommand = true;
            } else if (!foundSecondCommand) {
                foundSecondCommand = true;
            } else {
                return false;
            }
        }
        else if (tokens[i].type == OPTION) {
            if (!foundFirstCommand || !foundSecondCommand) {
                return false; 
            }
            expectingOption = false;
            expectingValue = true; 
        }
        else if (tokens[i].type == VALUE) {
            if (!expectingValue) {
                return false; 
            }
            expectingValue = false; 
            expectingOption = true; 
        }
        else if (tokens[i].type == UNKNOWN) {
            return false; 
        }
    }

    if (expectingValue) {
        return false;
    }

    return true;
}
