#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str);
    int len = strlen(str);
    int a = 0;
    if(str[0]-'0'==0)
    {
        for(int i=2;i<len;i++)
        {
            if(str[i]!='0'&&str[i+1]!='\0')
            {
                printf("%c.",str[i]);
                a = i;
                for(int p=i+1;p<len;p++)
                {
                    printf("%c",str[p]);
                }
                goto e;
            }
            else if(str[i]!='0'&&str[i+1]=='\0')
            {
                printf("%c",str[i]);
            }
        }
        e:
        printf("e-"); // @@ The code unconditionally prints "e-" for numbers starting with 0, but if the exponent calculation results in a negative number, it should just be printed as negative. However, the specific error here is that for input 0.9, the exponent is -1. The code prints "e-" and then prints the value of a-1. If a=2 (index of '9'), a-1=1. So it prints "e-1". Wait, let's trace carefully. Input "0.9". len=3. str[0]='0'. Loop i=2. str[2]='9'. str[3]='\0'. Condition str[i]!='0' (true) && str[i+1]!='\0' (false, str[3] is '\0'). So it goes to else if. str[i]!='0' (true) && str[i+1]=='\0' (true). Prints "9". Loop ends. Then executes label e: printf("e-"); printf("%d", a-1);. But 'a' was initialized to 0 and never updated because the 'if' block where a=i was not entered. So a=0. Prints "e-0". This is wrong. The expected output is 9e-1. The logic for finding the first non-zero digit and calculating exponent is flawed.
        printf("%d",a-1);
    }
    else
    {
        printf("%c.",str[0]);
        for(int i=1;i<len;i++)
        {
            if(str[i]!='.')
            {
                printf("%c",str[i]);
            }
            else
            {
                a = i;
            }
        }
        printf("e");
        printf("%d",a-1);
    }
    
    return 0;
}