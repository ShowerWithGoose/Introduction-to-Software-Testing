#include<stdio.h>
int main(){
    char s[101]="\0";
    fgets(s,101,stdin); // @@ [fgets reads newline; the code does not handle it, leading to incorrect output]
    int i;
    if(s[0]=='0'){
        i=2;
        while(s[i]=='0')
        i++;
        
        if(s[i+1]!='\0'){ // @@ [condition should also check for newline; otherwise, digits followed by newline are misinterpreted]
            printf("%c.%se-%d",s[i],&s[i+1],i-1); // @@ [output includes newline character from s[i+1], causing extra newline in scientific notation]
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
        while(s[i]!='\0'){ // @@ [loop shifts characters including newline, leaving newline in the string, causing extra newline in output]
            s[i]=s[i+1];
            i++;
        }
        printf("%c.%se%d",s[0],&s[1],k-1); // @@ [output includes newline from &s[1] because newline was not removed]
        }
        else{
            printf("%se0",&s[0]); // @@ [output includes newline from the string, causing extra newline in scientific notation]
        }
    }
    return 0;
}