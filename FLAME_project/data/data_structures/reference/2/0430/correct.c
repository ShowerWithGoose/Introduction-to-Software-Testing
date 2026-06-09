#include<stdio.h>
#include<strings.h>
#include<math.h>

typedef struct group1
{
    double number;
    char point;
}group;

int main()
{
    char a[100] = "";
    char *flag;
    gets(a);
    flag = strchr(a,' ');
    while(flag != NULL)
    {
        for(flag ; flag <= &a[strlen(a) - 1] ; flag++)
        {
            *flag = *(flag + 1);
        }
        flag = strchr(a, ' ');
    }
    int wei_cnt = 0,sum = 0,cnt = 0;//把数字和前面的符号存起来
    group group[100];
    group[0].point = '+';
    flag = &a[strlen(a)-2];
    for(flag ; flag >= a ; )
    {
        while(*flag >= '0' && *flag <= '9')
        {
            wei_cnt ++;
            sum += (*flag - '0') * pow(10,wei_cnt-1);
            flag --;
        }
        group[cnt].number = sum;
        if(flag < a) break;
        group[cnt].point = *flag;
        flag --;
        wei_cnt = 0;
        sum = 0;
        cnt ++;
    }
    group[cnt].point = '=';
    for(int i = 0 ; i <= cnt ; i ++)
    {
        if(group[i].point == '/')
        {
            group[i].number = 1.0 / group[i].number;
            group[i].point = '*';
        }
        if(group[i].point == '-')
        {
            group[i].number = -group[i].number;
            group[i].point = '+';
        }
    }
    for(int i = 0; i <= cnt ; i ++)
    {
        if(group[i].point == '*')
        {
            group[i+1].number = group[i+1].number * group[i].number;
            for(int j = i ; j > 0 ; j--)
            {
                group[j] = group[j-1];
                group[j-1].point = ' ';
            }
        }
    }
    for(int i = 0; i <= cnt ; i ++)
    {
        if(group[i].point == '+')
        {
            group[i+1].number = group[i+1].number + group[i].number;
            group[i].point = ' ';
        }
    }

    int m;
    m = (int)group[cnt].number;
    printf("%d" , m);

    system("pause");
    return 0;
}
