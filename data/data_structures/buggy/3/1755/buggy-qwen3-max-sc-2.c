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
        printf("%ce-%d",s[i],i-1); @@ [When the input is "0.0", this accesses s[i] where i goes beyond valid digits, leading to undefined behavior. Also, if input ends right after a non-zero digit (e.g., "0.1"), s[i+1] is '\n' or '\0', but logic assumes presence of more digits.]
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
            printf("%se0",&s[0]); @@ [This prints the entire string including the newline character read by fgets, and also includes the decimal point (e.g., for input "5.", it prints "5.e0" instead of "5e0" or "5.0e0". Also, per problem spec, if only one digit before decimal and it's non-zero, output should be just that digit without decimal unless there are fractional digits.]
        }
    }
    return 0;
}