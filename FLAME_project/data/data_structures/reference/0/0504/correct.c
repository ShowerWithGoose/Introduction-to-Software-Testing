#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char str[1000000]="";
int main()
{

     gets(str);
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='-')
        {
            if((islower(str[i-1])&&islower(str[i+1]))||(isupper(str[i-1])&&isupper(str[i+1]))||(str[i-1]>='0'&&str[i+1]<='9'))
            {
                if(str[i-1]<str[i+1])
                {
                    for(char k=str[i-1]+1;k<str[i+1];k++)
                        printf("%c",k);
                }
                else
                {
                    printf("%c",str[i]);
                }
            }
            else
                printf("%c",str[i]);
        }
        else
            printf("%c",str[i]);
    }
    return 0;
}

