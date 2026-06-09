#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char str[100000];
int main(void){
    int i,k = 0,num = 0;
    gets(str); @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers that remove gets() from stdio.h]
    for(i = 0;i < strlen(str);i++)
    {
        if(str[i] != '.')
            num++;
        else if(str[i] == '.')
            break;
    }    
    if(num == 1)
    {
        if(str[0] == '0')
        {
            num = 0;
            for(i = 0;i < strlen(str);i++)
            {
                if(str[i] == '0'&&k>0)
                {
                    num--;
                }
                else if(str[i] != '.')
                {
                    printf("%c",str[i]);
                    k++;
                    if(k == 1&&i!=strlen(str)-1)
                    {
                        printf(".");
                    }
                } 
            }
            printf("e%d",num);
        }
        else
        {
            printf("%se0",str);
        }
    }
    else
    {
        for(i = 0;i < strlen(str);i++)
        {
            if(i == 1)
            {
                printf(".%c",str[i]);
            }
            else if(i != num)
            {
                printf("%c",str[i]);
            } 
        } 
        printf("e%d",num-1);
    }
    return 0;
}