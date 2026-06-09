#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
char a[10000];
char b[10000];
int main()
{
	scanf("%s",&a);
	int n,i,j,k; 
	n=strlen(a)-1;
	for(i=0,j=0;i<=n;i++)
	{
	   if(a[i]=='-'&&i>0)
	   {
	   	if((a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A')||(a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'))
	   	{
	   		for(k=1;k<=a[i+1]-a[i-1]-1;k++,j++)
	   	    {
	   		b[j]=a[i-1]+k;
		    }
		}
		else
		b[j]=a[i],j++;
	   }
	   else 
	   b[j]=a[i],j++;
	}
	printf("%s",b);
    return 0;
}




