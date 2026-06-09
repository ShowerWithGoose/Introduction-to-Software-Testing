#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal); // @@ [The program uses hardcoded conditionals to guess the output based on input characters instead of actually parsing and evaluating the arithmetic expression. This approach fails for general inputs and only appears to handle a few specific test cases by coincidence.]
    if(cal[1]-'0'==0){ // @@ [This condition assumes the second character is a digit and checks if it's '0', which is not a valid way to parse expressions. It ignores spaces and operator precedence.]
        printf("%d",0);
        return 0;
    }
    else if(cal[0]-'0'==1){ // @@ [Hardcoding behavior based on the first digit being '1' is incorrect; the program should parse numbers properly, not assume fixed positions or values.]
        if(cal[2]-'0'==0){ // @@ [Assumes the third character is a digit and part of the number, ignoring possible spaces or multi-digit numbers.]
            printf("%d",12000);
            return 0;
        }
        else{
            printf("%d",602); // @@ [This outputs the expected answer for the given test case but does so by hardcoding, not by computation. It will fail on any other valid input.]
            return 0;
        }
    }
    else if(cal[0]-'0'==2){ // @@ [Again, hardcoded logic for inputs starting with '2'; completely bypasses actual expression evaluation.]
        if(cal[15]=='*'){ // @@ [Arbitrarily checks position 15 for an operator, which is unreliable due to variable spacing and expression length.]
            printf("%d",24);
            return 0;
        }
        else{
            printf("%d",211);
            return 0;
        }
    }
    
    return 0;
}