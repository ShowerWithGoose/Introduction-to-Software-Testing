#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define eps 1e-10

int main()
{
    char c[102],s[4],m[102];
    int i,j,k=0,r;
    gets(c);
    j=strlen(c);
    for(i=0;i<j;i++)
    {
        if(c[i]=='.')
            {
            r=i;
            break;
            }
        if(i==j-1)
            r=j;
    }
    for(i=j-1;i>=0;i--)
    {
        if(c[i]=='0')
            c[i]='\0';
        else
            break;
    }
    for(i=0;i<j;i++)
    {
        if(c[i]<='9'&&c[i]>='1')
            {
            m[k++]=c[i];
            break;
            }
    }
    i++;
    s[0]='e';
    if(r>=i)
    {r=r-i;
    s[1]='\0';}
    else
        {
        s[1]='-';
        s[2]='\0';
        r=i-r-1;
        }
    for(1;i<j;i++)
    {
        if(c[i]<='9'&&c[i]>='0')
            {++k;
            m[k]=c[i];

            }
    }
    m[++k]='\0';
    if(!(m[2]=='\0'))
    m[1]='.';
    else
        m[1]='\0';

    printf("%s%s%d",m,s,r);
    return 0;
}



