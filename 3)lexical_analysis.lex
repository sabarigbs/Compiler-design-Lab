%{
%}
Letter[a-zA-Z_]+
Number[0-9]+
Keyword"auto"|"double"|"int"|"struct"|"break"|"else"|"long"|"switch"|"case"|"enum"|"register"|"typedef"|"char"|"extern"|"return"|"union"|"const"|"float"|"short"|"unsigned"|"continue"|"for"|"signed"|"void"|"default"|"goto"|"sizeof"|"volatile"|"do"|"if"|"static"|"while"
%%
[#]+[a-z]+[<]+[a-z]+[".h"][>]+ printf("%s is a header file \n",yytext);
{Keyword} printf("%s is a keyword \n",yytext);
"printf()"|"scanf()" printf("%s is an inbuilt function\n",yytext);
{Letter}+{Number}* 	printf("%s is an identifier \n",yytext);
{Number}*[.]?{Number}+ printf("%s is a number \n",yytext);
[+|-|*|%|/|=]   printf("%s is an operaotr \n",yytext);
{Letter}+[(][)] printf("%s is a function \n",yytext);
[{] printf("%s is a Opening Curly brace \n",yytext);
[}] printf("%s is a Closing Curly brace \n",yytext);
;		  printf("%s is a delimiter \n",yytext);
%%
int yywrap(void)
{

	return 1;
}
int main(int argc,char *str[])
{
	
	yylex();
	return 0;
}