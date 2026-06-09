#include<stdio.h>
#include<string.h>
char str[15];
int mark[15];
int n;
void rank(int x,int y)
{
    int i=1;
    if(y==0)
    {
        puts(str); // @@ str is not null-terminated before calling puts, leading to undefined behavior; additionally, the output format requires spaces between integers, which puts does not provide.
        return;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(mark[i]==0)
            {
                str[x]=i+'0'; // @@ Converting integer to char using i+'0' only works for single digits (1-9). For N=10, this produces incorrect characters. Also, it does not handle space separation.
                mark[i]=1;
                rank(x+1,y-1);
                mark[i]=0;
            }
        }
    }
 } 
 int main()
 {
     scanf("%d",&n);
     rank(0,n);
     return 0;
 }