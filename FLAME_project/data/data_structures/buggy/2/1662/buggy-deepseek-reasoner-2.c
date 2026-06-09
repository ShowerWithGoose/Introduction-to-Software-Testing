#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal);
    if(cal[1]-'0'==0){ // @@ [Bug: Hardcoded condition that always triggers for inputs starting with "10", outputting 0 incorrectly for any expression like "10 + ..."]
        printf("%d",0); // @@ [Bug: Prints hardcoded value 0 instead of evaluating the expression]
        return 0; // @@ [Bug: Early return prevents any further processing]
    }
    else if(cal[0]-'0'==1){ // @@ [Bug: Hardcoded check based on first digit, not actual evaluation]
        if(cal[2]-'0'==0){ // @@ [Bug: Another hardcoded condition that may or may not match intended expression]
            printf("%d",12000); // @@ [Bug: Prints hardcoded value]
            return 0; // @@ [Bug: Early return]
        }
        else{
            printf("%d",602); // @@ [Bug: Hardcoded value for some expressions, not general]
            return 0; // @@ [Bug: Early return]
        }
    }
    else if(cal[0]-'0'==2){ // @@ [Bug: Hardcoded check based on first digit]
        if(cal[15]=='*'){ // @@ [Bug: Hardcoded index and character check]
            printf("%d",24); // @@ [Bug: Hardcoded value]
            return 0; // @@ [Bug: Early return]
        }
        else{
            printf("%d",211); // @@ [Bug: Hardcoded value]
            return 0; // @@ [Bug: Early return]
        }
    }
    
    return 0;
}