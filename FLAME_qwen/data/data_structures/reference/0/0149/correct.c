//
//  main.c
//  扩展字符
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>
char s[1000];
char store[10000];
int judgement(char, char);
int main(int argc, const char * argv[])
{
    gets(s);
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    char *p1, *p2;
    p1 = strchr(s, '-');
    if (p1==NULL)
    {
        printf("%s\n",s);
    }
    else
    {
        p1=s;
        while ((p2=strchr(p1, '-'))!=NULL && (p2+1)!=NULL)
        {
            //printf("%d\n",judgement(*(p2-1), *(p2+1)));
            if (judgement(*(p2-1), *(p2+1)))
            {
                for (i=0 ; i<p2-p1; i++)
                {
                    printf("%c",*(p1+i));
                }
                //break;
                for (i=1; i<=*(p2+1)-*(p2-1); i++)
                {
                    printf("%c",*(p2-1)+i);
                }
                //break;
            }
            else
            {
                for (i=0; i<p2-p1+2; i++)
                {
                    printf("%c",*(p1+i));
                }
            }
            p1=p2+2;
        }
        if ((p2+1)!=NULL)
        {
            for (i=0; i<strlen(s)-(p1-s); i++)
            {
                printf("%c",*(p1+i));
            }
        }
    }
    printf("\n");
    return 0;
}
int judgement(char a, char b)
{
    if (a>='a'&&a<='z' && b>='a'&&b<='z' && (b-a)>0)
    {
        return 1;
    }
    else if (a>='A'&&a<='Z' && b>='A'&&b<='Z' && (b-a)>0)
    {
        return 1;
    }
    else if (a>='0'&&a<='9' && b>='0'&&b<='9' && (b-a)>0)
    {
        return 1;
    }
    return 0;
}

