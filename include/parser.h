#ifndef PARSER_H
#define PARSER_H
#include <stdlib.h>
#include <lexer.h>
#include <AST.h>
#include <stdio.h>

typedef struct PARSER_STRUCT
{
	lexer_T* lexer;
	token_T* currentToken;
} parser_T;

parser_T* initParser(lexer_T* lexer);

// parser, expect a certain token. If you get an unexpected token, die
// if not, advance and continue as always!
void parser_eat(parser_T* parser, int tokType);

// parse() method
AST_T* parser_parse(parser_T* parser);

AST_T* parser_parseStatement(parser_T* parser);
AST_T* parser_parseStatements(parser_T* parser);

AST_T* parser_parseExpr(parser_T* parser);
AST_T* parser_parseFactor(parser_T* parser);
AST_T* parser_parseTerm(parser_T* parser);
AST_T* parser_parseFunctionCall(parser_T* parser);
AST_T* parser_parseVariable(parser_T* parser);
AST_T* parser_parseString(parser_T* parser);


#endif