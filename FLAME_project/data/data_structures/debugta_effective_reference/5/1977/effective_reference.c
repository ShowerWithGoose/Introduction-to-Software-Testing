#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct num
{
    int udr;
    int upr;
    struct num *next;
}num;

int main()
{
    num *expression1 = (num*)malloc(sizeof(num));
    num *ans = (num*)malloc(sizeof(num));
    num *flag1 = expression1;
    num *flag = ans;
    char line[1000]="";
    char line2[1000]="";
    gets(line);
    gets(line2);
    int i = 1,token = 0,op = 0;
    for(int i = strlen(line)-1 ; i >= 0 ; i --)
    {
        if(i != 0)
        {
            if(line[i] == ' ')
            {
                op++;
                if(op % 2 == 1)
                {
                    flag1->upr = token;
                    token = 0;
                    i = 1;
                }
                else
                {
                    flag1->udr = token;
                    flag1->next = (num*)malloc(sizeof(num));
                    flag1 = flag1->next;
                    token = 0;
                    i = 1;
                }
            }
            else
            {
                token+=(line[i]-'0') * i;
                i*=10;
            }
        }
        else
        {
            token+=(line[i]-'0') * i;
            flag1->udr = token;
            flag1->next = (num*)malloc(sizeof(num));
            flag1 = flag1->next;
        }
        
    }
    flag1->next = NULL;
    flag1 = expression1;
    num *expression2 = (num*)malloc(sizeof(num));
    num *flag2 = expression2;
    op = 0;
    i = 1;
    token = 0;
    for(int i = strlen(line2)-1 ; i >= 0 ; i --)
    {
        if(i != 0)
        {
            if(line2[i] == ' ' || i == 0)
            {
                op++;
                if(op % 2 == 1)
                {
                    flag2->upr = token;
                    token = 0;
                    i = 1;
                }
                else
                {
                    flag2->udr = token;
                    flag2->next = (num*)malloc(sizeof(num));
                    flag2 = flag2->next;
                    token = 0;
                    i = 1;
                }
            }
            else
            {
                token+=(line2[i]-'0') * i;
                i*=10;
            }
        }
        else
        {
            token+=(line2[i]-'0') * i;
            flag2->udr = token;
            flag2->next = (num*)malloc(sizeof(num));
            flag2 = flag2->next;
            token = 0;
            i = 1;
        }
    }
    flag2->next = NULL;
    flag2 = expression2;
    while(flag1->next != NULL)
    {
        while(flag2->next != NULL)
        {
            flag->upr = flag1->upr + flag2->upr;
            flag->udr = flag1->udr * flag2->udr;
            flag->next = (num*)malloc(sizeof(num));
            flag = flag->next;
            flag2 = flag2->next;
        }
        flag1 = flag1->next;
        flag2 = expression2;
    }
    flag->next = NULL;
    num*j = (num*)malloc(sizeof(num));
    int tmp;
    flag = ans;
    for(flag ; flag->next->next != NULL ; flag = flag->next)
    {
        for(j = flag->next ; j->next != NULL ; j = j->next)
        {
            if(flag->upr < j->upr)
            {
                tmp = flag->upr;
                flag->upr = j->upr;
                j->upr = tmp;
                tmp = flag->udr;
                flag->udr = j->udr;
                j->udr = tmp;
            }
        }
    }
    flag = ans;
    for(flag ; flag->next->next != NULL ; )
    {
        if(flag->upr == flag->next->upr)
        {
            flag->udr += flag->next->udr;
            flag->next = flag->next->next;
            continue;
        }
        flag = flag->next;
    }
    flag = ans;
    while(flag->next != NULL)
    {
        printf("%d %d ",flag->udr,flag->upr);
        flag = flag->next;
    }
    system("pause");
    return 0;
}
