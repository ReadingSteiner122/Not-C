//
//  token.h
//  TildeC
//
//  Created by Sanath Salil on 02/02/22.
//

#include "token_type.h"
#include "token.h"
#include <string>
#include <iostream>

Token::Token(TokenType type, string lexeme, int line){
    this->type = type;
    this->lexeme = lexeme;
    this->line = line;
}

string Token::toString(){
    return lexeme + " " + literal;
}

void Token::printToken(){
    if(type == TOKEN_ERROR)
        std::cout<<"Token - ERROR, String - "<<lexeme<<", line no - "<<line<<"\n";
    else
        std::cout<<"Token - "<<type<<", String  - "<<lexeme<<", line no - "<<line<<"\n";
}

