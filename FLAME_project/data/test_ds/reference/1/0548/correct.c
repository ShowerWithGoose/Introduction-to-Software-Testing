#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char *xx = "abcdefghijklmnopqrstuvwxyz";
char *dx = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *sz = "0123456789";
int main()
{
char a[600];
scanf("%s",a);
int i;
for(i = 0;i<strlen(a);i++)
{
if(a[i]>='a'&&a[i]<='z')
printf("%c",a[i]);
if(a[i]>='A'&&a[i]<='Z')
printf("%c",a[i]);
if(a[i]>='0'&&a[i]<='9')
printf("%c",a[i]);
if(a[i]=='-')
{
if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])
{char *b;
int j=0;
for(b=xx;b<xx+26;b++)
{
if(*b==a[i+1])
break;
if(*b==a[i-1])
{
j=1;
continue;}
if(j==1)
printf("%c",*b);}}
else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
{
char *b;
int j=0;
for(b=dx;b<dx+26;b++)
{
if(*b==a[i+1])
break;
if(*b==a[i-1])
{
j=1;
continue;}
if(j==1)
printf("%c",*b);}}
else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])
{
char *b;
int j=0;
for(b=sz;b<sz+10;b++)
{
if(*b==a[i+1])
break;
if(*b==a[i-1])
{
j=1;
continue;}
if(j==1)
printf("%c",*b);}}
else
printf("%c",a[i]);


}





}
return 0;}


