#include<stdio.h>
#include<strings.h>

int main()
{
    char num[100] = "";
    int cnt_fro, cnt_beh, cnt = 0;
    char *flag;
    gets(num);
    flag = strchr(num,'.');
    cnt_fro = flag - num;
    cnt_beh = &num[strlen(num)-1] - flag;
    if(cnt_fro == 1)
    {
        if(num[0] == '0')
        {
            while(*(flag + 1) == '0')
            {
                flag ++;
                cnt ++;
            }
            *flag = *(flag + 1);
            *(flag + 1)= '.';
            if(*(flag + 2) == '\0')
            {
                *(flag + 1) = *flag;
                flag ++;
            }
            for (flag ; flag <= &num[strlen(num)-1]; flag++)
            {
                printf("%c",*flag);
            }
            printf("e-%d", cnt+1);
        }
        else
        printf("%se0",num);
    }
    else
    {
        while(flag > &num[1])
        {
            *(flag) = *(flag - 1);
            flag --;
            cnt++;
        }
        *(flag) = '.';
        printf("%se%d",num,cnt);
    }

    system("pause");

    return 0;
}
