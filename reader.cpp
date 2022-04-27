#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    ifstream f1("copypaste.txt");
    string s;
    while(getline(f1, s)){
        stringstream linestream(s);
        string token;
        while(linestream >> token){
            cout<<"Token: "<<token<<endl;
        }
    }
    f1.close();
}