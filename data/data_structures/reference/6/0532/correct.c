#include <stdio.h>
int main(){
int a[101];
int n1,n2;
int i=1;
while(1)
{scanf("%d",&n1);
if(n1==-1)
break;
else if(n1==1)
{
if(i==101)
printf("error ");
else
{
scanf("%d",&n2);
a[i++]=n2;
}
}
else if(n1==0)
{
if(i==1)
printf("error ");
else
{
i--;
printf("%d ",a[i]);
}
}
}

return 0;
}




