//
//  main.c
//  0303
//
//  Created by  on 2022/3/3.
//


/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 105
#define num_of(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-10

void result(int, int, int);
void swap(int *, int *);
void initialize(int *, int, int);
int factorial(int);
int *p[15], N;
int main()
{
    int num[15];
    scanf("%d", &N);
    //N==1的情况
    if (1==N)
    {
        printf("1\n");
        return 0;
    }
    //2<=N<=10的情况
    for (int i=1; i<=N; i++)
    {
        num[i]=i;
        p[i]=&num[i];
    }
    result(1, N, 0);
    
    return 0;
}

void result(int a, int b, int layers)
{
    for (int i=a; i<=b; i++)//i总共循环b-a+1次
    {
        if(a+1==b)
        {
            for(int mm=0;mm<2;mm++)
            {
                for (int k=layers; k>0; k--)//???
                    printf("%d ", *p[a-k]);
                printf("%d %d\n", *p[a], *p[b]);
                swap(p[a], p[b]);
            }
            swap(p[a], p[b]);
            return;
        }
        result(a+1, b, layers+1);
        
        if(i<b)
        {
            if(a+1!=b) initialize(p[a+1], a+1, b);
            swap(p[a], p[i+1]);
        }
    }
}

void swap(int *pa, int *pb)
{
    int temp;
    temp=*pa;
    *pa=*pb;
    *pb=temp;
}

void initialize(int *q, int m, int n)
{
    int temp;
    int i, kk=(n-m+1)/2;
    for (i=0;i<kk; i++)
    {
        temp=*p[m+i];
        *p[m+i]=*p[n-i];
        *p[n-i]=temp;
    }
}

int factorial(int n)
{
    int i, ans=1;
    for (i=1; i<=n; i++)
        ans*=i;
    return ans;
}


