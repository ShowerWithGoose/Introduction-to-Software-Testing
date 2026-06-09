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
    num *head1 = (num*)malloc(sizeof(num));
    num *head3 = (num*)malloc(sizeof(num));
    num *flag1 = head1;
    num *flag3 = head3;
    char line1[1000]="";
    char line2[1000]="";
    gets(line1);
    gets(line2);
    int cnt = 1,sum = 0,op = 0;
    for(int i = strlen(line1)-1 ; i >= 0 ; i --)
    {
        if(i != 0)
        {
            if(line1[i] == ' ')
            {
                op++;
                if(op % 2 == 1)
                {
                    flag1->upr = sum;
                    sum = 0;
                    cnt = 1;
                }
                else
                {
                    flag1->udr = sum;
                    flag1->next = (num*)malloc(sizeof(num));
                    flag1 = flag1->next;
                    sum = 0;
                    cnt = 1;
                }
            }
            else
            {
                sum+=(line1[i]-'0') * cnt;
                cnt*=10;
            }
        }
        else
        {
            sum+=(line1[i]-'0') * cnt;
            flag1->udr = sum;
            flag1->next = (num*)malloc(sizeof(num));
            flag1 = flag1->next;
        }
        
    }
    flag1->next = NULL;
    flag1 = head1;
    num *head2 = (num*)malloc(sizeof(num));
    num *flag2 = head2;
    op = 0;
    cnt = 1;
    sum = 0;
    for(int i = strlen(line2)-1 ; i >= 0 ; i --)
    {
        if(i != 0)
        {
            if(line2[i] == ' ' || i == 0)
            {
                op++;
                if(op % 2 == 1)
                {
                    flag2->upr = sum;
                    sum = 0;
                    cnt = 1;
                }
                else
                {
                    flag2->udr = sum;
                    flag2->next = (num*)malloc(sizeof(num));
                    flag2 = flag2->next;
                    sum = 0;
                    cnt = 1;
                }
            }
            else
            {
                sum+=(line2[i]-'0') * cnt;
                cnt*=10;
            }
        }
        else
        {
            sum+=(line2[i]-'0') * cnt;
            flag2->udr = sum;
            flag2->next = (num*)malloc(sizeof(num));
            flag2 = flag2->next;
            sum = 0;
            cnt = 1;
        }
    }
    flag2->next = NULL;
    flag2 = head2;
    while(flag1->next != NULL)
    {
        while(flag2->next != NULL)
        {
            flag3->upr = flag1->upr + flag2->upr;
            flag3->udr = flag1->udr * flag2->udr;
            flag3->next = (num*)malloc(sizeof(num));
            flag3 = flag3->next;
            flag2 = flag2->next;
        }
        flag1 = flag1->next;
        flag2 = head2;
    }
    flag3->next = NULL;
    num*flag = (num*)malloc(sizeof(num));
    int tmp;
    flag3 = head3;
    for(flag3 ; flag3->next->next != NULL ; flag3 = flag3->next)
    {
        for(flag = flag3->next ; flag->next != NULL ; flag = flag->next)
        {
            if(flag3->upr < flag->upr)
            {
                tmp = flag3->upr;
                flag3->upr = flag->upr;
                flag->upr = tmp;
                tmp = flag3->udr;
                flag3->udr = flag->udr;
                flag->udr = tmp;
            }
        }
    }
    flag3 = head3;
    for(flag3 ; flag3->next->next != NULL ; )
    {
        if(flag3->upr == flag3->next->upr)
        {
            flag3->udr += flag3->next->udr;
            flag3->next = flag3->next->next;
            continue;
        }
        flag3 = flag3->next;
    }
    flag3 = head3;
    while(flag3->next != NULL)
    {
        printf("%d %d ",flag3->udr,flag3->upr);
        flag3 = flag3->next;
    }
    system("pause");
    return 0;
}
