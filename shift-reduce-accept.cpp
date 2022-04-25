#include <iostream>
#include <stack>
#include <string>

using namespace std;
//no of productions, lhs+rhs, max size of something in lhs or rhs
char cfg[4][2][4] = {{"Q", "S"},
                     {"S", "AA"},
                     {"A", "aA"},
                     {"A", "b"}};

stack<char> input_string;
stack<char> stck;

int terminal_count = 3;
int non_terminal_count = 2;

char arr[8][5][4] = {{"a", "b", "$", "S", "A"},
                          {"S3", "S4", "-", "1", "2"},
                          {"R1", "R1", "R1", "-", "-"},
                          {"S3", "S4", "-", "-", "5"},
                          {"S3", "S4", "-", "-", "6"},
                          {"R4", "R4", "R4", "-", "-"},
                          {"R2", "R2", "R2", "-", "-"},
                          {"R3", "R3", "R3", "-", "-"}};

void shift(char input_top, char new_state){
    input_string.pop();
    stck.push(input_top);
    stck.push(new_state);
}

void reduce(char new_state){
    //Rnewstate is the reduction rule
    int production_rule = new_state - '0';
    string rhs_cfg = cfg[production_rule - 1][1];
    int pop_count = rhs_cfg.size();
    for(int i=0;i<2*pop_count;i++){
        stck.pop();
    }
    string lhs_cfg = cfg[production_rule - 1][0];
    stck.push(lhs_cfg[0]);
    if(stck.top() == 'Q'){
        cout << "Accept";
        exit(1);
    }
    //GOTO
    char ch = stck.top();
    string str = string(1, ch);
    int index=0;
    for(int i=terminal_count;i<terminal_count+non_terminal_count;i++){
        if(str.compare(arr[0][i])==0){
            index = i;
            break;
        }
    }
    stck.pop();
    char stack_top = stck.top();
    stck.push(ch);
    string action = arr[stack_top-'0'+1][index];
    cout << "[" << stack_top << "," << ch <<"]\n";
    cout << "Action is GOTO "<<action<<"\n";
    stck.push(action[0]);
}

int main() {
    //Build parse table
    input_string.push('$');
    input_string.push('b');
    input_string.push('b');
    input_string.push('a');
    input_string.push('a');


    stck.push('$');
    stck.push('0');

    while(true){
        char stack_top = stck.top();
        char input_top = input_string.top();
        cout << "[" << stack_top << "," << input_top <<"]\n";
        string str = string(1, input_top);

        if(stack_top >= '0' && stack_top <= '9'){
            int index=0;
            for(int i=0;i<terminal_count+non_terminal_count;i++){
                if(str.compare(arr[0][i])==0){
                    index = i;
                    break;
                }
            }
            string action = arr[stack_top-'0'+1][index];
            cout<<"The action to be performed is "<< action<<"\n";

            //if shift
            if(action[0]=='S'){
                shift(input_top, action[1]);
            }
            else{
                reduce(action[1]);
            }
            //if reduce

        }
        else if(stack_top == 'Q'){
            cout << "Accept";
            exit (1);
        }
        else{
            cout << "Reject";
            exit(1);
        }

    }
}
