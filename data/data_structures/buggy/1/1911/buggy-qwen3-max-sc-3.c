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
        puts(Stack);/*输出全排列数字串*/ @@ [The output format requires each integer in a line to be separated by a space, but puts(Stack) prints the characters without spaces between them. Also, the digits are stored as characters (e.g., '1', '2'), so this outputs "123" instead of "1 2 3".]
        return;
    }
    for(i=1; i<=N; i++)
    {

        if(Mark[i]==0)
        {
            Mark[i] =1;/*标记该数字已被使用*/
            Stack[m]='0'+i;/*将当前数字加到全排列数字串中*/ @@ [Storing integers as characters (e.g., '1') prevents proper space-separated output later. Should store integer values or handle output differently.]
            rank(m+1,n-1);/*生成全排列中下一个数字*/
            Mark[i] = 0;/*释放该数字*/
        }

    }
}