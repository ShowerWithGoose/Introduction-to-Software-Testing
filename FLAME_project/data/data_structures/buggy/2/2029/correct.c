#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void squeez(char s[],char c);
int fouroperations(char s[]);
int num[100];
int count[100];
char operations[100];
char s[200];
int main()
{
    gets(s);
    squeez(s,' ');
    int x=fouroperations(s);
    printf("%d",x);

    return 0;
}

void squeez(char s[],char c)
{
    int i,j;
    for(i=j=0;s[i]!='\0';i++)
    {
        if(s[i]!=c)
        {
            s[j++]=s[i];
        }
    }
    s[j]='\0';
}

int fouroperations(char s[])
{
    int i,j,k,hold;
    int n=strlen(s);
    for(i=0,j=0,k=0;i<n;i++)
    {
        if((isdigit(s[i]))&&(isdigit(s[i-1])))
        {
            num[j-1]=num[j-1]*10+s[i]-'0';
        }
        else if(isdigit(s[i]))
        {
            num[j++]=s[i]-'0';
        }
        else
        operations[k++]=s[i];
    }
    for(i=0,j=0;i<n;i++)
    {
        if(operations[i]=='*')
        {
            num[i+1]=num[i]*num[i+1];
            num[i]=0;
            count[j]++;
        }
        else if(operations[i]=='/')
        {
            num[i+1]=num[i]/num[i+1];
            num[i]=0;
            count[j]++;
        }
        else
        j++;
    }
    hold=num[count[0]];
    for(i=0,j=1;i<strlen(operations);i++)
    {
        if(operations[i]=='-')
        {
            hold=hold-num[i+count[j]+1];
            j++;
        }
        else if(operations[i]=='+')
        {
            hold=hold+num[i+count[j]+1];
            j++;
        }
    }
    return hold;
}
