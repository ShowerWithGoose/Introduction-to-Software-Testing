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
        printf("%ce-%d",s[i],i-1); @@ [When the input is "0.0", this leads to undefined behavior because s[i] would be '\0', and printing it as %c is invalid. Also, for inputs like "0.1", s[i+1] might be '\n' or '\0', leading to incorrect output format.]
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
            printf("%se0",&s[0]); @@ [This prints the entire string including the newline character read by fgets, which results in extra characters (like '\n') in the output. It should print only up to the decimal point or remove the newline first.]
        }
    }
    return 0;
}