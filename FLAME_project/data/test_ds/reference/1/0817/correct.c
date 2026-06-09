#include<stdio.h>
#include<string.h>
int main()
{ 
    char x[1000]; 
    int n,i,h,j,k;
	scanf("%s",&x[i]);
	n=strlen(x);
	for(i=0;i<=n;i++)
	{
		if((x[i+1]!='-')&&(x[i]!='-'))
		printf("%c",x[i]);
		if(x[i+1]=='-')
		{
			if((x[i]>='a')&&(x[i+2]<='z')&&(x[i]<x[i+2]))
			{
				for(j=0;j<(x[i+2]-x[i]);j++)
				printf("%c",x[i]+j);
			}
			else if((x[i]>='A')&&(x[i+2]<='Z')&&(x[i]<x[i+2]))
			{
				for(h=0;h<(x[i+2]-x[i]);h++)
				printf("%c",x[i]+h);
			}
			else if((x[i]>='0')&&(x[i+2]<='9')&&(x[i]<x[i+2]))
			{
				for(k=0;k<(x[i+2]-x[i]);k++)
				printf("%c",x[i]+k);
			}
			else
			{
				printf("%c",x[i]);
				printf("%c",x[i+1]);
			}
			
		}		
	}
	return 0;

}



