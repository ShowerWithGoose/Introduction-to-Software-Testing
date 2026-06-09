#include<stdio.h>
#include<math.h>
#include<string.h>
char a[100];
void f(char a[])
{
	int flag=0,flag1=0,l,j=-1,max=101,min1=0;
    l=strlen(a);
    for(int i=0;i<l;i++)
    {
    	if(a[i]=='.')
    	{
    	flag++; 
    	j=i;
		}	
	}
	for(int i=0;i<l;i++)
    {
    	if(a[i]!='0'&&a[i]!='.')
    	{
    	max=i;
    	break;
		}	
	}
	if(max!=101)
	{
		for(int i=l-1;i>max;i--)
		{
			if(a[i]!='0'&&a[i]!='.')
			{
			min1=i;
			break;
		    }
		}	
	}
	if(max==101)
	{
		printf("0");
	}
	if(max>j&&j!=-1&&max!=101&&min1!=0)
	{
		printf("%c.",a[max]);
		for(int i=max+1;i<=min1;i++)
		{
			printf("%c",a[i]);
		}
		printf("e-%d",max-j);
	}
	if(max>j&&j!=-1&&max!=101&&min1==0)
	{
		printf("%c",a[max]);
		printf("e-%d",max-j);
	}
	if(max<j&&j!=-1&&max!=101&&min1!=0)
	{
		printf("%c.",a[max]);
		for(int i=max+1;i<=min1;i++)
		{
			if(a[i]=='.')
			continue;
			printf("%c",a[i]);
		}
		printf("e%d",j-max-1);
	}
	if(max<j&&j!=-1&&max!=101&&min1==0)
	{
		printf("%c",a[max]);
		printf("e%d",j-max-1);
	}
	if(j==-1&&max!=101&&min1!=0)
	{
		printf("%c.",a[max]);
		for(int i=max+1;i<=min1;i++)
		{
			printf("%c",a[i]);
		}
		printf("e%d",min1-max);
	}
	if(j==-1&&max!=101&&min1==0)
	{
		printf("%c",a[max]);
		if(l-1-max!=0)
		printf("e%d",l-1-max);	
	}
}
int main()
{
    gets(a);
    f(a);
    return 0;
}
