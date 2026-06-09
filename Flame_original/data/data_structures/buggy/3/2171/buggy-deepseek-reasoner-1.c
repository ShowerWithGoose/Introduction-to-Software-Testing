#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char str[100000];
int main(void){
    int i,k = 0,num = 0;
    gets(str);
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
                { // @@ Missing braces: the following statements should be enclosed in braces to be part of this else if block
                    printf("%c",str[i]); // @@ This statement is the only one inside else if due to missing braces; subsequent increments and dot print are executed unconditionally
                    k++; // @@ This k++ is executed for every character, including dots and zeros that should be skipped, causing incorrect counting
                    if(k == 1&&i!=strlen(str)-1) // @@ This condition is also executed unconditionally, causing a dot to be printed after the first digit even if it's a leading zero
                    {
                        printf("."); // @@ This dot print is executed unconditionally when condition is true, leading to extra dot
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