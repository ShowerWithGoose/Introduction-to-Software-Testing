#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int n;
int s[100]={0},sign[100]={0};
void dfs(int num)
{
    int i;
    if(num>n)
    {
        int j;
        for(j=1;j<=n;j++)
        {
            printf("%d",s[j]); // @@ Missing space after %d; should be "%d " to separate numbers.
        }
        printf("\n"); // @@ Missing return statement after printing; should have "return ;" to prevent fall-through into the for loop.
    }
        for(i=1;i<=n;i++)
        {
            if(sign[i]==0)
            {
                sign[i]=1;
                s[num]=i;
            
            dfs(num+1);
            sign[i]=0;}
        }
 } 
int main()
{
scanf("%d",&n);
dfs(1);
 return 0;
}