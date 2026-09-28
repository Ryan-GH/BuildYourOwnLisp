#include <stdio.h>

// Declare buffer for user input. Size of 2048
static char input[2048];

int main(int argc, char** argv) {
	
	// Print version and exit info
	puts("Lispy Vesion 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");
	
	// loop forever and ever for all time
	while (1) {
		// Output prompt
		fputs("lispy> ", stdout);
		
		// Read a line of user input of max size 2048
		// char* fgets( char* str, int count, FILE* stream)  Essentially: Where its writing to, max size, where it's reading from.
		fgets(input, 2048, stdin);
		
		// Echo input back to user
		printf("No, you're a %s", input);
	}
	
	return 0;
}