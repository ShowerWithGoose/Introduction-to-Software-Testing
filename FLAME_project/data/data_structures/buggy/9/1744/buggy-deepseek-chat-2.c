#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct f{
    int x1;
    int y1;
    int x2;
    int y2;
}SF;
int num[100]={0};
void fx(SF s[],int i)
{
    SF tmp;
    tmp=s[i];
    s[i]=s[i+1];
    s[i+1]=tmp;
}
void count(SF s[],int i,int k,int n)
{
    int j;
    for(j=i+1;j<n;j++)
    {
        if(s[i].x2==s[j].x1&&s[i].y2==s[j].y1)
        {
        num[k]++;
        count(s,j,i,n); // @@ [Error: The second argument should be j, not i, to continue the chain from the matched segment. Using i causes incorrect recursion and fails to find all connected segments.]
        }
    }
    return ;
}
int main()
{
int n,i,j;
scanf("%d",&n);
SF s[100];
for(i=0;i<n;i++)
{
    scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
} 
 for(i=0;i<n-1;i++)
 {
     for(j=0;j<n-i-1;j++)
     {
         if(s[j].x1>s[j+1].x1)
         fx(s,j);
     }
 }
 int ans=0,res;
 for(i=0;i<n;i++)
 {
     count(s,i,i,n);
     if(num[i]>ans)
     {
    ans=num[i];
     res=i;
     }
 }
 printf("%d %d %d",ans+1,s[res].x1,s[res].y1); // @@ [Error: ans+1 adds 1 incorrectly; the count function already counts the number of connected segments after the starting segment, so the total should be num[i]+1, not ans+1. Also, the starting point should be s[res].x1 and s[res].y1, but the sorting by x1 may not preserve the correct starting point for the longest chain.]
 return 0;
}