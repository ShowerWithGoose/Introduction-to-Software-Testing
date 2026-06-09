#include<stdio.h>
#include<string.h>
char s[1000],out[10000];
int fill(int);
int j=0;
int main()
{
    gets(s);
    int i;
    for(i=1;i<=strlen(s);i++)
    {
        if(s[i]!='-')
        {
            out[j]=s[i-1];
            j++;
        }
        else
            i+=fill(i);
    }
    out[j]='\0';
    printf("%s\n",out);
    system("pause");
    return 0;
}

int fill(int n)
{
    if('0'<=s[n-1]&&s[n-1]<s[n+1]&&'9'>=s[n+1])
    {
        for(int i=s[n-1];i<=s[n+1]-1;i++)
        {
        out[j++]=i;
        }return 1;
    }
    if('a'<=s[n-1]&&s[n-1]<s[n+1]&&'z'>=s[n+1])
    {
        for(int i=s[n-1];i<=s[n+1]-1;i++)
        {
        out[j++]=i;
        }return 1;
    }
    if('A'<=s[n-1]&&s[n-1]<s[n+1]&&'Z'>=s[n+1])
    {
        for(int i=s[n-1];i<=s[n+1]-1;i++)
        {
        out[j++]=i;
        }return 1;
    }
    out[j]=s[n-1];
    j++;
    return 0;
}

