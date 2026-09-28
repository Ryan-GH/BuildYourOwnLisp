// Bonus Marks Exercises
// https://www.buildyourownlisp.com/chapter3_basics

/*
	<<What built in types are there other than the ones used?>>
		So far I've only used ints, and string literals.
		There are also:
			-float: 4 byte floating point number
			-double: 8 byte floating point number
			-char: 1 byte character
			
			-void: represents no value or empty type. I don't know how much space it takes.
				-(I probably could have used void as the type for my functions here?)
				-I looked it up. Apparently: no size. 
				-Apparently sizeof(void) can cause compile-time errors under strict ANSI-C guidelines.
			
			-bool (boolean) is not a built in type. Must be included with <stdbool.h>
			-I think that's about it for primitive data types. It's a lot less than Java, from my memory.
			
	<<What other conditional operators are there, other than > and <? >>
		&&: and
		||: or
		>=: greater than or equal to
		<=: lesser than or equal to 
		==: equal to 
		!=: not equal to 
		I think that's it?
		
	<<What other mathematical operators are there, aside from + and - ? >>
		*: multiply
		/: divide
		%: modulus, returns the remainder
		
	<< What is the += operator, how does it work? >>
		adds amount to a variable. Common in many languages.
		int x = 3;
		x += 3; // x now holds a value of 6 (3 + 3 = 6). Shorthand for x = x + 3;
		-=, *= and /= may be possible too but I don't know for sure.
	
	<< what is the do loop, how does it work? >>
		Also known as do/while loop.
		Different from a while loop in that the code inside the curly brackets will always
		execute at least once.
		I'll write one and invoke it in main().
		
	<< What is the switch statement and how does it work? >>
		Lets you execute code blocks based on the input. Saves you from writing many switch statements.
		switch(variable) {
			case x:
				//code block
				break;
			case y:
				//code block
				break;
			default:
				//code block
		}
			note the use of break; which exits the switch code block instead of continuing through each option.
			
	<<	What is the break keyword and what does it do? >>
		Kinda just addressed this question above. It breaks you out of a code block. 
		In the switch statement is stops the computer from checking each case after a code block has already been resolved.
		In my example, if the vairable is x, the computer checks case x (true), executes the code block. It would be a waste
		of resources for it the then check case y, case z, then do the default, then exit the code block.
		Also, default doesn't need a break; because it is the last item and there is nothing to check after anyway.
		
	<< What is the continue keyworkd and what does it do? >>
	So. break; can pop you out of a loop entirely. The continue statement breaks just one iteration of the loop.
	I think it just restarts the loop. I'll write a function to demonstrate. So, break skips the loop, and continue skips 
	this round but keeps going.
	
	<< wat do typedef rly do tho ? >>
	Reading this off of w3schools:
	The typedef keyword lets you creat a new name for an existing type (an alias). This basically makes your code easier
	to read and maintain.
	
	So for example instead of writing
	float todayTemp = 25.5;
	float tomorrowTemp = 19.0;
	
	You can instead write:
	typedef float Temperature;
	Temperature today = 25.5;
	Temperature tomorrow = 19.0;
	
	So it goes typedef [data type] [name of type (you choose)]
	Use it with struct to create new data types/something like an object. I'm not showing an example because I'm tired.
	Nevermind here you go
	//without typedef
	struct Phone {
		char brand[30]; //this is a string i think
		int year;
	}
	
	//with typedef
	typedef struct {
		char brand[30];
		int year;
	} Phone;   // Phone at the end is the important bit!
	
	int main() {
		struct Phone phone1 = {"Blackberry", 2007}; //needs struct
		Phone phone2 = {"Trump Phone", 2026}; //Doesn't need struct. Also, how embarrassing :(
		
		printf("%s %d\n", phone1.brand, phone1.year);
		printf("%s %d\n", phone2.brand, phone2.year); //both work but not having to write struct is very good.
		
		return 0;
	}
	
*/

#include <stdio.h>

int forWorld() {
	
	for(int i = 5; i > 0; i--) {
		puts("For Hello World :)");
	}
	
	return 0;
}

int whileWorld() {
	int i = 0;
	while (i < 5) {
		puts("While Hello World :@");
		i++;
	}
	i = 0;
	return i;	
}

int nWorld(int n) {
	n = 0;
	while (n < 5) {
		puts("Hello n");
		n++;
	}
	return 0;
}

void doWhileWorld() {
	
	int i = 0;
	do {
		puts("Hello Dowhile 1");
	} while (i < 0); // even though i is already 0, the code in the curlies executes anyway.
	
	// i remains unincremented
	
	do {
		puts("Hello Dowhile 2");
		i++;
	} while (i < 3);
	
}


// This prints to the console 0, 1, 3 and 4. Note that 2 is skipped.
void continueWorld() {
	
	for (int i = 0; i < 5; i++) {
		if (i == 2) {
			continue;
		}
		printf("%d\n", i); //printf formatted output!! yay
	}
	
}


int main(int argc, char** argv) {
	
	forWorld();
	whileWorld();
	nWorld(10);
	doWhileWorld();
	continueWorld();
	
}	
