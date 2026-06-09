#include <stdio.h>
#include <string.h>
char string[]="123456789a";
int used[10]={0};
char output[10];
int length;
void Fun(int d)
{
int i;
for(i=0;i<=length;i++)
{
if(!used[i])
{
used[i]=1;
output[d]=string[i];
if(d==length)
{
for(d=0;d<length;d++)
{
if(output[d]=='a')
printf("10 ");
else printf("%c ",output[d]);
}
if(output[length]=='a')
printf("10\n");
else
printf("%c\n",output[length]);
}
else
Fun(d+1);
used[i]=0;
}
}
}
int main()
{
int n;
scanf("%d",&n);
string[n]=0;
length=strlen(string)-1;
Fun(0);
return 0;
} 

