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
            printf("%d",s[j]); // @@ [Missing space between numbers; should be "%d " to match expected output format]
        }
        printf("\n");
    } // @@ [Missing return statement; after printing a complete permutation, the function should return immediately to prevent further recursion]
        for(i=1;i<=n;i++) // @@ [This for loop should only run when num <= n; either place inside an 'else' block or add a return in the if block above]
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