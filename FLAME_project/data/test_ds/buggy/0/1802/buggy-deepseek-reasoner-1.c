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
flag=1; @@ [Missing check that a[i-1] < a[i+1]; also no bounds check for i==0 or i==n-1, and flag is never reset after processing, causing later characters to be skipped]
if(flag!=1)
printf("%c",a[i]); 
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0')))
{ @@ [Missing check that a[i-1] < a[i+1] and no bounds check for i==0 or i==n-1]
while(i1<(a[i+1]-a[i-1]))
{
printf("%c",a[i-1]+i1);
i1++;
}
i1=1;    @@ [Flag should be reset to 0 here (flag=0) to allow printing of the character after the dash and subsequent characters]
}
i++;    
}
return 0;
}