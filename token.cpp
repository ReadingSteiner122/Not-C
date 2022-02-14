//
//  token.h
//  TildeC
//
//  Created by Sanath Salil on 02/02/22.
//

#include "token_type.h"
#include "token.h"
#include <string>

Token::Token(TokenType type, string lexeme, string literal, int line){
    this->type = type;
    this->lexeme = lexeme;
    this->literal = literal;
    this->line = line;
}

string Token::toString(){
    return lexeme + " " + literal;
}

