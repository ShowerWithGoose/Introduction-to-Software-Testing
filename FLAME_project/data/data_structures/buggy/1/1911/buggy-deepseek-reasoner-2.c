#include <stdio.h>
#define MAX 10 // @@ Insufficient size for Mark array to index up to N (max 10); should be 11 to include index 10.

/*标记数组，用来标记某个数字是否已被使用成为*/
int Mark[MAX] = {0}; // @@ Mark array size is MAX (10), but loop uses Mark[i] for i up to N (10), so Mark[10] is out of bounds.
/*全排列数字串*/
char Stack[MAX+1]; // @@ Stack size insufficient to store spaces between numbers; need at least 2*N+1 characters.
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
    for(i=1; i<=N; i++) // @@ Loop accesses Mark[i] for i up to N (10), but Mark only has indices 0..9; also missing space insertion after Stack[m] assignment.
    {

        if(Mark[i]==0)
        {
            Mark[i] =1;/*标记该数字已被使用*/
            Stack[m]='0'+i;/*将当前数字加到全排列数字串中*/ // @@ Should also insert a space at Stack[m+1] before recursive call.
            rank(m+1,n-1);/*生成全排列中下一个数字*/ // @@ Should be rank(m+2,n-1) to account for the space.
            Mark[i] = 0;/*释放该数字*/
        }

    }
}