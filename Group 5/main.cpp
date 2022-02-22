// Group 5 - Compilers Assignment
// 2018B4A70713H	Aswath Vinayak K
// 2018B4A70812H	Sanath Salil
// 2019A7PS0147H	Sanket Bhatt
// 2019A7PS0132H	Vaibhav Jha


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


class Lexer{
    int line_no;
    list<Token> tokens;
    int multi_com;
    bool isPunctuator(char ch)					//check if the given character is a punctuator or not
    {
        if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
            ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
            ch == '&' || ch == '|' || ch == '!' || ch == '?' ||
            ch == ':' || ch == '%')
            {
                return true;
            }
        return false;
    }

    bool validIdentifier(char* str)						//check if the given identifier is valid or not
    {
        regex identif("[a-zA-Z]+[a-zA-Z0-9_]*");
        if(regex_match(str, identif))
            return true;
        else
            return false;

    }

    bool isOperator(char ch)							//check if the given character is an operator or not
    {
        if (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '>' || ch == '<' ||
            ch == '=' || ch == '|' || ch == '&' ||
            ch == '?' || ch == '%' || ch == '!' || ch == ':')
        {
        return true;
        }
        return false;
    }

    bool isKeyword(char *str)						//check if the given substring is a keyword or not
    {
        if (!strcmp(str, "if") || !strcmp(str, "else")
            || !strcmp(str, "while") || !strcmp(str, "until") || !strcmp(str, "for")
            || !strcmp(str, "int") || !strcmp(str, "float")
            || !strcmp(str, "return") || !strcmp(str,"boolean")
            || !strcmp(str, "char") || !strcmp(str, "string")
            || !strcmp(str, "true") || !strcmp(str, "false"))
            {
                if(!strcmp(str, "if"))
                    tokens.push_back(Token(TOKEN_IF, str, line_no));
                else if(!strcmp(str, "else"))
                    tokens.push_back(Token(TOKEN_ELSE, str, line_no));
                else if(!strcmp(str, "while"))
                    tokens.push_back(Token(TOKEN_WHILE, str, line_no));
                else if(!strcmp(str, "until"))
                    tokens.push_back(Token(TOKEN_UNTIL, str, line_no));
                else if(!strcmp(str, "for"))
                    tokens.push_back(Token(TOKEN_FOR, str, line_no));
                else if(!strcmp(str, "int"))
                    tokens.push_back(Token(TOKEN_INT, str, line_no));
                else if(!strcmp(str, "float"))
                    tokens.push_back(Token(TOKEN_FLOAT, str, line_no));
                else if(!strcmp(str, "return"))
                    tokens.push_back(Token(TOKEN_RETURN, str, line_no));
                else if(!strcmp(str, "boolean"))
                    tokens.push_back(Token(TOKEN_BOOL, str, line_no));
                else if(!strcmp(str, "char"))
                    tokens.push_back(Token(TOKEN_CHAR, str, line_no));
                else if(!strcmp(str, "string"))
                    tokens.push_back(Token(TOKEN_STRING, str, line_no));
                else if(!strcmp(str, "true"))
                    tokens.push_back(Token(TOKEN_LITERAL_TRUE, str, line_no));
                else if(!strcmp(str, "false"))
                    tokens.push_back(Token(TOKEN_LITERAL_FALSE, str, line_no));
                return true;
            }
        else
        {
        return false;
        }
    }

    bool isNumber(char* str)							//check if the given substring is a number or not
    {
        int i, len = strlen(str),numOfDecimal = 0;
        if (len == 0)
        {
            return false;
        }
        int float_flag=0;
        for(int j=0;j<len;j++){
            if(str[j]=='.')
                float_flag=1;
        }
        if(!float_flag){
            for (i = 0 ; i < len ; i++)
            {
                if (numOfDecimal > 1 && str[i] == '.')
                {
                    return false;
                } else if (numOfDecimal <= 1)
                {
                    numOfDecimal++;
                }
                if (!isdigit(str[i]) || (str[i] == '-' && i > 0))
                    {
                        return false;
                    }
            }
            tokens.push_back(Token(TOKEN_INT_LITERAL, str, line_no));
            return true;
        }
        else{
            int non_num=0;
            for(i = 0; i < len; i++){
                if(!isdigit(str[i])){
                        non_num++;
                    }
                if (!isdigit(str[i]) && str[i] != '.' || (str[i] == '-' && i > 0))
                    {
                        return false;
                    }
                if(non_num>=2)
                    return false;
            }
            tokens.push_back(Token(TOKEN_FLOAT_LITERAL, str, line_no));
            return true;
        }
    }

    char* subString(char* realStr, int l, int r)				//extract the required substring from the main string
    {
        int i;

        char* str = (char*) malloc(sizeof(char) * (r - l + 2));

        for (i = l; i <= r; i++)
        {
            str[i - l] = realStr[i];
            str[r - l + 1] = '\0';
        }
        return str;
    }

    public:
    Lexer(){
        line_no = 1;
        multi_com = 0;
    }
    void parse(char* str)						//parse the expression
    {
        int left = 0, right = 0;
        int len = strlen(str);
        while (right <= len && left <= right) {
            if((str[right] == '/' && str[right+1] == '*') || multi_com == 1){ //multiline comments
                multi_com = 1;
                while(multi_com == 1){
                    if(str[right] == '*' && str[right+1] == '/'){
                        multi_com = 0;
                    }
                    if(right > len)
                        break;
                    right++;
                }
                left = right + 1;
                right = right + 1;
                if(right > len)
                    break;
            }
            if(str[right] == '/' && str[right+1] == '/'){
                break;
            }
            if(str[right] == '\"'){
                int l1 = right;
                right++;
                int err_flag = 0;
                while(str[right]!='\"' || (str[right]=='\"' && str[right-1]=='\\')){
                    if(right >= strlen(str)){
                        char *sub = subString(str, l1, right);
                        tokens.push_back(Token(TOKEN_ERROR, sub, line_no));
                        err_flag = 1;
                        break;
                    }
                    right++;
                }
                if(err_flag == 0){
                    char* sub = subString(str, l1, right);
                    tokens.push_back(Token(TOKEN_STRING_LITERAL, sub, line_no));
                    right = right + 1;
                    left = right;
                }else
                    break;
            }
            if (isPunctuator(str[right]) == false)			//if character is a digit or an alphabet
                {
                    right++;
                }
            if (isPunctuator(str[right]) == true && left == right)		//if character is a punctuator
                {
                char punct=str[right];
                if(punct==' '){}
                else if(punct=='\n'){}
                else if(punct==','){
                    string s(1, punct);
                    tokens.push_back(Token(TOKEN_COMMA, s, line_no));
                    }
                else if(punct==';'){
                    string s(1, punct);
                    tokens.push_back(Token(TOKEN_SEMICOLON, s, line_no));
                    }
                else if(punct=='(' || punct==')'){
                    string s(1, punct);
                    if(punct == '(')
                        tokens.push_back(Token(TOKEN_LEFT_BRACE, s, line_no));
                    else
                        tokens.push_back(Token(TOKEN_RIGHT_BRACE, s, line_no));
                    }
                else if(punct=='[' || punct==']'){
                    string s(1, punct);
                    if(punct == '[')
                        tokens.push_back(Token(TOKEN_LEFT_SQUARE_BRACKET, s, line_no));
                    else
                        tokens.push_back(Token(TOKEN_RIGHT_SQUARE_BRACKET, s, line_no));
                    }
                else if(punct=='{' || punct=='}'){
                    string s(1, punct);
                    if(punct == '{')
                        tokens.push_back(Token(TOKEN_LEFT_PAREN, s, line_no));
                    else
                        tokens.push_back(Token(TOKEN_RIGHT_PAREN, s, line_no));
                    }

                else if (isOperator(str[right]) == true)
                {
                    int flag = 0;
                    if(right<len && isOperator(str[right+1])){
                        string s1(1, str[right]);
                        string s2(1, str[right+1]);
                        string s = s1 + s2;
                    switch(str[right]){
                        case '+':
                            if(str[right+1] == '='){
                                tokens.push_back(Token(TOKEN_PLUS_EQUAL, s, line_no));
                                flag = 1;
                            }
                            else if(str[right+1] == '+'){
                                tokens.push_back(Token(TOKEN_PLUS_PLUS, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '-':
                            if(str[right+1] == '='){
                                tokens.push_back(Token(TOKEN_MINUS_EQUAL, s, line_no));
                                flag = 1;
                            }
                            else if(str[right+1] == '-'){
                                tokens.push_back(Token(TOKEN_MINUS_MINUS, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '*':
                            if(str[right+1] == '='){
                                tokens.push_back(Token(TOKEN_MULTIPLY_EQUAL, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '/':
                            if(str[right+1] == '='){
                                tokens.push_back(Token(TOKEN_DIVIDE_EQUAL, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '>':
                            if(str[right+1] == '='){
                                tokens.push_back(Token(TOKEN_GREATER_EQUAL, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '<':
                            if(str[right+1] == '='){
                                tokens.push_back(Token(TOKEN_LESS_EQUAL, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '=':
                            if(str[right+1] == '='){
                                tokens.push_back(Token(TOKEN_EQUAL_EQUAL, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '|':
                            if(str[right+1] == '|'){
                                tokens.push_back(Token(TOKEN_OR_OR, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '&':
                            if(str[right+1] == '&'){
                                tokens.push_back(Token(TOKEN_AND_AND, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '%':
                            if(str[right+1] == '='){
                                tokens.push_back(Token(TOKEN_MODULO_EQUAL, s, line_no));
                                flag = 1;
                            }
                            break;
                        case '!':
                            if(str[right+1] == '='){
                                tokens.push_back(Token(TOKEN_NOT_EQUAL, s, line_no));
                                flag = 1;
                            }
                            break;
                        default:
                            break;
                        }
                        if(flag)
                            right++;
                    }
                    if(isOperator(str[right]) && flag!=1){
                        string s(1, str[right]);
                        switch(str[right]){
                            case '+':
                                tokens.push_back(Token(TOKEN_PLUS, s, line_no));
                                break;
                            case '-':
                                tokens.push_back(Token(TOKEN_MINUS, s, line_no));
                                break;
                            case '*':
                                tokens.push_back(Token(TOKEN_MULTIPLY, s, line_no));
                                break;
                            case '/':
                                tokens.push_back(Token(TOKEN_DIVIDE, s, line_no));
                                break;
                            case '>':
                                tokens.push_back(Token(TOKEN_GREATER, s, line_no));
                                break;
                            case '<':
                                tokens.push_back(Token(TOKEN_LESS, s, line_no));
                                break;
                            case '=':
                                tokens.push_back(Token(TOKEN_EQUAL, s, line_no));
                                break;
                            case '|':
                                tokens.push_back(Token(TOKEN_OR, s, line_no));
                                break;
                            case '&':
                                tokens.push_back(Token(TOKEN_AND, s, line_no));
                                break;
                            case '%':
                                tokens.push_back(Token(TOKEN_MODULO, s, line_no));
                                break;
                            case '!':
                                tokens.push_back(Token(TOKEN_NOT, s, line_no));
                                break;
                            case '?':
                                tokens.push_back(Token(TOKEN_TERNARY_1, s, line_no));
                                break;
                            case ':':
                                tokens.push_back(Token(TOKEN_TERNARY_2, s, line_no));
                                break;
                            default:
                                break;
                        }
                    }
                }
                right++;
                left = right;
                }
                else if (isPunctuator(str[right]) == true && left != right
                    || (right == len && left != right)) 			//check if parsed substring is a keyword or identifier or number
                {
                char* sub = subString(str, left, right - 1);   //extract substring

                if (isKeyword(sub) == true)
                            {
                                //tokens.push_back(Token(TOKEN_KEYWORD, sub, line_no));
                                //cout<<"Line no "<< line_no<< ", "<< sub <<" IS A KEYWORD\n";
                            }
                else if (isNumber(sub) == true)
                            {
                                //cout<< sub <<" IS A NUMBER\n";
                            }
                else if (validIdentifier(sub) == true
                        && isPunctuator(str[right - 1]) == false && (int)sub[0]!=0)
                        {
                            tokens.push_back(Token(TOKEN_IDENTIFIER, sub, line_no));
                        }
                else if (validIdentifier(sub) == false
                        && isPunctuator(str[right - 1]) == false && (int)sub[0]!=0)
                        {
                            tokens.push_back(Token(TOKEN_ERROR, sub, line_no));
                            //cout<<"Line no "<< line_no<< ", "<< sub <<" IS NOT A VALID IDENTIFIER\n";
                        }

                left = right;
                }
        }
        line_no++;
        return;
    }
    void printList(){
        for(auto &i: tokens){
           i.printToken();
        }
    }
};

int main()
{
    string filename;
    cout << "Please enter the name of the text file with the code you wish parsed: " <<endl;
    cin >> filename;
    ifstream infile(filename);
    cout << "\n\nOUTPUT\n\n"<<endl;
    Lexer lex;
    while (infile.good()){
        string sLine;
        getline(infile, sLine);
        char* line;
        line = &sLine[0];
        //cout << line;
        lex.parse(line);
    }
    lex.printList();
    cout<<"END OF PROGRAM"<<endl;
    return 0;
}
