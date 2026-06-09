#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal);
    if(cal[1]-'0'==0){ // @@ Incorrect logic: checks a specific character index instead of parsing and evaluating the arithmetic expression.
        printf("%d",0); // @@ Incorrect logic: prints a hardcoded value instead of the calculated result.
        return 0;
    }
    else if(cal[0]-'0'==1){ // @@ Incorrect logic: checks a specific character index instead of parsing the expression.
        if(cal[2]-'0'==0){ // @@ Incorrect logic: checks a specific character index instead of parsing the expression.
            printf("%d",12000); // @@ Incorrect logic: prints a hardcoded value instead of the calculated result.
            return 0;
        }
        else{
            printf("%d",602); // @@ Incorrect logic: prints a hardcoded value instead of the calculated result.
            return 0;
        }
    }
    else if(cal[0]-'0'==2){ // @@ Incorrect logic: checks a specific character index instead of parsing the expression.
        if(cal[15]=='*'){ // @@ Incorrect logic: checks a specific character at a fixed index instead of parsing the expression.
            printf("%d",24); // @@ Incorrect logic: prints a hardcoded value instead of the calculated result.
            return 0;
        }
        else{
            printf("%d",211); // @@ Incorrect logic: prints a hardcoded value instead of the calculated result.
            return 0;
        }
    }
    
    return 0;
}