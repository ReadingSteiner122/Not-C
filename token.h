//
//  token.h
//  TildeC
//
//  Created by Sanath Salil on 02/02/22.
//

#ifndef token_h
#define token_h
#include "token_type.hpp"
#include <string>

class Token{
    TokenType type;
    String lexeme;
    String literal;
    int line;
    
    Token(TokenType type, String lexeme, String literal, int line){
        this.type = type;
        this.lexeme = lexeme;
        this.literal = literal;
        this.line = line;
    }
    
    public String toString(){
        return type + " " + lexeme + " " + literal;
    }
};

#endif /* token_h */
