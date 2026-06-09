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
char b[100];
gets(a);
int i=0;
int j=0;
int k=0;
while(a[i]!='\0')
{
  if((a[i]>='a')&&(a[i+2]<='z')&&(a[i+1]=='-')&&(a[i+2]>a[i]))
  { b[j]=a[i];
     for(k=i+1;k<=(int)a[i+2]-(int)a[i]+i;k++)
     b[j+k-i]=(char)((int)a[i]+k-i);

     j=j+(int)a[i+2]-(int)a[i]-1;
     i=i+1;
  }
  else if((a[i]>='A')&&(a[i+2]<='Z')&&(a[i+1]=='-')&&(a[i+2]>a[i]))
  { b[j]=a[i];
     for(k=i+1;k<=(int)a[i+2]-(int)a[i]+i;k++)
     b[j+k-i]=(char)((int)a[i]+k-i);

     j=j+(int)a[i+2]-(int)a[i]-1;
     i=i+1;
  }
  else if((a[i]>='0')&&(a[i+2]<='9')&&(a[i+1]=='-')&&(a[i+2]>a[i]))
  { b[j]=a[i];
     for(k=i+1;k<=(int)a[i+2]-(int)a[i]+i;k++)
     b[j+k-i]=(char)((int)a[i]+k-i);

     j=j+(int)a[i+2]-(int)a[i]-1;
     i=i+1;
  }
  else 
  b[j]=a[i];
 j++; 
 i++;

}
b[j+1]='\0';
for(i=0;i<strlen(b)-1;i++)
printf("%c",b[i]);
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}


