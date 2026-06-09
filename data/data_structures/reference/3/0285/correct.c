// 1.找到小数点
// 1.小数点前面为0：
// 找到小数点后面不为0的第一个数，同时记录0的个数

// 2.小数点前不为0
// 1，一位的话直接输出
// 2.多位的话移动小数点到第一个数后，同时记录位数

#include<stdio.h>
#include<string.h>

int main()
{
    char s[500];
    gets(s);

    int len = strlen(s);

    int i = 0;
    for(i=0; s[i] != '.'; i++)
    ;

    if(s[i - 1] == '0' && i-1 == 0)
    {   
        int ans = 0;
        int j = 0;

        for(j = i + 1 ; j < len ;j++)
        {
        if(s[j] != '0')
        {
        ans = i - j;
        break;
        }
        }
        
        if(j == len - 1)
        {
            printf("%se%d",&s[j],ans);
        }
        
        else
        {
            s[j-1] = s[j];
            s[j] = '.';
            printf("%se%d",&s[j-1],ans);
        }
    }

    else
    {
        char ch = s[0];
        
        int ans = i - 1;

        for(int j = i; j >=2 ;j--)
        {
        s[j] = s[j - 1];
        }

        s[1] = '.';

        printf("%se%d",s,ans);
    }

    return 0;
}
