#include "Lexer.h"
#include <string>
#include <iostream>
using namespace std;

Lexer::Lexer(){
    Autos.push_back(new MatcherAuto(COMMA, ","));
    Autos.push_back(new MatcherAuto(PERIOD, "."));
    Autos.push_back(new MatcherAuto(Q_MARK, "?"));
    Autos.push_back(new MatcherAuto(LEFT_PAREN, "("));
    Autos.push_back(new MatcherAuto(RIGHT_PAREN, ")"));
    Autos.push_back(new MatcherAuto(COLON, ":"));
    Autos.push_back(new MatcherAuto(COLON_DASH, ":-"));
    Autos.push_back(new MatcherAuto(MULTIPLY, "*"));
    Autos.push_back(new MatcherAuto(ADD, "+"));
    Autos.push_back(new MatcherAuto(SCHEMES, "Schemes"));
    Autos.push_back(new MatcherAuto(FACTS, "Facts"));
    Autos.push_back(new MatcherAuto(RULES, "Rules"));
    Autos.push_back(new MatcherAuto(QUERIES, "Queries"));
}

Lexer::~Lexer(){
    for(unsigned int i = 0; i < Autos.size(); i++){
        delete Autos[i];
    }
}

vector<Token> Lexer::Run(string input){  //Check for newline reliability 
    lineNumber = 1;
    int numAutos = Autos.size();
    int charsRead = 0;
    int maxCharsRead;
    int maxIndex;
    int maxNewlines;
    while (input.size()){
        maxCharsRead = 0;
        maxIndex = 0;
        maxNewlines = 0;
        for (int i = 0; i < numAutos; i++){
            charsRead = Autos[i]->read(input);
            if (charsRead > maxCharsRead){
                maxCharsRead = charsRead;
                maxIndex = i;
                maxNewlines = Autos[i]->NewLinesRead();
            }
        }
        if (maxCharsRead > 0){
            lineNumber += maxNewlines;
            Tokens.push_back(Autos[maxIndex]->CreateToken(input.substr(0,maxCharsRead), lineNumber));
        } else {
            maxCharsRead = 1;
            Tokens.push_back(Token(UNDEFINED, input.substr(0,1), lineNumber));
        }
        input.erase(0,maxCharsRead);
    }
    return Tokens;
}