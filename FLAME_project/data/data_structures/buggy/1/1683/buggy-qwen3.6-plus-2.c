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
        str[x] = '\0'; // @@ The null terminator is missing before printing, which can lead to garbage output or incorrect string handling.
        puts(str);
        return;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(mark[i]==0)
            {
                str[x]=i+'0';
                if (x > 0) str[x-1] = ' '; // @@ Spaces are missing between numbers in the permutation. A space should be added before the current digit if it's not the first one.
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