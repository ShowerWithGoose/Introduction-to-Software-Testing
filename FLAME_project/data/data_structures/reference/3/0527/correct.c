#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
int main()
{
	char array[105];//直接输入字符串字符串， 不超过100定义105个防止越界 
	int i=0,j=0,k,qian,chang;//k是小数点后用来计数第一个非零数所在位，qian指的是小数点前的位数 
	char *find; 
	scanf("%s",array);//输入字符串
	find=strchr(array,'.');//查找表小数点所在的位置 然后判断是否有小数点区分是整数还是小数 
	while(array[i]!='.')
	{
		i++;
	}
	qian=i;
	i=0;j=0; 
	for(j=qian+1;j<strlen(array);j++)
	{
	
		if(array[j]!='0')
		{
			k=j-qian;
			break;
		}
}
	if(find==NULL)//小数点不存在
	{
		puts(array);
	}//这是整数哪一类的代码 
	else if(qian==1)//这一类是所有的小数点前只有一位的 
	{ 
		if(array[0]=='0')
		{
			if(k==(strlen(array)-2))
			{
				printf("%c",array[k+1]);
				printf("e-%d",k); 
			}
			else
			{
				printf("%c.",array[k+1]);
				for(j=k+2;j<strlen(array);j++)
				{
					printf("%c",array[j]);
					
				}printf("e-%d",k);
			}
		}
		
		
	    if(array[0]!='0')//1.几或者2.几这种 在最后直接输入e0就可 
		{
			for(i=0;i<strlen(array);i++)
			{
				
				printf("%c",array[i]);
			 }
			 printf("e0");
		 } 
	}
	else 
	{
		printf("%c",array[0]);
		printf(".");
		for(i=1;i<qian;i++)
		{
			printf("%c",array[i]);
			
		 }
		 for(i=qian+1;i<strlen(array);i++)
	{
		printf("%c",array[i]); 
	}
	printf("e%d",qian-1);
	}
	return 0;
}


