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
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0')))
flag=1; // @@ The flag is set to 1 but never reset to 0 for subsequent characters, causing all characters after the first expansion to be skipped.
if(flag!=1)
printf("%c",a[i]); // @@ When flag is 1, this condition is false, so the character before '-' (like 'u' in "a-u") is not printed, and subsequent non-expansion characters are also skipped.
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0')))
{
while(i1<(a[i+1]-a[i-1]))
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