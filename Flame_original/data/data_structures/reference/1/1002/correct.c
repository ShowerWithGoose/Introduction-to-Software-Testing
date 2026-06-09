#include <stdio.h>
#include <string.h>
int mark[12]={};
char stack[12];
void rank(int m,int n,int N)
{
    int i;
    if(n==0)
    {
        stack[m]='\0';
        for(i=0;i<strlen(stack);i++)
            printf("%c ",stack[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=N;i++)
        if(mark[i]==0)
        {
            mark[i]=1;
            stack [m]='0'+i;
            rank(m+1,n-1,N);
            mark[i]=0;
        }

}
int main() {
    int n;
    scanf("%d",&n);
    int N=n;
    rank(0,N,N);
    return 0;
}

