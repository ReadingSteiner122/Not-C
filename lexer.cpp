//
//  lexer.cpp
//  TildeC
//
//  Created by Sanath Salil on 02/02/22.
//

#include <stdio.h>
#include "token_type.hpp"
#include "token.hpp"
#include <list>

class Lexer{
    private final String source;
    private final list<Token> tokens;
    private int start = 0;
    private int current = 0;
    private int line = 1;
    
    Lexer(String source){
        this.source = source;
    }
    
    private boolean isAtEnd(){
        return current >= source.size();
    }
    
    private char advance(){
        return source.at(current++);
    }
    
    private void addToken(TokenType type, String literal){
        String text = source.substring(start, current);
        tokens.add(Token(type, lexeme, literal, line));
    }
    
    private void addToken(TokenType type){
        addToken(type, "");
    }
    
    private void scanToken(){
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
    
    list<Token> scanTokens(){
        while(!isAtEnd()){
            start = current;
        }
        tokens.push_back(Token(EOF, "", null, line));
        return tokens;
    }
}
