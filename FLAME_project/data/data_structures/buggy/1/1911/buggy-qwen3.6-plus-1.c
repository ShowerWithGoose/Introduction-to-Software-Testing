#include <stdio.h>
#define MAX 10

/*标记数组，用来标记某个数字是否已被使用成为*/
int Mark[MAX] = {0};
/*全排列数字串*/
char Stack[MAX+1];
/*m记录下一个要生成的全排列数字应放在Stack中的位置，n表示还剩几个数字需要
生成*/
void rank(int m,int n);
int N;
int main()
{
    scanf ("%d",&N);
    rank(0,N);
    return 0;
}

void rank(int m,int n)
{
    int i;
    if(n==0)
    {
        Stack[m] ='\0';
        puts(Stack);/*输出全排列数字串*/
        return;
    }
    for(i=1; i<=N; i++)
    {

        if(Mark[i]==0)
        {
            Mark[i] =1;/*标记该数字已被使用*/
            Stack[m]='0'+i;/*将当前数字加到全排列数字串中*/
            Stack[m+1] = ' '; // @@ The reference program adds a space after each number to separate them. The buggy code misses this, causing numbers to be concatenated (e.g., "12" instead of "1 2").
            rank(m+2,n-1);/*生成全排列中下一个数字*/ // @@ Since a space character is added at m+1, the next digit should be placed at m+2, not m+1.
            Mark[i] = 0;/*释放该数字*/
        }

    }
}