#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal); // @@ [Using unsafe gets() function; also, the program does not parse the expression, it relies on hardcoded conditions instead of evaluating the arithmetic expression.]
    if(cal[1]-'0'==0){ // @@ [Hardcoded condition that does not evaluate the actual expression; program should compute the result from the input, not check specific positions.]
        printf("%d",0); // @@ [Hardcoded output; does not reflect the true result of the expression.]
        return 0;
    }
    else if(cal[0]-'0'==1){ // @@ [Hardcoded condition; program should not depend on the first character alone to decide the output.]
        if(cal[2]-'0'==0){ // @@ [Hardcoded nested condition; ignores the actual mathematical evaluation.]
            printf("%d",12000); // @@ [Hardcoded output; not the correct result for an arbitrary expression.]
            return 0;
        }
        else{
            printf("%d",602); // @@ [Hardcoded output; program does not compute the expression.]
            return 0;
        }
    }
    else if(cal[0]-'0'==2){ // @@ [Hardcoded condition; no generalization.]
        if(cal[15]=='*'){ // @@ [Hardcoded check based on index 15; only works for specific input length and characters.]
            printf("%d",24); // @@ [Hardcoded output; not computed.]
            return 0;
        }
        else{
            printf("%d",211); // @@ [Hardcoded output; program fails for any other input.]
            return 0;
        }
    }
    
    return 0;
}