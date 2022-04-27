#ifndef parseTable_h
#define parseTable_h

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


class parseEntry{
    public:
    vector<string> action;
    vector<string> goTo;
};

class parseTable{
    private:
    vector<parseEntry> table;
    public:
    void insert(){
        parseEntry p1;
        cout<<"Insert Action Row"<<endl;
        for(int i=0; i<45; i++)
            cin>>p1.action[i];
        cout<<"Insert GoTo Row"<<endl;
        for(int i=0; i<26; i++)
            cin>>p1.goTo[i];
        table.push_back(p1);
    }
    void printTable(){
        for(int i=0; i<130; i++){
            cout<<"A ";
            for(int j=0; j<table[i].action.size(); j++)
                cout<<table[i].action[j]<<" ";
            cout<<"GT ";
            for(int j=0; j<table[i].goTo.size(); j++)
                cout<<table[i].goTo[j]<<" ";
            cout<<endl;
        }
    }
    void writeTable(){
        ofstream f1("LALR.txt");
        for(int i=0; i<128; i++){
            for(int j=0; j<45; j++)
                f1<<table[i].action[j]<<" ";
            for(int j=0; j<26; j++)
                f1<<table[i].goTo[j]<<" ";
            f1<<endl;
        }
        f1.close();
    }
    void readTable(){
        ifstream f1("LALR.txt");
        string s;
        int i=0;
        while(getline(f1, s)){
            stringstream line(s);
            string token;
            int j=0;
            int k=0;
            int tc = 0;
            parseEntry p;
            table.push_back(p);
            while(line >> token){
                if(tc == 0){
                    tc++;
                    continue;
                }
                if(j<46){
                    table[i].action.push_back(token);
                    j++;
                }
                else{
                    table[i].goTo.push_back(token);
                    k++;
                }
            }
        i++;
        }
        f1.close();
    }
    parseEntry accessParseTable(int i){
        return table[i];
    }
};

#endif