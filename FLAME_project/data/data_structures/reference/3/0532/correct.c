#include <stdio.h>
#include <string.h>
int main(){
char a[10000],b[10000],c[10000];
scanf("%s",a);
if(a[0]=='0')
{
int n=1,t=2,k=1;
while(a[t]=='0')
    n++,t++;
    b[0]=a[t];
    t++;
    if(a[t+1]!='\0')
    b[k++]='.';
for(;a[t]!='\0';t++)
{
      b[k++]=a[t];
}
b[k]='\0';
printf("%se-%d",b,n);
return 0;



}
else
{
int n=0,t=1,k=1;
 b[0]=a[0];
 if(a[1]!='\0')
 b[k++]='.';
 while(a[t]!='.'&&a[t]!='\0')
 {
     b[k++]=a[t];
     t++,n++;
}
t++;
while(a[t]!='\0')
{
    b[k]=a[t];
    k++;
    t++;
}
b[k]='\0';
printf("%se%d",b,n);

return 0;
}
}



