#include<stdio.h>
char a[100];
int flag[10]={0};
int N;

void perm(int m,int n)
{
    if(n==0)
    {
        a[m]='\0';
        puts(a);
        return;
    }
    else
    {
        for(int i=1;i<=N;i++)
        {
            if(flag[i]==0)
            {
                a[m]=i+'0';
                a[m+1]=' ';
                flag[i]=1;
                perm(m+2,n-1);
                flag[i]=0;
            }
        }
    }
}

int main()
{

    scanf("%d",&N);

    perm(0,N);
    return 0;
}

