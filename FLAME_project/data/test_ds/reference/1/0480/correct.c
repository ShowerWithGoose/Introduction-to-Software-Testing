#include<stdio.h>
#include<string.h>

int main()
{
    char s[1000],*p,ne[1000],*sto;
    int i,j;
    gets(s);
    p = s - 1;
    while( strchr(p+1,'-') != NULL)
    {
        sto = p + 1;
        p = strchr(p+1,'-');
        *p = '\0';
        for(j = 0;(sto + j) < p;j++)
            {
                printf("%c",*(sto + j));
            }
        if(*(p - 1) < *(p + 1)&&((*(p - 1)>='a')&&(*(p + 1)<='z'))||((*(p - 1)>='A')&&(*(p + 1)<='Z'))||((*(p - 1)>='0')&&(*(p + 1)<='9')))
        {
            for(i = *(p - 1) + 1;i < *(p + 1);i++)
                printf("%c",i);
        }
        else
        {
            printf("-");
        }
    }
    puts((p+1));
    return 0;
}

