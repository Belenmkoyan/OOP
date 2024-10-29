#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

enum TokenType {
    COMMAND,
    OPTION,
    VALUE,
    UNKNOWN
};

struct Token {
    std::string text; 
    TokenType type;  
};
std::vector<Token> tokenize(const std::string &input);

#endif 
