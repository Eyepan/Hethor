#ifndef AST_H
#define AST_H
#include <ctype.h>
#include <stdlib.h>

typedef struct AST_STRUCT
{
	enum 
	{
		AST_VAR_DEF,
		AST_VAR,
		AST_FUNCTION_CALL,
		AST_STRING,
		AST_COMPOUND		// basically a tree/list of ast nodes
	} type;

	// AST variable definiion
	char* varDefVarName; 
	struct AST_STRUCT* varDefValue;

	// AST variable
	char* varName;

	// AST function call
	char* funcCallName;
	struct AST_STRUCT** funcCallArgs;
	size_t funcCallArgsSize;

	// AST string
	char* stringVal;
	
	// AST compound
	struct AST_STRUCT** compoundValue;
	size_t compoundSize;

} AST_T;

AST_T* initAST(int type);
#endif