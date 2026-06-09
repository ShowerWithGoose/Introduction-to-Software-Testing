#include<stdio.h>
#include<string.h>
int main()
{
    int num1,num2,num3;
    char ch1,ch2,ch3;
    num1 = 0; ch1 = '+';
    while(ch1!='=')
    {
        scanf("%d %c",&num2,&ch2);
        while(ch2 == '*' || ch2 == '/')
        {
            scanf("%d %c",&num3,&ch3);
            if(ch2 == '*')
                num2 = num2 * num3;
            else if(ch2 == '/')
                num2 = num2 / num3;
            ch2 = ch3;
        }
        if(ch1 == '+')
            num1 = num1 + num2;
        else if(ch1 == '-')
            num1 = num1 - num2;
        ch1 = ch2;
    }
    if(ch1 == '=')
        printf("%d", num1);
    return 0;
}

