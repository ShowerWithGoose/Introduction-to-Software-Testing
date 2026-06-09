#include <stdio.h>
#include <string.h>
char a[100000],b[100000];
int main()
{
int i=0,n,i1=1,flag=0;
gets(a);
n=strlen(a);
while(i<n)
{
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) @@ [Missing bounds check (i>0 && i<n-1) to prevent out-of-bounds access; also missing check that a[i-1] < a[i+1] to avoid reverse expansion.]
flag=1; @@ [Flag is set but never reset after expansion, causing subsequent characters (including the last character of the range) to be suppressed.]
if(flag!=1)
printf("%c",a[i]); 
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) @@ [Same missing bounds and order check as above.]
{
while(i1<(a[i+1]-a[i-1])) @@ [Condition does not ensure a[i+1] > a[i-1]; if a[i-1] >= a[i+1], the difference is non-positive, leading to incorrect or no expansion.]
{
printf("%c",a[i-1]+i1);
i1++;
}
i1=1;    
}
i++;    
}
return 0;
}