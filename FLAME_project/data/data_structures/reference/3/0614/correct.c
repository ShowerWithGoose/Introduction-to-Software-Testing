#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 10005
char arr[MAXSIZE],ans[MAXSIZE];
void change();
int main()
{
	scanf("%s",arr);
	change();
	printf("%s",ans);
	return 0;
}
void change()
{
    int n = strlen(arr);
    int key = -1;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if(arr[i] == '.')
        {
            key = i;
            break;
        }
    }//key标记.的位置
    if(key == 1 && arr[key - 1] == '0')
    {
        int cnt = 1;
        for (int i = key + 1; arr[i] == '0'; i++)
        {
            /* code */ cnt++;
        }
        char x = arr[key+cnt]; // x 存储第一个不为0的数
        int flag = 0;// 0 表示 之后全为0  1 表示之后不全为0
        if(key + cnt != n - 1) flag = 1;
        if(flag == 0)
        {
            ans[0] = x;
            ans[1] = 'e';
            ans[2] = '-';
            if(cnt < 10)
            {
                ans[3] = cnt % 10 + '0'; 
            }
            else if(cnt > 10 && cnt < 100)
            {
                ans[3] = cnt / 10+ '0';
                ans[4] = cnt % 10+ '0';
            }
        }
        if(flag == 1)
        {
            int sum = 0;
            ans[0] = x;
            ans[1] = '.';
            for(int i = 1; key + cnt + i < n; i++)
            {
                ans[i+1] = arr[key+cnt+i];
                sum++;
            }
            ans[sum+2] = 'e';
            ans[sum+3] = '-';
            if(cnt < 10)
            {
                ans[sum+4] = cnt % 10 + '0'; 
            }
            else if(cnt > 10 && cnt < 100)
            {
                ans[sum+4] = (cnt / 10) + '0';
                ans[sum+5] = (cnt % 10) + '0';
            }
        }
    }
    else
    {
        ans[0] = arr[0];
        ans[1] = '.';
        int x = key-1; // x 为 e的次幂
        int flag = 0,cnt = 0; // 0 表示后面全为0 1 表示后面不全为0
        for(int i = 1; i < n; i++)
        {
            if(arr[i] == '.')
            {
                continue;
            }
            ans[2+cnt] = arr[i];
            cnt++;
        }
        int tmp = strlen(ans);
        ans[tmp] = 'e';
        if(x < 10)
            {
                ans[tmp+1] = x % 10 + '0'; 
            }
            else if(x > 10 && x < 100)
            {
                ans[tmp+1] = x / 10+ '0';
                ans[tmp+2] = x % 10+ '0';
            }
    }
   
    return;
}


