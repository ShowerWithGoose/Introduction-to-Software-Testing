#include<stdio.h>
int main(){
    char s[101]="\0";
    fgets(s,101,stdin); // @@ fgets retains the trailing newline character '\n', which interferes with string termination checks and causes incorrect output formatting.
    int i;
    if(s[0]=='0'){
        i=2;
        while(s[i]=='0')
        i++;

        if(s[i+1]!='\0'){ // @@ The condition does not account for the '\n' character, causing it to incorrectly treat the end of the number as having more digits and printing an unwanted decimal point.
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
        while(s[i]!='\0'){ // @@ The loop shifts characters but does not stop at '\n', moving the newline into the string and causing it to be printed incorrectly.
            s[i]=s[i+1];
            i++;
        }
        printf("%c.%se%d",s[0],&s[1],k-1);
        }
        else{
            printf("%se0",&s[0]); // @@ Prints the entire string including the trailing '\n', resulting in malformed output. The newline should be stripped before printing.
        }
    }
    return 0;
}