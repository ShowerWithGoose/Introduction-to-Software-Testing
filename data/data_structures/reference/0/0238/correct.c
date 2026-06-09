#include <stdio.h>
char app[1000];
void func(char *arr)//没有判断扩展长度问题 
{
	int i,j,m=0;//用i记录 -两边的大小 
	char *p;
	for(p=arr;*p!='-'&&*p!='\0';p++);//先指针转到'-'处 
	if(*p=='-')
	{
		m=1;	
	} 
	
	*p='\0';//将-前后分开 
	
	printf("%s",arr);//-前面打出来 
	
	
	
	if((*(p-1)>='a'&&*(p-1)<='z')&&(*(p+1)>='a'&&*(p+1)<='z'))//判断-前后是否符合条件 
	{
		i = *(p+1)-*(p-1); 
		if(i>0)
		{
			for( j=1;j<i;j++)
			{
				printf("%c",*(p-1)+j);
			}
			func(p+1);	
		}
		else
		{
			printf("-");
			func(p+1);
		}
			
	}
	else if((*(p-1)>='A'&&*(p-1)<='Z')&&(*(p+1)>='A'&&*(p+1)<='Z'))//判断-前后是否符合条件 
	{
		i = *(p+1)-*(p-1); 
		if(i>0)
		{
			for( j=1;j<i;j++)
			{
				printf("%c",*(p-1)+j);
			}
			func(p+1);	
		}
		else
		{
			printf("-");
			func(p+1);
		}
	}
	else if((*(p-1)>='0'&&*(p-1)<='9')&&(*(p+1)>='0'&&*(p+1)<='9'))//判断-前后是否符合条件 
	{
		i = *(p+1)-*(p-1); 
		if(i>0)
		{
			for( j=1;j<i;j++)
			{
				printf("%c",*(p-1)+j);
			}
			func(p+1);	
		}
		else
		{
			printf("-");
			func(p+1);
		}
	}
	else
	{
		if(m==1) printf("-");
		for(p++;*p!='\0';p++)
		{
			
			printf("%c",*p);
		}
		return;
	 } 
	
}
int main()
{
	gets(app);
	func(app);
	return 0;
	
}

