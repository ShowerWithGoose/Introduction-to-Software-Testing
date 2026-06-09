#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define N 1005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
typedef long long ll;
int read();
int main()
{
int op;
int a;
scanf("%d",&op);
int i=1;
int top=0;
int s[105];
while(op!=-1)
{
    if(op==1)
    {scanf("%d",&a);
     top++;
     if(top>100)
     {printf("error ");
      top--;
     }
     else
     {
         s[top]=a;
     }
    }
    else if(op==0)
    {
        if(top==0)
        printf("error ");
        else
        {
        printf("%d ",s[top]);    
        top--;
        }
    }
    scanf("%d",&op);
}

return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}
