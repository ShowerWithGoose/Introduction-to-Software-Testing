#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
char str[1000];
int main(int argc, char const *argv[])
{
    gets(str);
    int i=0,j=0,k=0,copy=0;

    if (str[i]=='0')
    {
        copy=1;
        k++;
        i+=2;
        while (str[i]=='0')
        {
            k++;
            i++;
        }
    }
    else
    {
        k-=1;
        while (str[i]!='.')
         {
            k++;
            i++;
        }
        
    }
    if (copy)
    {
        printf("%c",str[k+1]);
        if (str[k+2]>='0'&&str[k+2]<='9')
        {
            printf(".");
            for (int s=k+2; (str[s]>='0'&&str[s]<='9')||str[s]=='.'; s++)
            {
                if (str[s]=='.')
                {
                    continue;
                }
                
                printf("%c",str[s]);
            }
        }        
        printf("e-%d",k);
        
    }
    else
    {
        printf("%c.",str[0]);
        for (int s=1; (str[s]>='0'&&str[s]<='9')||str[s]=='.'; s++)
            {
                if (str[s]=='.')
                {
                    continue;
                }
                
                printf("%c",str[s]);
            }
            printf("e%d",k);
    }


    return 0;
}

