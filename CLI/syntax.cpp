#include "tokenizer.h"
#include <vector>
#include <iostream>

bool validateTokenOrder(const std::vector<Token>& tokens) {
    bool foundFirstCommand = false;
    bool foundSecondCommand = false;
    bool expectingOption = false; 
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
            if (!foundFirstCommand) {
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

    // Final check to ensure we are not expecting a value at the end
    if (expectingValue) {
        return false; // If we expect a value at the end, it's invalid
    }

    return true; // The token sequence is valid
}

