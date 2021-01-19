#include "Token.h"
#include "TokenType.h"


Token::Token(TokenType type, string input, int lineNumber){
    this->type = type;
    this->input = input;
    this->lineNumber = lineNumber;
}