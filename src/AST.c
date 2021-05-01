#include <AST.h>

AST_T* initAST(int type)
{
	AST_T* ast = calloc(1, sizeof(struct AST_STRUCT));
	ast->type = type;
	
	ast->varDefVarName = (void*)0; 
	ast->varDefValue = (void*)0;
	ast->varName = (void*)0;
	ast->funcCallName = (void*)0;
	ast->funcCallArgs = (void*)0;
	ast->funcCallArgsSize = 0;
	ast->stringVal = (void*)0;
	ast->compoundValue = (void*)0;
	ast->compoundSize = 0;
	return ast;
}

