#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(a=b;a<c;a++)
#define ll long long
#define ull unsigned long long
int main()
{
	char a[1000]={'\0'},b[1000]={'\0'},c[10]={'\0'};
	int j,k,l=2,m; 
	gets(a);
	if(a[1]=='.'&&a[0]=='0')
	{
		for(k=2;k<1000;k++)
		{
			if(a[k]!='0'&&a[k]!='\0')
			{
				b[0]=a[k];
				if(a[k+1]=='\0')
				{
					l=1;
					break;
				}	
				
				else
				{
					b[1]='.';
					for(j=k+1;j<strlen(a);j++)
					{
						b[l]=a[j];
						l++; 
					}
				}
				break;
			}	
		}
		b[l]='e';	
		b[l+1]='-';	
		printf("%s",b);printf("%d",k-1);
	}
	else if(a[1]=='.'&&a[0]!='0')
	{
		for(k=0;k<strlen(a);k++)
		{
			b[k]=a[k];
		}
		b[k]='e';
		b[k+1]='0';
		printf("%s",b);
	}
	else
	{
		b[0]=a[0];
		b[1]='.';
		for(k=1;k<strlen(a);k++)
		{
			if(a[k]!='.')
			{
				b[k+1]=a[k];
			}
			else
			break;
		}
		for(m=k+1;m<strlen(a);m++)
		{
			b[m]=a[m];
		}
		b[m]='e';
		printf("%s",b);
		printf("%d",k-1);
	}
	return 0;
}



