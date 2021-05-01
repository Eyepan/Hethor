#include "../include/parser.h"


parser_T* initParser(lexer_T* lexer)
{
	parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
	parser->lexer = lexer;
	parser->currentToken = lexer_getNextToken(lexer);
	return parser;
}

void parser_eat(parser_T* parser, int tokType)
{
	if (parser->currentToken->type == tokType)
	{
		parser->currentToken = lexer_getNextToken(parser->lexer);
	}
	else
	{
		printf("UNEXPECTED TOKEN: %d:%s", parser->currentToken->type, parser->currentToken->value);
		exit(-1);
	}
}

// parse() method
AST_T* parser_parse(parser_T* parser)
{
	return parser_parseStatements(parser);
}

AST_T* parser_parseStatement(parser_T* parser)
{

}

AST_T* parser_parseStatements(parser_T* parser)
{
	AST_T* compound = initAST(AST_COMPOUND);
	compound->compoundValue = calloc(1, sizeof(struct AST_STRUCT*));
	// parse a statement
	AST_T* astStatement = parser_parseStatement(parser);
	compound->compoundValue[0] = astStatement;
	compound->compoundSize++;
	while(parser->currentToken->type == TT_SEMI)
	{
		parser_eat(parser, TT_SEMI);
		AST_T* astStatement = parser_parseStatement(parser);
		compound->compoundValue = realloc(compound->compoundValue, compound->compoundSize * sizeof(struct AST_STRUCT));
		compound->compoundValue[compound->compoundSize - 1] = astStatement;
		compound->compoundSize++;
	}

	return compound;
}

AST_T* parser_parseExpr(parser_T* parser)
{

}
AST_T* parser_parseFactor(parser_T* parser)
{

}
AST_T* parser_parseTerm(parser_T* parser)
{

}
AST_T* parser_parseFunctionCall(parser_T* parser)
{
	
}
AST_T* parser_parseVariable(parser_T* parser)
{

}
AST_T* parser_parseString(parser_T* parser)
{

}