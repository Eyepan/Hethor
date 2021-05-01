#include <stdio.h>
#include <lexer.h>

int main()
{
	printf("HETHOR\n");
	char* str = 
		"var name = \"Iyappan\";\n"
		"print(name);\n";
	lexer_T* lexer = initLexer(str);
	printf("%s\n", str);
	for (token_T* token = (void*)0; (token = lexer_getNextToken(lexer)) != (void*)0;)
	{
		printf("TOKEN{%d, %s}\n", token->type, token->value);
	}

	getchar();
	return 0;

}