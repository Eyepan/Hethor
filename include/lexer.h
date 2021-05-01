#ifndef LEXER_H
#define LEXER_H
#include <token.h>

typedef struct LEXER_STRUCT
{
	char currentChar;
	unsigned int idx;
	char* contents;
} lexer_T;

lexer_T* initLexer(char* contents);

void lexer_advance(lexer_T* lexer);
void lexer_skipWhitespace(lexer_T* lexer);
token_T* lexer_getNextToken(lexer_T* lexer);
token_T* lexer_makeString(lexer_T* lexer);
token_T* lexer_makeID(lexer_T* lexer);
token_T* lexer_advanceWithToken(lexer_T* lexer, token_T* token);

char* lexer_getCurrentCharAsString(lexer_T* lexer);


#endif // LEXER_H