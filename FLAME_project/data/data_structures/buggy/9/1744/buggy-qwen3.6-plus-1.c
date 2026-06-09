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
int num[100]={0}; // @@ The global array 'num' is not reset between test cases or different starting points in the loop, leading to accumulated counts from previous iterations. It should be reset to 0 for each new starting segment 'i'.
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
        count(s,j,i,n); // @@ The recursive call passes 'i' as the 'k' (original start index) argument, which is correct for accumulating count into the start index. However, the logic assumes a simple chain. If multiple segments connect, this might double count or miss branches depending on structure, but given constraints (no intersection, no 3+ share), it's likely a simple path. The main issue is the global state.
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
     count(s,i,i,n); // @@ The function 'count' modifies the global 'num' array. Since 'num' is not cleared before this call, it adds to values from previous iterations of 'i'. This causes incorrect counts.
     if(num[i]>ans)
     {
    ans=num[i];
     res=i;
     }
 }
 printf("%d %d %d",ans+1,s[res].x1,s[res].y1);
 return 0;
}