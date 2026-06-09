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
        while(s[i]!='\0'){
            s[i]=s[i+1];
            i++;
        }
        printf("%c.%se%d",s[0],&s[1],k-1);
        }
        else{
            printf("%se0",&s[0]); @@ [The format specifier "%s" expects a null-terminated string, but &s[0] includes the newline character read by fgets, which may cause incorrect output. Also, according to problem requirements, if there's only one digit before the decimal point (like "5.3"), it should be normalized to "5.3e0", but this branch handles cases like "5." incorrectly. Moreover, the output should not include the decimal point if the base is an integer with one digit, but here it prints the whole string including the decimal point and possibly a newline.]
        }
    }
    return 0;
}