%{
    int numChars = 0, numWords = 0, numLines = 0;
%}
%%
\n          {numLines++; numChars++;}
[^ \t\n]+   {numWords++; numChars += yyleng;} 
.           {numChars++;}
%%
int main() {
    yylex();
    if (numChars > 25)
    {
        printf("Emil gillar inte att läsa så mycket.\n");
    }
    printf("%d\t%d\t%d\n", numChars, numWords, numLines);






}