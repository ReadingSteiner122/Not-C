#include <iostream>
#include <stack>
#include <string>
#include "CFGReader.h"
#include "parse_table.h"

using namespace std;
//no of productions, lhs+rhs, max size of something in lhs or rhs
/*char cfg[4][2][4] = {{"Q", "S"},
                     {"S", "AA"},
                     {"A", "aA"},
                     {"A", "b"}};*/
CFG cfg;

stack<string> input_string;
stack<string> stck;

//int terminal_count = 3;
//int non_terminal_count = 2;

/*char arr[8][5][4] = {{"a", "b", "$", "S", "A"},
                          {"S3", "S4", "-", "1", "2"},
                          {"R1", "R1", "R1", "-", "-"},
                          {"S3", "S4", "-", "-", "5"},
                          {"S3", "S4", "-", "-", "6"},
                          {"R4", "R4", "R4", "-", "-"},
                          {"R2", "R2", "R2", "-", "-"},
                          {"R3", "R3", "R3", "-", "-"}};*/

parseTable arr;

void shift(string input_top, string new_state){
    input_string.pop();
    stck.push(input_top);
    stck.push(new_state);
}

void reduce(char new_state){
    //Rnewstate is the reduction rule
    if(new_state!=' '){
        int production_rule = new_state - '0';
        vector<string> cfgr(cfg.accessCFG(production_rule - 1));
        //string rhs_cfg = cfg.accessCFG(production_rule - 1)[1];
        int pop_count = cfgr.size() - 1;
        for(int i=0;i<2*pop_count;i++){
            stck.pop();
        }
        string lhs_cfg = cfgr[0];
        stck.push(lhs_cfg);
        if(stck.top()[0] == 'Q'){
            cout << "Accept";
            exit(1);
        }
    }else{
    //GOTO
        string ch = stck.top();
        string str = ch;
        int index=0;
        /*for(int i=terminal_count;i<terminal_count+non_terminal_count;i++){
            if(str.compare(arr.accessParseTable(0).goTo[i])==0){
                index = i;
                break;
            }
        }*/
        int acGo;
        for(int i=0;i<arr.accessParseTable(0).action.size();i++){
            if(str.compare(arr.accessParseTable(0).action[i])==0){
                index = i;
                acGo = 0;
                break;
            }else if(i<arr.accessParseTable(0).goTo.size() && str.compare(arr.accessParseTable(0).goTo[i])==0){
                index = i;
                acGo = 1;
                break;
            }
        }
        stck.pop();
        string stack_top = stck.top();
        stck.push(ch);
        string action = (acGo==0)?arr.accessParseTable(stack_top[0]-'0'+1).action[index]:arr.accessParseTable(stack_top[0]-'0'+1).goTo[index];
        cout << "[" << stack_top << "," << ch <<"]\n";
        cout << "Action is GOTO "<<action<<"\n";
        string actions(1, action[0]);
        stck.push(actions);
    }
}


int main() {
    //Build parse table
    /*input_string.push('$');
    input_string.push('b');
    input_string.push('b');
    input_string.push('a');
    input_string.push('a');


    stck.push('$');
    stck.push('0');*/
    input_string.push("$");
    input_string.push("}");
    input_string.push("0");
    input_string.push("return");
    input_string.push("{");
    input_string.push(")");
    input_string.push("(");
    input_string.push("main");
    input_string.push("int");

    stck.push("$");
    stck.push("0");

    cfg.readCFG();
    arr.readTable();
    //cout<<"AccessParse "<<arr.accessParseTable(0).action[8]<<endl;

    while(true){
        string stack_top = stck.top();
        string input_top = input_string.top();
        cout << "[" << stack_top << "," << input_top <<"]\n";
        string str = input_top;

        if(stack_top[0] >= '0' && stack_top[0] <= '9'){
            int index=0;
            int acGo;
            for(int i=0;i<arr.accessParseTable(0).action.size();i++){
                if(str.compare(arr.accessParseTable(0).action[i])==0){
                    index = i;
                    acGo = 0;
                    //cout<<"PENIS-1"<<endl;
                    break;
                }else if(i<arr.accessParseTable(0).goTo.size() && str.compare(arr.accessParseTable(0).goTo[i])==0){
                    index = i;
                    acGo = 1;
                    //cout<<"PENIS-2"<<endl;
                    break;
                }
            }
            cout<<index<<" "<<acGo<<" "<<arr.accessParseTable(stack_top[0]-'0'+1).goTo[index]<<endl;
            string action = (acGo==0)?arr.accessParseTable(stack_top[0]-'0'+1).action[index]:arr.accessParseTable(stack_top[0]-'0'+1).goTo[index];
            cout<<"The action to be performed is "<< action<<"\n";
            //if shift
            if(action[0]=='S'){
                string actions(1, action[1]);
                shift(input_top, actions);
            }
            else if (action[0] ='R'){
                reduce(action[1]);
            }else
                reduce(' ');
            //if reduce

        }
        else if(stack_top[0] == 'Q'){
            cout << "Accept";
            exit (1);
        }
        else{
            cout << "Reject";
            exit(1);
        }

    }
}
