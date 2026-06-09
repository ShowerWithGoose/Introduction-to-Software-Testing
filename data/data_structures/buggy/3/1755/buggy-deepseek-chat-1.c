#include<stdio.h>
int main(){
    char s[101]="\0";
    fgets(s,101,stdin);
    int i;
    if(s[0]=='0'){
        i=2;
        while(s[i]=='0')
        i++;
        
        if(s[i+1]!='\0'){ // @@ The condition should check if s[i+1] is not '\n' or '\0', because fgets includes the newline character. This may cause incorrect output when the number ends exactly after the first non-zero digit.
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
        while(s[i]!='\0'){ // @@ This loop shifts characters to remove the decimal point, but it also shifts the newline character from fgets, which may cause issues. Additionally, the loop condition should check for '\n' as well.
            s[i]=s[i+1];
            i++;
        }
        printf("%c.%se%d",s[0],&s[1],k-1);
        }
        else{
            printf("%se0",&s[0]); // @@ This prints the entire string including the newline character from fgets, which is incorrect. It should only print the number without the newline.
        }
    }
    return 0;
}