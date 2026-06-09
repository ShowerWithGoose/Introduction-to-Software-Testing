#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct link
{
    int d;
    int n;
    struct link *next;
};

int an[100][2], bn[100][2];

int main(int argc, char const *argv[])
{
    char a[500],b[500];
    struct link *p, *head;
    p = (struct link *)malloc(sizeof(struct link));
    head = (struct link *)malloc(sizeof(struct link));
    head->next = p;
    gets(a);gets(b);
    for(int i=0,j=0;a[i]!=0;i++)
    {
        while(a[i]>='0'&&a[i]<='9')
        {
            an[j][0]=an[j][0]*10+a[i]-'0';
            i++;
        }
        i++;
        while(a[i]>='0'&&a[i]<='9')
        {
            an[j][1]=an[j][1]*10+a[i]-'0';
            i++;
        }
        j++;
    }
    for(int i=0,j=0;b[i]!=0;i++)
    {
        while(b[i]>='0'&&b[i]<='9')
        {
            bn[j][0]=bn[j][0]*10+b[i]-'0';
            i++;
        }
        i++;
        while(b[i]>='0'&&b[i]<='9')
        {
            bn[j][1]=bn[j][1]*10+b[i]-'0';
            i++;
        }
        j++;
    }
    for (int i = 0; an[i][0] != 0; i++)
    {
        for (int j = 0; bn[j][0] != 0; j++)
        {
            if (i == 0 && j == 0)
            {
                head->d = an[i][0] * bn[j][0];
                head->n = an[i][1] + bn[j][1];
                p->n=-1;
            }
            else
            {
                for (p = head; p->next->n > an[i][1] + bn[j][1]; p = p->next)
                    ;
                if (p->next->n == an[i][1] + bn[j][1])
                {
                    p->next->d = p->next->d + an[i][0] * bn[j][0];
                }
                else
                {
                    struct link *tmp;
                    tmp = (struct link *)malloc(sizeof(struct link));
                    tmp->d = an[i][0] * bn[j][0];
                    tmp->n = an[i][1] + bn[j][1];
                    tmp->next = p->next;
                    p->next = tmp;
                }
            }
        }
    }
    for (p = head; p->n != -1; p = p->next)
    {
        printf("%d %d ", p->d, p->n);
    }
    return 0;
}

