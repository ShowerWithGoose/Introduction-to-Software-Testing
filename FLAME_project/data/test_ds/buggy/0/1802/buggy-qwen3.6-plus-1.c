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
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) // @@ Missing condition a[i+1] > a[i-1] to ensure expansion only occurs when the right character is greater than the left one.
flag=1; // @@ flag is never reset to 0, causing subsequent characters to be skipped after the first valid expansion.
if(flag!=1)
printf("%c",a[i]); 
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) // @@ Missing condition a[i+1] > a[i-1] here as well.
{
while(i1<(a[i+1]-a[i-1])) // @@ Loop condition uses < instead of <=, which misses the last character of the expansion range.
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