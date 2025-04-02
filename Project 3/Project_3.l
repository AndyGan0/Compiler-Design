%{
#include <string.h>
void doesntRepeat(char input[]);
%}

 



%%


"σημείο "[A-Z] {printf("%s is accepted\n", yytext);}
"ευθεία "[A-Z]{2} {doesntRepeat(yytext);}
"τρίγωνο "[A-Z]{3} {doesntRepeat(yytext);}
"τετράγωνο "[A-Z]{4} {doesntRepeat(yytext);}
"πεντάγωνο "[A-Z]{5} {doesntRepeat(yytext);}
"εξάγωνο "[A-Z]{6} {doesntRepeat(yytext);}
"επτάγωνο "[A-Z]{7} {doesntRepeat(yytext);}
"οκτάγωνο "[A-Z]{8} {doesntRepeat(yytext);}
.


%%


int yywrap(){}




void doesntRepeat(char input[]) {

	//	make START show at the beginning of the symbols	
	int START = 0;
	while (input[START] != ' ') {
		START++;
	}
	START++;


	//	for each symbol from START
	
	while (START != strlen(input)) {

		//	check if its the same as any other symbol after START
		for (int k = START+1; k < strlen(input); k++) {
			if (input[START] == input[k]) {
				//	if at least 2 symbols are the same, return
				return;
			}
		}
		START++;

	}

	//	print accepted
	printf("%s is accepted\n", input);
	return;
}





int main( int argc, char **argv ) {

	++argv, --argc;
	if ( argc > 0 )
	yyin = fopen( argv[0], "r" );
	else
	yyin = stdin;
	yylex();
  
	return 0;
}