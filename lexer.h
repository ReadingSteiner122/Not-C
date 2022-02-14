
#ifndef lexer_h
#define lexer_h
#include "token_type.h"
#include "token.h"
#include<string>
#include<list>
using namespace std;


class Lexer{
    string source;
    list<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;
    
    Lexer(string source);
    
    bool isAtEnd();
    char advance();
    
    void addToken(TokenType type, string literal);
    
    void addToken(TokenType type);
    
    void scanToken();
    
    list<Token> scanTokens();
};

#endif /* lexer_h */