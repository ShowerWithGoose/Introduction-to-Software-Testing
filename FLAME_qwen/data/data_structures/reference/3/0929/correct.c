#include<stdio.h>
#include<string.h>
int main()
{
	char a[110];
	scanf("%s", a);
	int len,i,n,m,j=0,b[110];
	len=strlen(a);
	for(i=0;i<len;i++){
		if(a[i]=='.')
			n=i;
		else
		{
			b[j]=a[i]-'0';
			j++;
		}
	}
	m=j-1;
	if(n>=2)
	{
		printf("%d.",b[0]);
		for(i=1;i<=m;i++){
			printf("%d",b[i]);
		}
		printf("e%d",n-1);
	}
	else
	{
		if(b[0])
		{
			printf("%d.",b[0]);
			for(i=1;i<=m;i++){
				printf("%d",b[i]);
			}
			printf("e0");
		}
		else
		{
			int count=0;
			for(i=0;i<=m;i++){
				if(b[i]==0)
				{
					count++;
					continue;	
				}
				else
					break;
			}
			if(count!=m)
				printf("%d.",b[count]);
			else
				printf("%d",b[count]);
			for(i=count+1;i<=m;i++){
				printf("%d",b[i]);
			}
			printf("e-%d",count); 
		}
	}
	return 0;
}

