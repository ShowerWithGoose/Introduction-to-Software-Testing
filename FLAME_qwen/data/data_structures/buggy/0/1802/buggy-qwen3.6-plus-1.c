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
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) // @@ Accessing a[i-1] when i=0 or a[i+1] when i=n-1 causes out-of-bounds memory access; should verify i>0 && i<n-1 first.
flag=1; // @@ flag is set to 1 but never reset to 0, causing all characters after the first expansion to be skipped.
if(flag!=1)
printf("%c",a[i]); 
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) // @@ Same out-of-bounds issue; also missing the required check that a[i+1] > a[i-1] before expanding.
{
while(i1<(a[i+1]-a[i-1])) // @@ Missing condition to ensure a[i+1] > a[i-1]; if a[i+1] < a[i-1], expansion should not occur per problem statement.
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