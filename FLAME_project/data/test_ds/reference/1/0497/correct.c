#include<stdio.h>
#include<ctype.h>
int main()
{
    char ch[100];
    int i,j;
    scanf("%s",&ch);
    for(i=0; i<100; i++)
    {
        if(ch[i]!='-')
        {
            printf("%c",ch[i]);
        }

        if(ch[i]=='-')
        {
            if((isupper(ch[i-1])&&isupper(ch[i+1]))||((islower(ch[i-1])&&islower(ch[i+1])))||(isdigit(ch[i-1])&&isdigit(ch[i+1])))
            {
                for( j=1; j<ch[i+1]-ch[i-1]; j++)
                {
                    printf("%c",ch[i-1]+j);
                }
            }
            else
            {
                printf("-");
            }
        }
    }
    ch[++i]='\0';
    return 0;
}



