#include<stdio.h>

char s[1025] = {'\0'};

void fk(int i);

int main(){
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-') printf("%c",s[i]);
        else fk(i);
    }
    return 0;
}

void fk(int i)
{
    int k=1;
    if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a') // @@ [Potential out-of-bounds access if i is 0 or at end of string]
    k=0;
    else if(s[i-1]<='9'&&s[i+1]<='9'&&s[i-1]>='0'&&s[i+1]>='0') // @@ [Potential out-of-bounds access if i is 0 or at end]
    k=0;
    else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A') // @@ [Potential out-of-bounds access if i is 0 or at end]
    k=0;
    
    if(s[i+1]-s[i-1]<=0) // @@ [Potential out-of-bounds access if i is 0 or at end]
    k=1;
    if(k==1) // @@ [When k==1, the function returns without printing the '-' character, violating the requirement to output '-' unchanged]
    return; // @@ [Missing print of '-' before return; should have printf("%c",'-');]
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++)
        printf("%c",s[i-1]+j);
    }
}