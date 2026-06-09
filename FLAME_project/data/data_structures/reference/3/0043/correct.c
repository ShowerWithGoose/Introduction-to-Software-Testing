#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char a[200];
char ch;
int i,lena,k,d;
int main()
{
	while((ch=getchar())!='\n')
	{
		a[i]=ch;
		i++;
	}
	lena=strlen(a);
	if(a[1]=='.' && a[0]!='0')
	{
		for(i=0;i<lena;i++)
			printf("%c",a[i]);
		printf("e0");
	}
	else if(a[1]=='.' && a[0]=='0')
	{
		for(i=2;i<lena;i++)
		{
			if(a[i]!='0')
			{
				k=i;	
				break;
			}
		}
		for(i=k+1;i<lena;i++)
		{
			if(a[i]!='0')
			{
				d=1;
				break;
			}
		}
			printf("%c",a[k]);
			if(d==1)
			printf(".") ;
			for(i=k+1;i<lena;i++)
			printf("%c",a[i]);
			
			printf("e-%d",k-1);
	}
	else
	{
		for(i=0;i<lena;i++)
		if(a[i]=='.')
			{
			k=i;	
			break;
			}
			printf("%c",a[0]);
			printf(".");
			for(i=1;i<lena;i++)
			{
				if(i!=k)
				printf("%c",a[i]);
				
			}
			printf("e%d",k-1);
			
	}
return 0;
}


