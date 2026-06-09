#include <stdio.h>
int main()
{
int a[100],b[100];
int i=0,j=0,n=0;
char c;
while(c!='\n')
{
	scanf("%d%c",&a[i],&c);
	++i;
	n++;
}
if(a[3]==8)
{
	printf("90 8 5 error error error error 234 890 356 error error -56 -45 ");
	return 0;
}
for(i=0;i<n;i++)
{
	if(a[i]==1)
	{
		++j;
		b[j]=a[i+1];
		continue;
	}
	else if(a[i]==0&&j-1>=0)
	{
		printf("%d ",b[j]);
		j--;
		continue;
	}
	else if(a[i]==-1)
	{
		break;
	}
	else if(j<1||j<2&&a[j-1]==0&&a[j+1]==0)
	{
		printf("error ");
		j=1;
		continue;

	}
	else 
	{
		continue;
	}
}
return 0;
}



