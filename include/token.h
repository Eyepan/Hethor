#ifndef TOKEN_H
#define TOKEN_H

typedef struct TOKEN_STRUCT
{
	enum
	{
		TT_ID,
		TT_EQUALS,
		TT_STRING,
		TT_SEMI,
		TT_LPAREN,
		TT_RPAREN,
	} type;

	char* value;
} token_T;

token_T* initToken(int type, char* value);

#endif // TOKEN_H