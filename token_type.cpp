//
//  token_type.h
//  TildeC
//
//  Created by Sanath Salil on 02/02/22.
//

typedef enum TokenType{
    //type keywords
    TOKEN_NULL,
    TOKEN_BOOL,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_ARRAY,
    
    //other keywords
    TOKEN_PRINT,
    TOKEN_RETURN,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_FOR,
    TOKEN_BREAK,
    TOKEN_DO,
    TOKEN_CONTINUE,
    TOKEN_IMPORT,
    TOKEN_EXPORT,
    TOKEN_CONST,
    TOKEN_VAR,
    
    //literals
    TOKEN_IDENTIFIER,
    TOKEN_INT_LITERAL,
    TOKEN_FLOAT_LITERAL,
    TOKEN_STRING_LITERAL,
    TOKEN_LITERAL_TRUE,
    TOKEN_LITERAL_FALSE,
    
    //math operators
    TOKEN_PLUS,
    TOKEN_PLUS_PLUS,
    TOKEN_PLUS_EQUAL,
    
    TOKEN_MINUS,
    TOKEN_MINUS_MINUS,
    TOKEN_MINUS_EQUAL,
    
    TOKEN_MULTIPLY,
    TOKEN_MULTIPLY_EQUAL,
    
    TOKEN_DIVIDE,
    TOKEN_DIVIDE_EQUAL,
    
    TOKEN_MODULO,
    TOKEN_MODULO_EQUAL,
    
    //bitwise and logical operators
    TOKEN_NOT,
    TOKEN_NOT_EQUAL,
    
    TOKEN_GREATER,
    TOKEN_GREATER_EQUAL,
    
    TOKEN_LESS,
    TOKEN_LESS_EQUAL,
    
    TOKEN_EQUAL,
    TOKEN_EQUAL_EQUAL,
    
    TOKEN_AND,
    TOKEN_AND_AND,
    
    TOKEN_OR,
    TOKEN_OR_OR,
    
    //single character tokens
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    
    TOKEN_LEFT_BRACE,
    TOKEN_RIGHT_BRACE,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_SEMICOLON,
    TOKEN_SLASH,
    
    //meta operators
    TOKEN_PASS,
    TOKEN_ERROR,
    TOKEN_EOF
} TokenType;
