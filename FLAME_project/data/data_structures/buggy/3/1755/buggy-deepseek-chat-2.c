#include<stdio.h>
int main(){
    char s[101]="\0";
    fgets(s,101,stdin);
    int i;
    if(s[0]=='0'){
        i=2;
        while(s[i]=='0')
        i++;
        
        if(s[i+1]!='\0'){
            printf("%c.%se-%d",s[i],&s[i+1],i-1); // @@ The format specifier %s expects a string, but &s[i+1] is a pointer to a single character; this will print garbage or cause undefined behavior. Also, the exponent calculation i-1 is incorrect because i starts at 2 and counts leading zeros, but the exponent should be the number of decimal places moved, which is the position of the first non-zero digit after the decimal point.
        }
        else
        printf("%ce-%d",s[i],i-1); // @@ Same issue with exponent calculation; i-1 is not the correct exponent value.
    }
    else{
        if(s[1]!='.'){
        i=1;
        while(s[i]!='.'){
            i++;
        }
        int k=i;
        while(s[i]!='\0'){
            s[i]=s[i+1];
            i++;
        }
        printf("%c.%se%d",s[0],&s[1],k-1); // @@ The format specifier %s expects a string, but &s[1] is a pointer to a single character; this will print garbage or cause undefined behavior. Also, the loop that shifts characters overwrites the string incorrectly, potentially losing the decimal point and subsequent digits.
        }
        else{
            printf("%se0",&s[0]); // @@ The format specifier %s expects a string, but &s[0] is the whole string; this will print the entire input including the decimal point, which is incorrect for scientific notation base.
        }
    }
    return 0;
}