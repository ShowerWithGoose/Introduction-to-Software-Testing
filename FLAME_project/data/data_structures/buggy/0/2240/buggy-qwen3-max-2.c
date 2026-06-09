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
    if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a')
    k=0;
    else if(s[i-1]<='9'&&s[i+1]<='9'&&s[i-1]>='0'&&s[i+1]>='0')
    k=0;
    else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A')
    k=0;
    
    if(s[i+1]-s[i-1]<=0)
    k=1;
    if(k==1)
    return; // @@ [When k==1, the function returns without printing the '-', so the '-' is omitted from output, but it should be printed as-is when expansion is not performed.]
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++)
        printf("%c",s[i-1]+j);
    }
}