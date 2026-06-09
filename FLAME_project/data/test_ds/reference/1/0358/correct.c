#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[1005]={'\0'};
	//memset(a,'\0',sizeof(a));
	
	int i=0,j=0;
	gets(a);
	//for(i=0;i<100;i++)
	//{
	//	printf("%d,",a[i]);
	//}
	//puts (a);
	for(i=0;i<1005;i++)
	{
		if (a[i]!=45)
			printf("%c",a[i]);
		else if(i!=0 && a[i-1]<a[i+1])
		{
			if(a[i-1]>='0' && a[i-1]<='9'  && a[i+1]>='0' && a[i+1]<='9' ||  a[i-1]>='a' && a[i-1]<='z'  && a[i+1]>='a' && a[i+1]<='z' || a[i-1]>='A' && a[i-1]<='Z'  && a[i+1]>='A' && a[i+1]<='Z')
			{
				for(j=a[i-1]+1;j<=a[i+1]-1;j++)
					printf("%c",j);
			}
			else
				printf("-");
		}
	}
	return 0;
}



