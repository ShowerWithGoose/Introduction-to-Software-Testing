#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
char a[110];
int main()
{
	int i=0,n,position=0,k;
	scanf("%s",&a);
	n=strlen(a);
	for(i;i<=n-1;i++)
	{
		if(a[i]=='.')
		{
			position=i;
		    break;
		}
	}
	if(i==1&&a[i-1]=='0')
	{
		for(k=2;k<=n-1;k++)
		{
		    if(a[k]!='0')
			break;	
		}
		int k1=k;
		putchar(a[k]);
		if(k!=n-1)
		{
			putchar('.');
		    k+=1;
		    for(k;k<=n-1;k++)
		    putchar(a[k]);
		}
		
		putchar('e');
		printf("%d",-1*(k1-1));
	}
	else if(i==1&&a[i-1]!='0')
    {
    	for(k=0;k<=n-1;k++)
    	putchar(a[k]);
    	printf("e0");
	}
	else if(i!=1)
	{
	    putchar(a[0]);
		putchar('.');
		for(k=1;k<position;k++)
		putchar(a[k]);
		for(k=position+1;k<=n-1;k++)
		putchar(a[k]);
		putchar('e');
		printf("%d",position-1);	
	}
    return 0;
}


