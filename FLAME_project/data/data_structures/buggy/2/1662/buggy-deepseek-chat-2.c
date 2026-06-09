#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal);
    if(cal[1]-'0'==0){ // @@ This line incorrectly assumes the input is always a single-digit number and uses hardcoded checks instead of parsing the expression.
        printf("%d",0);
        return 0;
    }
    else if(cal[0]-'0'==1){ // @@ This line hardcodes a check for the first digit being 1, which is not a general solution for any arithmetic expression.
        if(cal[2]-'0'==0){ // @@ This line hardcodes a check for the third character, assuming a specific input format, which is incorrect for general expressions.
            printf("%d",12000);
            return 0;
        }
        else{
            printf("%d",602);
            return 0;
        }
    }
    else if(cal[0]-'0'==2){ // @@ This line hardcodes a check for the first digit being 2, which is not a general solution.
        if(cal[15]=='*'){ // @@ This line hardcodes a check for a specific position in the input, which is not valid for all expressions.
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