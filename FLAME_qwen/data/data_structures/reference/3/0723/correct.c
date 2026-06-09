#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char a[105];
int point,fdigit;
int move;
int main()
{
    gets(a);
    for(int i=0;i<strlen(a);i++)
    {
    	if(a[i]=='.')
		{
			point=i;
			break;
		} 
	}
	for(int i=0;i<strlen(a);i++)
    {
    	if(a[i]>='1'&&a[i]<='9')
		{
			fdigit=i;
			break;
		} 
	}
	
	if(point!=0)
	{
		move=point-fdigit;
		if(move>0) move--;
		a[point]=127;
		for(int i=fdigit;i<strlen(a);i++)
		{
			if(a[i]<127)
			{
				printf("%c",a[i]);
				if(i==fdigit&&i<strlen(a)-1) printf(".");
			}
		}
	}
	else
	{
		if(point==0) point=strlen(a); 
		move=point-fdigit;
		if(move>0) move--;
		a[point]=127;
		int ldigit;
		for(int i=strlen(a)-1;i>=0;i--) 
		{
			if(a[i]>='1'&&a[i]<='9')
			{
				ldigit=i;
				break;
			} 
		}
		for(int i=fdigit;i<=ldigit;i++)
		{
				printf("%c",a[i]);
				if(i==fdigit&&i!=ldigit) printf(".");
		}
	}
	//printf("%d",move);
	printf("e%d",move);
	return 0;
}




