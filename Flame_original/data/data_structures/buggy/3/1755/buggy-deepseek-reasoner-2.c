#include<stdio.h>
int main(){
    char s[101]="\0";
    fgets(s,101,stdin); @@ // fgets includes newline, causing unwanted characters in output
    int i;
    if(s[0]=='0'){
        i=2;
        while(s[i]=='0')
        i++;
        
        if(s[i+1]!='\0'){ @@ // should also check for newline, as fgets adds newline
            printf("%c.%se-%d",s[i],&s[i+1],i-1); @@ // prints newline as part of base
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
        while(s[i]!='\0'){ @@ // includes newline in the shift, causing newline in output
            s[i]=s[i+1];
            i++;
        }
        printf("%c.%se%d",s[0],&s[1],k-1); @@ // prints newline from shifted string
        }
        else{
            printf("%se0",&s[0]); @@ // prints newline after base
        }
    }
    return 0;
}