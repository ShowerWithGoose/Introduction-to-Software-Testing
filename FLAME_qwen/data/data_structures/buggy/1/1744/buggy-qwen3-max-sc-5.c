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
            printf("%d",s[j]); // @@ [Missing space after each number; output format requires space-separated integers]
        }
        printf("\n");
    }
        for(i=1;i<=n;i++) // @@ [Loop is outside the if block but intended to be part of the function logic; however, this is not a compilation error. The actual issue is the missing space in output. Also, no compilation error exists in code logic, but the test environment failed due to missing compiler, which is external. However, based on problem context and expected vs buggy output, the real bug is formatting.]
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