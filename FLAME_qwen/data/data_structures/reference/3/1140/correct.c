#include<stdio.h>
#include<string.h>
int main ()
{
    char input[105];
    int i;
    gets(input);
    if(input[0]=='0' && input[1]=='.')
    {
        for(i=2;input[i]=='0';i++);
        if(input[i+1]=='\0')
            printf("%ce-%d",input[i],i-1);
        else
            printf("%c.%se-%d",input[i],input+i+1,i-1);
    }
    else
    {
        for(i=1;input[i]!='.';i++);
        strcpy(input+i,input+i+1);
        printf("%c.%se%d",input[0],input+1,i-1);
    }
    return 0;
}
