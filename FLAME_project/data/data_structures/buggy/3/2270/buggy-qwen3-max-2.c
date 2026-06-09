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
                printf("%c",str[i]); // @@ [This branch prints only one digit without decimal point, but doesn't set 'a' correctly or handle exponent properly. Also, after printing, it falls through without jumping to 'e', causing missing exponent output in some cases.]
            }
        }
        e:
        printf("e-");
        printf("%d",a-1); // @@ [When input is "0.9", 'a' is never set because the loop exits without entering any condition (since str[2] is '9' and str[3] is '\0', so second condition triggers but doesn't set 'a'). Thus 'a' remains 0, leading to exponent -1, but printed as "e--1" due to logic error in control flow. Actually, in this specific case, the first non-zero is at i=2, but 'a' is not assigned in the second condition, so a=0 -> a-1 = -1, but the real issue is double '-' comes from incorrect handling elsewhere. However, deeper issue: the code prints "e-" then "%d" of (a-1). If a=0, then a-1=-1, so output becomes "e--1". The root cause is that 'a' is not updated in the second branch.]
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