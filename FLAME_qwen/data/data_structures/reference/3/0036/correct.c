#include <stdio.h>
#include <math.h>
#include <string.h>
char s[5000];
char s1[5000];
char s2[5000];
int i=0,j,k,flag=0,mark,num=1,a=0,b=0;
int main()
{
    gets(s);
    for(; s[i]!='\0'; i++)
    {
        if(s[i] == '.'&&flag==0)
        {
            flag=1;
            mark=i;
        }
        else if(flag==0)
        {
            s1[a++]=s[i];
        }
        else
        {
            s2[b++]=s[i];
        }
    }
    s1[a]='\0';
    s2[b]='\0';
    flag=0;
    if(mark == 1&&s1[0] == '0')
    {
        for(j=0; j<b; j++)
        {
            if(s2[j]=='0')
            {
                num++;
            }
            else
            {
                if(j==b-1)
                    printf("%c",s2[j]);
                else
                {
                    for(k=j; k<b; k++)
                    {
                        printf("%c",s2[k]);
                        if(k==j)
                            printf(".");
                    }
                }
                break;
            }
        }
        printf("e-%d",num);
    }
    else if(mark==1&&s[1]!='0')
    {
        printf("%se0",s);
    }
    else
    {
        printf("%c.",s[0]);
        for(i=1; i<a; i++)
            printf("%c",s1[i]);
        printf("%se%d",s2,a-1);
    }
    return 0;
}

