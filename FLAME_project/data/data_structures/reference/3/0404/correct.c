#include<stdio.h>
int main()
{
	char a[110]={0};
	int i,k,m;
	for(i=0;i<110;i++)
	{
		a[i]='\0';
	}
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='.')
		break;
	} 
		int j;
		j=i;
		if(i==1&&a[0]=='0')
			{
				for(k=1;a[i+1]=='0';j++)
				{
					if(a[j+1]!='0')
					{
						break;
					}
					k++;
					
				}
				printf("%c",a[k+1]);
				if(a[k+2]!='\0')
				printf(".");
				for(j=k+2;a[j]!='\0';j++)
				{
					printf("%c",a[j]);
				}
				printf("e-%d",k);
			}
		else
		{
			printf("%c.",a[0]);
			for(k=1;k<j;k++)
			{printf("%c",a[k]);
			}
			for(m=k+1;a[m]!='\0';m++)
			{
				printf("%c",a[m]);
			 } 
			printf("e%d",i-1) ;
			}	
	
	
	
	
	
	
}



