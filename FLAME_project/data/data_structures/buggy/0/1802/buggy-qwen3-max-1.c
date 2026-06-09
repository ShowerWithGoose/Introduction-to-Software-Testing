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
flag=1; // @@ [This flag is set globally for the entire loop, but it should only affect the current '-' expansion. Also, it doesn't check if a[i+1] > a[i-1], violating the requirement that expansion only occurs when the right character is greater.]
if(flag!=1)
printf("%c",a[i]);  // @@ [Because 'flag' is not reset per '-', once a valid '-' is found, all subsequent characters (even non-expansion ones) may be mishandled. Also, this prints the '-' itself when flag==0, but in valid expansions, the '-' and surrounding chars should be replaced—not printed as-is.]
if(a[i]=='-'&&((a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0')))
{
while(i1<(a[i+1]-a[i-1])) // @@ [The loop condition should be i1 <= (a[i+1] - a[i-1]) to include the last character. Currently, it stops one short, so 'u' in a-u is missing, and 'F' in B-F is missing. Also, it doesn't verify that a[i+1] > a[i-1]; if not, no expansion should occur.]
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