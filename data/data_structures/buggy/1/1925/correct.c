#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define PI 3.2415926536
#define eps 1e-8
#define MAX 1000005
#define arrlen(x) (sizeof(x)/sizeof(x[0]))//数组长度

//求最大值
int Max(int,int);

//整数平方longlong输出
long long mpow(int,int);

//辗转相除求最大公约
int gcd(int,int);



//转义 \ -> \\;% -> %%; ' -> \' '' -> \''

//求字符串长度len=strlen(s);

/*
    FILE *in, *out;
    in = fopen("filein.txt","r");
    out = fopen("fileout.txt","w");

    fclose(in);
    fclose(out);
*/

//while((content[i++] = fgetc(in))!=EOF);
//fputc(,out);

int SWAP(int ,int);

int pailie(int ,int );


int ans[15];

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        ans[i]=i+1;
    }



    pailie(0,n-1);


    return 0;

}


long long mpow(int x,int y)
{
    long long ans = 1;
    for(int i = 0;i < y;i++)
    {
        ans *= x;
    }
    return ans;
}

int Max(int a, int b)
{
    return (a > b) ? a : b;
}

int gcd(int a,int b)
{
    return a%b?gcd(b,a%b):b;
}

int SWAP1(int a,int b)
{
    int i;
    int re=ans[b];
    for(i = 0;i < (b-a);i++)
    {
        ans[b-i]=ans[b-i-1];
    }
    ans[a]=re;

}

int SWAP2(int a,int b)
{
    int i;
    int re=ans[a];
    for(i = 0;i < (b-a);i++)
    {
        ans[a+i]=ans[a+i+1];
    }
    ans[b]=re;

}

int pailie(int begin, int end)
{
    int i = 0,j = 0;
    if(begin == end)
    {
        for(i = 0;i <= end;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    else
    {
        for(j = begin;j <= end;j++)
        {
            SWAP1(begin,j);
            pailie(begin + 1,end);
            SWAP2(begin,j);
        }
    }
}


