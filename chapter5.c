//chapter 5 bbbbbonus marksssss
/*
<<Write down some more--
	I'll keep what remains of my dignity, thanks.
	
<<Why are there back slashes \ in front of the quote marks in the grammar?>>
	The entire thing is one big string. The backslash is an escape character that prevents the
	big string from meeting an untimely termination.
	
<<Why are there backslashes at the end of the line in the grammar?>>
	I thought it was an escape character for the new line, but that doesn't quite make sense.
	Apparently the backslash is a line-continuation character. String literals in C cannot go
	accross multiple lines unless this character is used. I think the same may also go for 
	MACRO definitions.
	
<<Describe textually a grammar for decimal numbers such as 0.01 or 52.221>>
	Guess you just want me to talk it out.
	In the case of larger numbers (like 52.221), we write out the first digit, then another, and another,
	until we get to the 'ones' column. We write the unit digit, and then a period (.). Then follow 
	the decimal digits. Note that we do not ever have leading zeroes when our number is 1 or greater
	(meaning, it is not written as 00052.221).
	However, when a number is less than 1 (but still positive, lets not overcomplicate), there is always 
	a single trailing zero (like for 0.01). Then the period follows, then the decimals.
	
	or maybe I was intended to describe which parts are nouns and adjectives? Verbs? Adverbs?
	Guess we'll never know. I'm done
	

*/

//this code is just for show. Don't compile. In fact,
#ifdef MEATBALLS
mpc_parser_t* Adjective = mpc_new("adjective");
mpc_parser_t* Noun      = mpc_new("noun");
mpc_parser_t* Phrase    = mpc_new("phrase");
mpc_parser_t* Doge      = mpc_new("doge");

mpca_lang(MPCA_LANG_DEFAULT,
  "                                           \
    adjective : \"wow\" | \"many\"            \
              |  \"so\" | \"such\";           \
    noun      : \"lisp\" | \"language\"       \
              | \"book\" | \"build\" | \"c\"; \
    phrase    : <adjective> <noun>;           \
    doge      : <phrase>*;                    \
  ",
  Adjective, Noun, Phrase, Doge);

/* Do some parsing here... */

mpc_cleanup(4, Adjective, Noun, Phrase, Doge);


#endif

int main()
{
	return 0;
}
 //guess what I had for dinner :p