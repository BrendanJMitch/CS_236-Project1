#include <iostream>
#include <string>
#include <fstream>
#include "MatcherAuto.h"
#include "Lexer.h"
using namespace std;


int main (int argc, char *argv[]){

    if (argc == 1){
        cout << "No input files. Program terminated." << endl;
        return 0;
    }

    ifstream fin(argv[1]);
    string input((std::istreambuf_iterator<char>(fin)), (std::istreambuf_iterator<char>()));

    Lexer lexer;
    vector<Token> Tokens = lexer.Run(input);

    string answer = "";
    for (unsigned int i = 0; i < Tokens.size(); i++){
        answer += Tokens[i].toString();
    }
    answer += "Total Tokens = " + to_string(Tokens.size());
    cout << answer << endl;
}
