#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define N 1005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
typedef long long ll;
int read();
int isfuhao(char a)
{
if(a=='+')
return 1;
else if(a=='-')
return 1;
else if(a=='*')
return 1;
else if(a=='/')
return 1;
else 
return 0;
}
int main()
{
char a[100];
gets(a);
char b[100];
int number[100];
char zifu[100];
int  shuzi[100];//shuzu
int j=0;
int k=0;
int l=0;
int ch=0;
int check=0;
int hash[100];
for(int q=0;q<=99;q++)
hash[q]=0;
for(int i=0;i<=strlen(a)-1;i++)
{
    if(a[i]!=' ')
    {
    b[j]=a[i];
    j++;
    }
}
int i=0;
while(b[i]!='=')
{
  if(b[i]>='0'&&b[i]<='9')
{
   number[k]=b[i]-'0';
   i++;
 
   while(b[i]>='0'&&b[i]<='9')
   {
      number[k]=10*number[k]+b[i]-'0';     
      i++;
}
   k++;   
} 
  else if(isfuhao(b[i])==1)
  {zifu[l]=b[i];
   if(b[i]=='/')
   hash[l]=1;
   else if(b[i]=='*')
   hash[l]=2;
   l++;
   i++;
  }
}
for(i=0;i<=l;i++)
{
   if(hash[i]==2)
   {
   number[i+1]=(number[i])*(number[i+1]);
   }
   else if(hash[i]==1)
   {   
       number[i+1]=(number[i])/(number[i+1]);
   }
   else if(hash[i]==0)
   { 
   shuzi[check]=number[i];
   check++;
   }
}
int sum=shuzi[0];
check=1;
for(i=0;i<=l-1;i++)
{
 if(zifu[i]=='+')
{
  sum=sum+shuzi[check];
  check++;
}
 else if(zifu[i]=='-')
 {
 sum=sum-shuzi[check];
 check++;
}
}
printf("%d",sum);
return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}




