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
        printf("%ce-%d",s[i],i-1); @@ [When the input is "0.0", this accesses s[i] where i goes beyond valid digits, leading to undefined behavior. Also, for inputs like "0.1", s[i+1] may be '\n' or '\0', but the condition doesn't properly handle end-of-string vs newline.]
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
            printf("%se0",&s[0]); @@ [This prints the entire string including the newline character read by fgets, which causes incorrect output (e.g., "5.\n" instead of "5."). Also, it should print only the first digit without decimal if only one digit before '.', but logic fails for cases like "5.0".]
        }
    }
    return 0;
}