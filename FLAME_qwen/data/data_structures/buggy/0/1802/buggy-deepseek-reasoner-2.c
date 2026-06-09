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
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) @@ // Missing bounds check (i>0 && i<n-1) and missing ordering check (a[i-1] < a[i+1])
flag=1;
if(flag!=1)
printf("%c",a[i]); 
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))) @@ // Missing bounds check and ordering condition; also duplicate condition
{
while(i1<(a[i+1]-a[i-1])) @@ // Loop condition should be <= to include last character; also need to handle non-positive difference
{
printf("%c",a[i-1]+i1);
i1++;
}
i1=1;    
}
i++; @@ // After expansion, should increment i an extra time to skip the end character and reset flag=0
}
return 0;
}