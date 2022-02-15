typedef enum TokenType{
    //type keywords
    TOKEN_NULL, //0
    TOKEN_BOOL, //1
    TOKEN_INT, //2
    TOKEN_FLOAT, //3
    TOKEN_STRING, //4
    TOKEN_ARRAY, //5
    
    //other keywords
    TOKEN_KEYWORD, //6
    TOKEN_PRINT, //7
    TOKEN_RETURN, //8
    TOKEN_IF, //9
    TOKEN_ELSE, //10
    TOKEN_WHILE, //11
    TOKEN_FOR, //12
    TOKEN_BREAK, //13
    TOKEN_DO, //14
    TOKEN_CONTINUE, //15
    TOKEN_IMPORT, //16
    TOKEN_EXPORT, //17
    TOKEN_CONST, //18
    TOKEN_VAR, //19
    
    //literals
    TOKEN_IDENTIFIER, //20
    TOKEN_INT_LITERAL, //21
    TOKEN_FLOAT_LITERAL, //22
    TOKEN_STRING_LITERAL, //23
    TOKEN_LITERAL_TRUE, //24
    TOKEN_LITERAL_FALSE, //25
    
    //math operators
    TOKEN_PLUS, //26
    TOKEN_PLUS_PLUS, //27
    TOKEN_PLUS_EQUAL, //28
    
    TOKEN_MINUS, //29
    TOKEN_MINUS_MINUS, //30
    TOKEN_MINUS_EQUAL, //31
    
    TOKEN_MULTIPLY, //32
    TOKEN_MULTIPLY_EQUAL, //33
    
    TOKEN_DIVIDE, //34
    TOKEN_DIVIDE_EQUAL, //35
    
    TOKEN_MODULO, //36
    TOKEN_MODULO_EQUAL, //37
    
    //bitwise and logical operators
    TOKEN_NOT, //38
    TOKEN_NOT_EQUAL, //39
    
    TOKEN_GREATER, //40
    TOKEN_GREATER_EQUAL, //41
    
    TOKEN_LESS, //42
    TOKEN_LESS_EQUAL, //43
    
    TOKEN_EQUAL, //44
    TOKEN_EQUAL_EQUAL, //45
    
    TOKEN_AND, //46
    TOKEN_AND_AND, //47
    
    TOKEN_OR, //48
    TOKEN_OR_OR, //49
    
    //single character tokens
    TOKEN_LEFT_PAREN, //50
    TOKEN_RIGHT_PAREN, //51
    
    TOKEN_LEFT_SQUARE_BRACKET, //52
    TOKEN_RIGHT_SQUARE_BRACKET, //53
    TOKEN_LEFT_BRACE, //54
    TOKEN_RIGHT_BRACE, //55
    TOKEN_COMMA, //56
    TOKEN_DOT, //57
    TOKEN_SEMICOLON, //58
    TOKEN_SLASH, //59
    
    //meta operators
    TOKEN_PASS, //60
    TOKEN_ERROR, //61
    TOKEN_EOF, //62
    TOKEN_UNTIL, //63
    TOKEN_CHAR, //64
    TOKEN_TERNARY_1,
    TOKEN_TERNARY_2 //65
} TokenType;