#include <stdio.h>
#include <ctype.h>
char s[10000];
int judge(char a, char b)
{
    if((isdigit(a)!=0&&isdigit(b)!=0)||(isupper(a)!=0&&isupper(b)!=0)||(islower(a)!=0&&islower(b)!=0))
        if(a<b)
            return 1;
    return 0;
}
int main()
{
    int i,j;
    gets(s);
    char *p=s;
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]=='-'&&judge(s[i-1], s[i+1])==1)
        {
            s[i]='\0';
            printf("%s",p);
            p=s+1+i;
            for(j=(int)s[i-1]+1;j<(int)s[i+1];j++)
                printf("%c",(char)j);
        }
    }
    printf("%s",p);
    return 0;
}



