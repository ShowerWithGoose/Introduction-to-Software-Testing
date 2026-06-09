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
        for(i=1;i<=n;i++) // @@ [This loop is outside the 'if' block but should be inside the function body regardless; however, the real issue is missing space in output. Also, this line is not properly indented but that's not an error. The main functional error is in printf formatting.]
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