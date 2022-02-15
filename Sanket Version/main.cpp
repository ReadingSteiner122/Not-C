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

using namespace std;


class Lexer{
    int line_no;
    list<Token> tokens;
    bool isPunctuator(char ch)					//check if the given character is a punctuator or not
    {
        if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
            ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
            ch == '&' || ch == '|')
            {
                return true;
            }
        return false;
    }

    bool validIdentifier(char* str)						//check if the given identifier is valid or not
    {
        if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
            str[0] == '3' || str[0] == '4' || str[0] == '5' ||
            str[0] == '6' || str[0] == '7' || str[0] == '8' ||
            str[0] == '9' || isPunctuator(str[0]) == true)
            {
                return false;
            }									//if first character of string is a digit or a special character, identifier is not valid
        int i,len = strlen(str);

        if (len == 1)
        {
            return true;
        }										//if length is one, validation is already completed, hence return true
        else
        {
        for (i = 1 ; i < len ; i++)						//identifier cannot contain special characters
        {
            if (isPunctuator(str[i]) == true)
            {
                return false;
            }
        }
        }
        return true;
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
            || !strcmp(str, "while") || !strcmp(str, "until")
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
                if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                    && str[i] != '3' && str[i] != '4' && str[i] != '5'
                    && str[i] != '6' && str[i] != '7' && str[i] != '8'
                    && str[i] != '9' || (str[i] == '-' && i > 0))
                    {
                        return false;
                    }
            }
            tokens.push_back(Token(TOKEN_INT_LITERAL, str, line_no));
            cout<<"Line no "<< line_no<< ", "<< str <<" IS A INTEGER LITERAL\n";
            return true;
        }
        else{
            int non_num=0;
            for(i = 0; i < len; i++){
                if(str[i]!=0 && str[i] != '1' && str[i] != '2'
                    && str[i] != '3' && str[i] != '4' && str[i] != '5'
                    && str[i] != '6' && str[i] != '7' && str[i] != '8'
                    && str[i] != '9'){
                        non_num++;
                    }
                if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                    && str[i] != '3' && str[i] != '4' && str[i] != '5'
                    && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '.'
                    && str[i] != '9' || (str[i] == '-' && i > 0))
                    {
                        return false;
                    }
                if(non_num>=2)
                    return false;
            }
            tokens.push_back(Token(TOKEN_FLOAT_LITERAL, str, line_no));
            cout<<"Line no "<< line_no<< ", "<< str <<" IS A FLOAT LITERAL\n";
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
    }
    void parse(char* str)						//parse the expression
    {
        int left = 0, right = 0;
        int len = strlen(str);
        while (right <= len && left <= right) {
            if(str[right] == '\\' && str[right+1] == '\\'){
                break;
            }
            if(str[right] == '\"'){
                int l1 = right;
                right++;
                while(str[right]!='\"' || (str[right]=='\"' && str[right-1]=='\\'))
                    right++;
                char* sub = subString(str, l1, right);
                tokens.push_back(Token(TOKEN_STRING_LITERAL, sub, line_no));
                right = right + 1;
                left = right;
            }
            if (isPunctuator(str[right]) == false)			//if character is a digit or an alphabet
                {
                    right++;
                }
            if (isPunctuator(str[right]) == true && left == right)		//if character is a punctuator
                {
                //
                char punct=str[right];
                if(punct==' '){}
                else if(punct=='\n'){}
                else if(punct==','){
                    string s(1, punct);
                    tokens.push_back(Token(TOKEN_COMMA, s, line_no));
                    std::cout<<"Line no "<< line_no<< ", "<< str[right] <<" IS AN DELIMITER OR SEPARATOR\n";
                    }
                else if(punct==';'){
                    string s(1, punct);
                    tokens.push_back(Token(TOKEN_SEMICOLON, s, line_no));
                    std::cout<<"Line no "<< line_no<< ", "<< str[right] <<" IS AN DELIMITER OR SEPARATOR\n";
                    }
                else if(punct=='(' || punct==')'){
                    string s(1, punct);
                    if(punct == '(')
                        tokens.push_back(Token(TOKEN_LEFT_BRACE, s, line_no));
                    else
                        tokens.push_back(Token(TOKEN_RIGHT_BRACE, s, line_no));
                    std::cout<<"Line no "<< line_no<< ", "<< str[right] <<" IS AN DELIMITER OR SEPARATOR\n";
                    }
                else if(punct=='[' || punct==']'){
                    string s(1, punct);
                    if(punct == '[')
                        tokens.push_back(Token(TOKEN_LEFT_SQUARE_BRACKET, s, line_no));
                    else
                        tokens.push_back(Token(TOKEN_RIGHT_SQUARE_BRACKET, s, line_no));
                    std::cout<<"Line no "<< line_no<< ", "<< str[right] <<" IS AN DELIMITER OR SEPARATOR\n";
                    }
                else if(punct=='{' || punct=='}'){
                    string s(1, punct);
                    if(punct == '{')
                        tokens.push_back(Token(TOKEN_LEFT_PAREN, s, line_no));
                    else
                        tokens.push_back(Token(TOKEN_RIGHT_PAREN, s, line_no));
                    std::cout<<"Line no "<< line_no<< ", "<< str[right] <<" IS AN DELIMITER OR SEPARATOR\n";
                    }

                else if (isOperator(str[right]) == true)
                {
                    if(right<len && isOperator(str[right+1])){
                        string s1(1, str[right]);
                        string s2(1, str[right+1]);
                        string s = s1 + s2;
                        int flag = 1;
                    switch(str[right]){
                        case '+':
                            if(str[right+1] == '=')
                                tokens.push_back(Token(TOKEN_PLUS_EQUAL, s, line_no));
                            else if(str[right+1] == '+')
                                tokens.push_back(Token(TOKEN_PLUS_PLUS, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '-':
                            if(str[right+1] == '=')
                                tokens.push_back(Token(TOKEN_MINUS_EQUAL, s, line_no));
                            else if(str[right+1] == '-')
                                tokens.push_back(Token(TOKEN_MINUS_MINUS, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '*':
                            if(str[right+1] == '=')
                                tokens.push_back(Token(TOKEN_MULTIPLY_EQUAL, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '/':
                            if(str[right+1] == '=')
                                tokens.push_back(Token(TOKEN_DIVIDE_EQUAL, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '>':
                            if(str[right+1] == '=')
                                tokens.push_back(Token(TOKEN_GREATER_EQUAL, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '<':
                            if(str[right+1] == '=')
                                tokens.push_back(Token(TOKEN_LESS_EQUAL, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '=':
                            if(str[right+1] == '=')
                                tokens.push_back(Token(TOKEN_EQUAL_EQUAL, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '|':
                            if(str[right+1] == '|')
                                tokens.push_back(Token(TOKEN_OR_OR, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '&':
                            if(str[right+1] == '&')
                                tokens.push_back(Token(TOKEN_AND_AND, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '%':
                            if(str[right+1] == '=')
                                tokens.push_back(Token(TOKEN_MODULO_EQUAL, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        case '!':
                            if(str[right+1] == '=')
                                tokens.push_back(Token(TOKEN_NOT_EQUAL, s, line_no));
                            else{
                                tokens.push_back(Token(TOKEN_ERROR, s, line_no));
                                std::cout<<"INVALID TOKEN\n";
                                flag = 0;
                            }
                            break;
                        default:
                            cout<<"INVALID TOKEN\n";
                            break;
                        }
                        if(!flag)
                            std::cout<<"Line no "<< line_no<< ", "<< str[right] << str[right+1]<<" IS AN OPERATOR\n";
                        right++;
                        goto here;
                    }
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
                    std::cout<<"Line no "<< line_no<< ", "<< str[right] <<" IS AN OPERATOR\n";
                }
                here:
                right++;
                left = right;
                } else if (isPunctuator(str[right]) == true && left != right
                    || (right == len && left != right)) 			//check if parsed substring is a keyword or identifier or number
                {
                char* sub = subString(str, left, right - 1);   //extract substring

                if (isKeyword(sub) == true)
                            {
                                //tokens.push_back(Token(TOKEN_KEYWORD, sub, line_no));
                                cout<<"Line no "<< line_no<< ", "<< sub <<" IS A KEYWORD\n";
                            }
                else if (isNumber(sub) == true)
                            {
                                //cout<< sub <<" IS A NUMBER\n";
                            }
                else if (validIdentifier(sub) == true
                        && isPunctuator(str[right - 1]) == false && (int)sub[0]!=0)
                        {
                            tokens.push_back(Token(TOKEN_IDENTIFIER, sub, line_no));
                            cout<<"Line no "<< line_no<< ", "<< sub <<" IS A VALID IDENTIFIER\n";

                        }
                else if (validIdentifier(sub) == false
                        && isPunctuator(str[right - 1]) == false && (int)sub[0]!=0)
                        {
                            tokens.push_back(Token(TOKEN_ERROR, sub, line_no));
                            cout<<"Line no "<< line_no<< ", "<< sub <<" IS NOT A VALID IDENTIFIER\n";
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
    ifstream infile("sample.txt");
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
    return 0;
}
