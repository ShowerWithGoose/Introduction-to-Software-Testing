#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal);
    if(cal[1]-'0'==0){ // @@ This line incorrectly assumes the input is a single-digit number and hardcodes a result of 0, instead of parsing the full expression.
        printf("%d",0);
        return 0;
    }
    else if(cal[0]-'0'==1){ // @@ This line hardcodes a specific result based on the first character, ignoring the actual arithmetic expression.
        if(cal[2]-'0'==0){ // @@ This line further hardcodes based on a specific position, which is not a valid parsing method.
            printf("%d",12000);
            return 0;
        }
        else{
            printf("%d",602);
            return 0;
        }
    }
    else if(cal[0]-'0'==2){ // @@ This line hardcodes another specific case instead of evaluating the expression.
        if(cal[15]=='*'){ // @@ This line checks a fixed index that may not correspond to any operator in the actual input.
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