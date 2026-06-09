#include <stdio.h>
#include <string.h>
#define MAXN 100000
char c[MAXN];
int jud(int i,int j)
{
    if(c[i]>='A'&&c[i]<='Z'&&c[j]>='A'&&c[j]<='Z') return 1;
    if(c[i]>='a'&&c[i]<='z'&&c[j]>='a'&&c[j]<='z') return 1;
    if(c[i]>='0'&&c[i]<='9'&&c[j]>='0'&&c[j]<='9') return 1;
    return 0;
}
int main()
{
    scanf("%s",c);
    int len=strlen(c);
    for(int i=0;i<len;i++)
    {
        if(c[i]!='-') putchar(c[i]);
        else 
        {
            if(i>0&&jud(i-1,i+1))
            {
                for(char j=c[i-1]+1;j<c[i+1];j++) putchar(j);
            }
            else putchar('-');
        }
    }
    return 0;
}

