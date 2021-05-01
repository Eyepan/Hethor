#include <lexer.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

lexer_T* initLexer(char* contents)
{
	lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
	lexer->contents = contents;
	lexer->idx = 0;
	lexer->currentChar = contents[lexer->idx];

	return lexer;
}

void lexer_advance(lexer_T* lexer)
{
	if (lexer->currentChar != '\0' && lexer->idx < strlen(lexer->contents))
	{
		lexer->currentChar = lexer->contents[++lexer->idx];
	}
}

void lexer_skipWhitespace(lexer_T* lexer)
{
	while (lexer->currentChar == ' ' || lexer->currentChar == '\n')
	{
		lexer_advance(lexer);
	}
}
token_T* lexer_getNextToken(lexer_T* lexer)
{
	while (lexer->currentChar != '\0' && lexer->idx < strlen(lexer->contents))
	{
		if (lexer->currentChar == ' ' || lexer->currentChar == '\n')
			lexer_skipWhitespace(lexer);
		
		if (isalnum(lexer->currentChar))
			return lexer_makeID(lexer);
		
		if (lexer->currentChar == '"')
			return lexer_makeString(lexer);

		switch(lexer->currentChar)
		{
			case '=':
				return lexer_advanceWithToken(lexer, initToken(TT_EQUALS, lexer_getCurrentCharAsString(lexer)));
				break;
			case ';':
				return lexer_advanceWithToken(lexer, initToken(TT_SEMI, lexer_getCurrentCharAsString(lexer)));
				break;
			case '(':
				return lexer_advanceWithToken(lexer, initToken(TT_LPAREN, lexer_getCurrentCharAsString(lexer)));
				break;
			case ')':
				return lexer_advanceWithToken(lexer, initToken(TT_RPAREN, lexer_getCurrentCharAsString(lexer)));
				break;
		}
	}

	return (void*)0;
}

token_T* lexer_makeString(lexer_T* lexer)
{
	lexer_advance(lexer);
	char* value = calloc(1, sizeof(char));
	value[0] = '\0';

	while (lexer->currentChar != '"')
	{
		char* s = lexer_getCurrentCharAsString(lexer);
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);
		lexer_advance(lexer);
	}
	
	lexer_advance(lexer);
	return initToken(TT_STRING, value);
}


token_T* lexer_makeID(lexer_T* lexer)
{
	char* value = calloc(1, sizeof(char));
	value[0] = '\0';

	while (isalnum(lexer->currentChar))
	{
		char* s = lexer_getCurrentCharAsString(lexer);
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);
		lexer_advance(lexer);
	}

	return initToken(TT_ID, value);
}

token_T* lexer_advanceWithToken(lexer_T* lexer, token_T* token)
{
	lexer_advance(lexer);
	return token;
}

char* lexer_getCurrentCharAsString(lexer_T* lexer)
{
	char* str = calloc(2, sizeof(char));
	str[0] = lexer->currentChar;
	str[1] = '\0';
	return str;
}