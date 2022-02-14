//
//  token.h
//  TildeC
//
//  Created by Sanath Salil on 02/02/22.
//

#ifndef token_h
#define token_h
#include "token_type.h"
#include <string>

using namespace std;
class Token{
    TokenType type;
    string lexeme;
    string literal;
    int line;
    
    public:
    Token(TokenType type, string lexeme, string literal, int line);
    string toString();
};

#endif /* token_h */
