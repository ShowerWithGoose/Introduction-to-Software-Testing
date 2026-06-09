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
flag=1; // @@ The condition does not check that the character after '-' is greater than the one before it, as required by the problem. Also, flag is set but never reset to 0, causing subsequent characters to be incorrectly skipped.
if(flag!=1)
printf("%c",a[i]); // @@ When flag is 1, this line is skipped, but the '-' character itself is not printed, which is incorrect for cases where expansion should not occur (e.g., a-R). Additionally, flag is never reset to 0 after processing a valid expansion.
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