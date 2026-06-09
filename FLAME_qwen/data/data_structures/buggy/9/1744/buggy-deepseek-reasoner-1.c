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
int num[100]={0}; // @@ Array size too small for n up to 1024, may cause buffer overflow.
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
        count(s,j,i,n);
        }
    }
    return ;
}
int main()
{
int n,i,j;
scanf("%d",&n);
SF s[100]; // @@ Array size too small for n up to 1024, may cause buffer overflow.
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
 int ans=0,res; // @@ 'res' uninitialized; if no chain is found (all num[i]=0), using res leads to undefined behavior.
 for(i=0;i<n;i++)
 {
     count(s,i,i,n);
     if(num[i]>ans)
     {
    ans=num[i];
     res=i;
     }
 }
 printf("%d %d %d",ans+1,s[res].x1,s[res].y1);
 return 0;
}