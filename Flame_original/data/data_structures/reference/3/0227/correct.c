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
char a[100];
gets(a);
int i=0;
int number=0;
while(a[i]!='.')
{
i++;    
number=number+1;
}
if(number==1&&a[0]=='0')
{   i=2;
    number=0;
    while(a[i]=='0')
    {number=number+1;
    i++;
}
printf("%c",a[i]);
if(i!=strlen(a)-1)
printf(".");
i++;
while(a[i]!='\0')
{
    printf("%c",a[i]);
    i++;
}
printf("e-%d",number+1);
}
else
{
for(i=number-1;i>=1;i--)
{
    a[i+1]=a[i];
}
a[1]='.';

printf("%se%d",a,number-1);


}

return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}
