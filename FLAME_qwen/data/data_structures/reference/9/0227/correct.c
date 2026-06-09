#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define N 1005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
typedef long long ll;
int read();
typedef struct{

int x1;
int y1;
int x2;
int y2;
int cnt;

} link;
link a[100];
link b[100];
int main()
{
int n;
int i,j;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i].x1);
        scanf("%d",&a[i].y1);
            scanf("%d",&a[i].x2);
                scanf("%d",&a[i].y2);
b[i].x1=a[i].x1;
  b[i].x2=a[i].x2;
  b[i].y1=a[i].y1;
  b[i].y2=a[i].y2;
                a[i].cnt=1;
                b[i].cnt=1;
}
i=1;
int swi;       
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{   
if(b[j].x1==a[i].x2&&b[j].y1==a[i].y2)
{
a[i].x2=b[j].x2;
a[i].y2=b[j].y2;
a[i].cnt++;
i--;
}
}
}
link m;
for(i=1;i<=n-1;i++)
{
    if(a[i].cnt>a[i+1].cnt)
    {
     m=a[i];
     a[i]=a[i+1];
     a[i+1]=m;      
    }
}
printf("%d %d %d",a[n].cnt,a[n].x1,a[n].y1);







return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}
