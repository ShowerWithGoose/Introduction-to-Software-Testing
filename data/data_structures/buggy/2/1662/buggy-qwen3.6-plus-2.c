#include <stdio.h>
int main()
{
    char cal[100]={}; // @@ The program lacks the necessary logic to parse and evaluate arithmetic expressions dynamically.
    gets(cal); // @@ gets() was removed in the C11 standard, causing compilation errors in modern environments; use fgets() instead. Additionally, the input is not parsed for calculation.
    if(cal[1]-'0'==0){ // @@ Hardcoded condition checking specific input characters instead of evaluating the expression.
        printf("%d",0); // @@ Hardcoded output for a specific test case, which fails for general inputs.
        return 0;
    }
    else if(cal[0]-'0'==1){ // @@ Hardcoded condition checking specific input characters.
        if(cal[2]-'0'==0){ // @@ Hardcoded condition.
            printf("%d",12000); // @@ Hardcoded output.
            return 0;
        }
        else{
            printf("%d",602); // @@ Hardcoded output.
            return 0;
        }
    }
    else if(cal[0]-'0'==2){ // @@ Hardcoded condition.
        if(cal[15]=='*'){ // @@ Hardcoded condition checking a specific index.
            printf("%d",24); // @@ Hardcoded output.
            return 0;
        }
        else{
            printf("%d",211); // @@ Hardcoded output.
            return 0;
        }
    }
    
    return 0;
}