#include<stdio.h>
int main(){
    char s[101]="\0";
    fgets(s,101,stdin); // @@ fgets retains newline character, causing the string to contain '\n'; subsequent checks and prints will be misled.
    int i;
    if(s[0]=='0'){
        i=2;
        while(s[i]=='0')
        i++;
        
        if(s[i+1]!='\0'){ // @@ The newline from fgets makes this condition always true even when there are no more digits; expects null for integer base, but gets '\n'.
            printf("%c.%se-%d",s[i],&s[i+1],i-1);
        }
        else
        printf("%ce-%d",s[i],i-1);
    }
    else{
        if(s[1]!='.'){
        i=1;
        while(s[i]!='.'){
            i++;
        }
        int k=i;
        while(s[i]!='\0'){ // @@ The newline is included in the shift, corrupting the string; also i is not reset after shifting, leading to undefined behavior.
            s[i]=s[i+1];
            i++;
        }
        printf("%c.%se%d",s[0],&s[1],k-1);
        }
        else{
            printf("%se0",&s[0]); // @@ Prints the entire string including the newline and decimal point, producing unwanted characters.
        }
    }
    return 0;
}