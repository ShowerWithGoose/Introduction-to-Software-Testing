#include <stdio.h>
#include <string.h>
char a[100000],b[100000];
int main()
{
int i=0,n,i1=1,flag=0;
gets(a); // @@ gets is deprecated/removed in C11 and often causes compilation errors in modern environments; use fgets instead.
n=strlen(a);
while(i<n)
{
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) // @@ Accesses a[i-1] when i=0 causing out-of-bounds read; also fails to check if a[i+1] > a[i-1] as required by the problem.
flag=1; // @@ flag is never reset to 0, so once a valid expansion is found, all subsequent characters will be incorrectly skipped.
if(flag!=1)
printf("%c",a[i]);
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) // @@ Redundant condition with same out-of-bounds and missing > check issues.
{
while(i1<(a[i+1]-a[i-1])) // @@ May cause infinite loop or incorrect output if a[i+1] <= a[i-1] due to missing validation.
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