#pragma once
#include <string>
#include "Automaton.h"

class MatcherAuto : public Automaton {
    private:
    std::string ID;

    public:
    MatcherAuto(TokenType type) : Automaton(type){
    }
    virtual int read(std::string& input);
};
