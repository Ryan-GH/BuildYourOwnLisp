// Chapter 6 Bonus Marks
/*
Man this chapter was tougher than previous ones.
<<Write a regex matching strings of all a or b such as 'aababa' or 'bbaa'>>
	First try: /^a+b+$/
	This only matches strings of a followed by b, like aaabb
	
	I think /^[ab]+$/ works better.
	For each character, checks if it is within the set [ab]. Requires 1 or more (+).
	
<<Write a regular expression matching pit, pot and respite but not peat, spit, or part>>
	I'm using https://regexr.com to test these.
	
	Needs to allow 'pit' and 'pot'.
	Needs to allow 'respite'.
	Needs to reject 'peat', 'spit', 'part'. ALl of which containt p + vowel + t.
	
	So we need p + (i or o) + t as a standalone substring.
	I don't really know how to do this as a pattern. You can do p[io]t to capture pit and pot.
	But it doesn't match respite.
	You can just do this: 
		^(?:pit|pot|respite)$
	But I don't think this is the approach being asked.
	
	(?: is the non capturing group: Groups multiple tokens together without creating a capture group.
	
<< Change the grammar to add a new operator such as % >>

	This is a simple matter of adding it to the string:
	operator : '+' | '-' | '*' | '/' | '%' ;
	
<< Change the grammar to recognise operators written in textual format 'add', 'sub', 'mul', 'div'	
	
	I don't know how to do this. Passing them in as string literals makes Lispy show an error
	<stdin>: error: Parser Undefined!
	This is because the grammar being passed to mpca_lang is incorrect. But I don't know how to correct it.
	I tried using regular expressions. /add/ /sub/ /mul/ /div/
	This worked I think ,but for the wrong reasons. It was only matching the first letter. idk maybe im dumb
	but I'm moving on. Hopefully I figure it out as I progress.

<<Change the grammar to recognize decimal numbers such as 0.01, 5.21, or 10.2>>
	For this the grammar needs to be updated so that the regex for 'number' supports decimals.
	This took me ages. You can keep the existing regex:
	/-?[0-9]+/
	Which reads like this:
	First, -? means optional negative sign.
	[0-9]+ The  + means at least one. Then any digit. So, at least one of any digit.
	
	Now, if the number is decimal, it will have a point (.) followed by at least one decimal number.
	But the whole thing is optional, so there is a ? on the end.
	.[0-9]+?
	The . by itself means 'any character is required'. We need to escape the character so that it is a
	literal point. Backslash is the escape character in regex. Also, put the whole thing in brackets because
	everything after the last whole digit is optional.
	(\.[0-9]+)?
	
	Putting everything together:
	/-?[0-9]+(\.[0-9]+)?/
	
	This works. However I'm now getting a compilation warning:
	.\parsingCH6.c: In function 'main':
	.\parsingCH6.c:110:12: warning: unknown escape sequence: '\.'
	  110 |           ",
		  |   
	
	Can't really tell which it is having a problem with: The escape \., or the end of the string (",)
	
	
*/


#include "mpc.h"

#include <stdio.h>
#include <stdlib.h>



/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {

	/* Create Some Parsers */
	mpc_parser_t* Number   = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr     = mpc_new("expr");
	mpc_parser_t* Lispy    = mpc_new("lispy");

	/* Define them with the following Language */
	mpca_lang(MPCA_LANG_DEFAULT,
	  "                                                     \
		number   : /-?[0-9]+(\.[0-9]+)?/ ;                  \
		operator : '+' | '-' | '*' | '/' ;                  \
		expr     : <number> | '(' <operator> <expr>+ ')' ;  \
		lispy    : /^/ <operator> <expr>+ /$/ ;             \
	  ",
	  Number, Operator, Expr, Lispy);


  puts("Lispy Version 0.0.0.0.1");
  puts("^_^\nPress Ctrl+c to Exit\n");

  while (1) {

    /* Now in either case readline will be correctly defined */
    char* input = readline("Lispy> ");
    add_history(input);

    /* Attempt to Parse the user Input */
	mpc_result_t r;
	if (mpc_parse("<stdin>", input, Lispy, &r)) {
	  /* On Success Print the AST */
	  mpc_ast_print(r.output);
	  mpc_ast_delete(r.output);
	} else {
	  /* Otherwise Print the Error */
	  mpc_err_print(r.error);
	  mpc_err_delete(r.error);
	}
    free(input);

  }

	/* Undefine and Delete our Parsers */
	mpc_cleanup(4, Number, Operator, Expr, Lispy);
	
  return 0;
}