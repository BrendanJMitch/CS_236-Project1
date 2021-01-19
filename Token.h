#pragma once
#include "TokenType.h"
#include <string>
using namespace std;

class Token{

    private:
    TokenType type;
    string input;
    int lineNumber;

    public:
    Token(TokenType type, string input, int lineNumber){
            this->type = type;
            this->input = input;
            this->lineNumber = lineNumber;
    }
};