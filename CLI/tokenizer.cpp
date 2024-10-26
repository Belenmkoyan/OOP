#include "tokenizer.h"
#include <iostream>
#include <vector>
#include <cctype>

std::vector<Token> tokenize(const std::string &input) {
    std::vector<Token> tokens;
    size_t pos = 0;

    while (pos < input.size()) {
        while (pos < input.size() && std::isspace(input[pos])) {
            ++pos;
        }

        if (pos < input.size() && input[pos] == '-') {
            size_t start = pos;
            ++pos;
            while (pos < input.size() && (std::isalpha(input[pos]) || std::isdigit(input[pos]))) {
                ++pos;
            }
            std::string option = input.substr(start, pos - start);
            tokens.push_back({option, OPTION});
        }
        else if (pos < input.size() && input[pos] == '"') {
            ++pos;
            size_t start = pos;
            while (pos < input.size() && input[pos] != '"') {
                ++pos;
            }
            if (pos < input.size() && input[pos] == '"') {
                std::string value = input.substr(start, pos - start);
                tokens.push_back({value, VALUE});
                ++pos;
            } else {
                tokens.push_back({input.substr(start - 1, pos - start + 1), UNKNOWN});
            }
        }
        else if (pos < input.size() && std::isalpha(input[pos])) {
            size_t start = pos;
            while (pos < input.size() && std::isalpha(input[pos])) {
                ++pos;
            }
            std::string command = input.substr(start, pos - start);
            tokens.push_back({command, COMMAND});
        }
        else if (pos < input.size()) {
            tokens.push_back({std::string(1, input[pos]), UNKNOWN});
            ++pos;
        }
    }

    return tokens;
}
