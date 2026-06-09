#include<stdio.h>
void kxjsf(char s[])
{
    int point=0,i,j,k,m,n,z;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')
        {
            point=i;
        }
    }
    if(s[0]>='1')
    {
        printf("%c.",s[0]);
        for(j=1;j<point;j++)
        {
            printf("%c",s[j]);
        }
        for(j=point+1;j<i;j++)
        {
            printf("%c",s[j]);
        }
        printf("e%d",point-1);
    }
    else if(s[0]=='0')
    {
        for(k=0;;k++)
        {
            if(s[k]!='0'&&s[k]!='.')
            {
                break;
            }
        }
        printf("%c",s[k]);
        if(k!=i-1)
        {
            printf(".");
        }
        for(m=k+1;m<i;m++)
        {
            printf("%c",s[m]);
        }
        printf("e%d",point-k);
    }
}
int main()
{
    char s[100],s1[100];
    int i,j;
    gets(s);
    if(s[0]=='-')
    {
        for(i=1,j=0;s[i]!='\0';i++,j++)
        {
            s1[j]=s[i];
        }
        printf("-");
        kxjsf(s1);
    }
    if(s[0]!='-')
    {
        kxjsf(s);
    }
    return 0;
}

