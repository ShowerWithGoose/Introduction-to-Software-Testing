#include<stdio.h>

char s[1025] = {'\0'};

void fk(int i);

int main(){
    gets(s); // @@ gets() is deprecated and removed in C11 standard, which may cause a compilation error; use fgets() or scanf() instead.
    for(int i=0;s[i]!='\0';i++) // @@ Declaring loop variable inside for loop is not allowed in C89/C90, causing a compilation error.
    {
        if(s[i]!='-') printf("%c",s[i]);
        else fk(i);
    }
    return 0;
}

void fk(int i)
{
    int k=1;
    if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a')
    k=0;
    else if(s[i-1]<='9'&&s[i+1]<='9'&&s[i-1]>='0'&&s[i+1]>='0')
    k=0;
    else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A')
    k=0;
    
    if(s[i+1]-s[i-1]<=0)
    k=1;
    if(k==1) // @@ When expansion condition fails, the function returns without printing the '-' character, leading to incorrect output.
    return; // @@ Should print '-' before returning to ensure the original string is output unchanged when no expansion occurs.
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++) // @@ Declaring loop variable 'j' inside for loop may cause a compilation error in C89/C90.
        printf("%c",s[i-1]+j);
    }
}