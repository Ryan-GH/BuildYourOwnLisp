// Chapter 4-Interactive Prompt
/*
<<What other patterns can be used with printf?>>
	In this file we only use s (%s).
	Other options include:
		d or i: represents whole number as a decimal integer
		u: unsigned decimal integer
		o: octal integer
		x or X: hexadecimal integer
		f or F: floating point numbers
		e or E: represent floating point numbers in scientific notation
		g or G: General number; uses shortest option between f and e for a float
		a or A: Hexadecimal floating point number
		
		c: character. If an integer, represents it's ASCII.
		p: pointer. Represents the memory address of a pointer, usually with hex digits
		n: no output. I don't understand this one
		%: Represents a literal % character.
		
	Additionally there are many flags for formatting the output, justifying it, adding + to positive integers, etc.
		
<< What happens when you pass printf() a variable that doesn't match the pattern? >>		
	I tried it and recieved a compilation time error. It pointed out that I was putting a char* into an integer reciever.
	
<< What does the preprocessor command #ifndef do?>>
	#ifdef checks if a MACRO is defined. #ifndef does the opposite.
	I'm not yet sure what macros are. But in this code, the macro _WIN32 is defined on my windows machine, so that code
	is compiled, and the code after #else and before #endif is ignored for me.
	I read online that the C preprocessor only cares about macro definitions, not variables or symbols in your code.
	Macros are considered defined if
		-you used #define MACRO
		-you passed it via compiler tags like -DMACRO
		-another header defined it before this point
	I think _WIN32 is the universal 'im on windows' macro, even if you're on a 64-bit system (_WIN64 exists too).
	Compiler defines it automatically when you compile on Windows.

<<What does the preprocessor command #define do? >>
	I think it just defines a MACRO. The MACRO gets substituted during preprocessing time.
	eg:
	#define PI 3.14159
	...
	
	double area = PI * r * r;
	
	The preprocessor rewrites this before compilation, substituting PI for the value in the definition.
	
	Doesn't just do values. It can hold expressions too.
	eg:
	#define MAX(a,b) ((a) > (b) ? (a) : (b))
	These behave like inline functions, but they are not.
	
<<If _WIN32 is defined on windows, what is defined for Linux or Mac?>>
	They have their own built in compiler macros.
	For Linux:
		__linux__: The most standard one
		
	In practise, you check:
		#ifdef __linux__
			//linux specific code
		#endif
		
	For Apple platforms:
		__APPLE__: any apple OS, incl. tv, mobile, watch, etc
		__MACH__: indicates the Mach kernel
		
	MacOS detection:
		#if defined(__APPLE__) && defined(__MACH__)
			//apple code
		#endif
	
	If you wanna distinguish between macOS, iOS etc, look into <TargetConditionals.h>.
*/

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

  puts("Lispy Version 0.0.0.0.1");
  puts("^_^\nPress Ctrl+c to Exit\n");

  while (1) {

    /* Now in either case readline will be correctly defined */
    char* input = readline("cowboy> ");
    add_history(input);

    printf("What's that? %s?\n", input);
    free(input);

  }

  return 0;
}