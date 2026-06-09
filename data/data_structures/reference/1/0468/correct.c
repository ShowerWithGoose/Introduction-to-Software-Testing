#include<stdio.h>
#include<string.h>
int mark[10]={0};
char a[11];
void rank(int m,int n);
int N;
int main()
{
    scanf("%d",&N);
    rank(0,N);
    return 0;
}
void rank(int m,int n)
{
    int i,j;
    if(n==0)
    {
        a[m]='\0';
       for(j=0;a[j]!='\0';j++)
       {
           printf("%c ",a[j]);
       }
       printf("\n");
        return 0;
    }
    for(i=1;i<=N;i++)
    {
        if(mark[i]==0)
        {
            mark[i]=1;
            a[m]='0'+i;
            rank(m+1,n-1);
            mark[i]=0;
        }
    }
}



