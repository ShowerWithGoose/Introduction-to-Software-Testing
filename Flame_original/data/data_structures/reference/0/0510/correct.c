#include<stdio.h>
#include<string.h>

int main(void)
{
	char input[1000];
	scanf("%s",input);
	int i,j;
	
	for(i=0;i>=0;i++)
	{
		if(input[i]=='\0')
		  break;
	}
	int const len=i-1;//计算字符串长度 
	
	printf("%c",input[0]);
	
	for(i=1;i<len;i++)
	{
		if(input[i]=='-')//替换“-” 
		{
			if(input[i-1]>='a'&&input[i+1]<='z'&&input[i-1]<input[i+1])
			{
				for(j=1;input[i-1]+j<input[i+1];j++)
				  printf("%c",input[i-1]+j);
			}
			else if(input[i-1]>='A'&&input[i+1]<='Z'&&input[i-1]<input[i+1])
			{
				for(j=1;input[i-1]+j<input[i+1];j++)
				  printf("%c",input[i-1]+j);
			}	
			else if(input[i-1]>='0'&&input[i+1]<='9'&&input[i-1]<input[i+1])
			{
				for(j=1;input[i-1]+j<input[i+1];j++)
				  printf("%c",input[i-1]+j);
			}
			else
			 {
			 	printf("-");
			}	  
		}
		
		else//正常输出 
		{
			printf("%c",*(input+i));
		}
	}
	printf("%c",input[len]);
	return 0;
}

