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


int ans[11];

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

int SWAP(int a,int b)
{
    int temp = ans[a];
    ans[a]=ans[b];
    ans[b]=temp;
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
            SWAP(begin,j);
            pailie(begin + 1,end);
            SWAP(begin,j); // @@ The swap-back approach does not restore the remaining elements to their original sorted order after the recursive call, which fails to generate permutations in lexicographical order as required by the problem.
        }
    }
} // @@ Function is declared to return int but lacks a return statement, which causes a compilation error in strict compiler settings.