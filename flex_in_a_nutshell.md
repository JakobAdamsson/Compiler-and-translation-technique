# General + Syntax
Flex files are defined with .l extentions.  
When a .l file is invoked, a lex.yy.c file is created. This file provides an **extern** function called **yylex()** that will can one token. The scanner reads from stdin and outputs in stdout by default.  

### Structure of a flex file
```
%{
Declarations
%}

Definitions

%%
Rules
%%

User subroutines
```

### Flex rules
A rule has a regular expression(pattern) and is an associated set of C statements(action). The idea is that when the scanner reads an input sequence that matches the patthern(expression), it executes the action to process it.

General syntax:  
```c
Character classes [0-9]. May also look like [0-9A-Za-z] or [aeiou0-9]

Character exclusion ^(complement), e.g [^0-9] will match any non-digit character

Arbitrary character . will match any character except newline

Single repetition x? means 0 or 1 occurances of x

Non-zero repetition x+ or xx* means that x is repeated one or more times

Specified repetition x{n, m} means that x is repeated between n and m times

Beginning of line ^x matches x at beginning of line ONLY

End of line x$ matches x at end of line ONLY

Context-sensitivity ab/cd means that ab is matched only when followed by cd

Literal strings "x" dont know

Definitions {name} replaces the earlier defined pattern called name, makes patterns more readable
```

The scanner reads characters from the file and will gather them until it forms the longest possible match for any of the available patterns. If there are two or more patterns that are equally long, the first pattern is chosen.

### Flex global variables
- The token grabbing function **yylex()** takes no arguments and returns an integer.  
- **yytext()** is a null terminated string containing the text of the lexeme just recognized as a token and is managed in the lex.yy.c file
- **yyleng()** is the global variable that stores attributes about the togen, e.g for an integer lexeme it might store the value, for a string literal, the pointer to its characters and so on. This variable is of typ **YYSTYPE** and is usually a union of all the various fields needed for different token types.
- **yyloc()** is the global variable that is used to store the location(line and column) of the token. THis variable is declared of type **YYSTYPE**
