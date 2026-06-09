#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <stdio.h>
int main()  
{
int n,i,j;
scanf("%d",&n);
int a[110][5]={0};
for(i=0;i<n;i++)
{
    for(j=0;j<4;j++)
    {
        scanf("%d",&a[i][j]);
    }
}
int num=0,ans=0;
int b[110]={0};
int k=0,ansi=0;
for(i=0;i<n;i++)
{
    b[i]=1;
    k=i;
    for(j=0;j<n;j++)
    {
        if(b[j]==0&&a[k][2]==a[j][0]&&a[k][3]==a[j][1])
        {
            b[j]=1;
            num++;
            k=j;
            j=-1;
        }
    }
    if(num>=ans)
    {
        ans=num+1;
        ansi=i;
    }
    memset(b,0,sizeof(b));
    num=0;
}
printf("%d %d %d",ans,a[ansi][0],a[ansi][1]);
 return 0;
}

