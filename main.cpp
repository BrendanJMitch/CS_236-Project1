#include <iostream>
#include <string>
#include <fstream>
#include "MatcherAuto.h"
using namespace std;


int main (int argc, char *argv[]){

    if (argc == 1){
        cout << "No input files. Program terminated." << endl;
        return 0;
    }
    ifstream fin(argv[1]);
    cout << argv[1] << endl;
    MatcherAuto Auto(SCHEMES, "Schemes");
    string inputstr;
    while(!fin.eof()){
        fin >> inputstr;
        int val = Auto.read(inputstr);
        cout << inputstr << endl;
        cout << val << endl;
    }
    cout << endl << endl << endl;

    Token token(SCHEMES, "Schemes", 10);
    token.print();

}
