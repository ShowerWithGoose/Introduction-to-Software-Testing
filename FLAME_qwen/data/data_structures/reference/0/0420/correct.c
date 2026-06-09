#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char k,m='-';
    char str[100];
    scanf("%s",str);
    i=strlen(str);
    for(j=0;j<i;j++)
    {
        if(str[j]=='-')
        {
            if(j==0||j==i-1)
            {
                printf("%c",m);
            }
            else
            {
                if((str[j-1]>='a'&&str[j+1]<='z')||(str[j-1]>='A'&&str[j+1]<='Z')||(str[j-1]>='0'&&str[j+1]<='9'))
                {
                    for(k=str[j-1]+1;k<str[j+1];k++)
                    {
                        printf("%c",k);
                    }
                }
                else
                {
                    printf("%c",str[j]);
                }
            }
        }
        else
        {
            printf("%c",str[j]);
        }
    }
    return 0;
}



