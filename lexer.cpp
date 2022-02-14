//
//  lexer.cpp
//  TildeC
//
//  Created by Sanath Salil on 02/02/22.
//

#include <stdio.h>
#include "token_type.h"
#include "token.h"
#include "lexer.h"
#include <list>
#include <iostream>




Lexer::Lexer(string source){
    this->source = source;
}
    
bool Lexer::isAtEnd(){
    return current >= source.size();
}
    
char Lexer:: advance(){
    return source.at(current++);
}
    
void Lexer::addToken(TokenType type, string literal){
    string text = source.substr(start, current);
    tokens.push_front(Token(type, text, literal, line));
}
    
void Lexer::addToken(TokenType type){
    addToken(type, "");
}
    
void Lexer::scanToken(){
    char c = advance();
    switch(c){
        case '(':
            addToken(TOKEN_LEFT_PAREN);
            break;
        case ')':
            addToken(TOKEN_RIGHT_PAREN);
            break;
        case '{':
            addToken(TOKEN_LEFT_BRACE);
            break;
        case '}':
            addToken(TOKEN_RIGHT_BRACE);
            break;
        case ',':
            addToken(TOKEN_COMMA);
            break;
        case '.':
            addToken(TOKEN_DOT);
            break;
        case '-':
            addToken(TOKEN_MINUS);
            break;
        case '+':
            addToken(TOKEN_PLUS);
            break;
        case ';':
            addToken(TOKEN_SEMICOLON);
            break;
        default:
            cout<<"Unexpected Character at Line no: "<<line;
            break;
    }
}
    
list<Token> Lexer::scanTokens(){
    while(!isAtEnd()){
        start = current;
    }
    tokens.push_back(Token(TOKEN_EOF, "", NULL, line));
    return tokens;
}