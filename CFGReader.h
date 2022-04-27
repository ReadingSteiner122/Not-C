#ifndef CFGReader_h
#define CFGReader_h
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#include <list>
#include "token_type.h"
#include "token.h"
#include <regex>
using namespace std;

class CFG{
    vector<vector<string>> productions;
    public:
    vector<string> accessCFG(int i){
        return productions[i];
    }
    void readCFG(){
        ifstream f1("CFG.txt");
        string s;
        int i=0;
        while(getline(f1, s)){
            stringstream line(s);
            string token;
            vector<string> p;
            //productions.push_back(p);
            while(line >> token){
                if(token.compare("->")!=0)
                    p.push_back(token);  
            }
            productions.push_back(p);
        }
        f1.close();
    }
    void printCFG(){
        for(int i=0; i<productions.size(); i++){
            for(int j=0; j<productions[i].size(); j++){
                if(j == 0)
                    cout<<productions[i][j]<<" -> ";
                else
                    cout<<productions[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
#endif