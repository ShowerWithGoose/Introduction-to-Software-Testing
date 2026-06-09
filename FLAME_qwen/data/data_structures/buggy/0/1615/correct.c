#include <stdio.h>
#include <string.h>
int main()
{
	char str[20000];
	int sum,i,len;
 	gets(str); 
 	len = strlen(str);  // 获取字符串长度
 	for(i=0;i<len-2;i++)
 	{
 		if(str[i+1]=='-')
 		{
 			if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z')))
 			{
 				int m,n;
				m=(int)str[i];
				n=(int)str[i+2];
				int j;
				for(j=m;j<n;j++)
				{
					printf("%c",(char)j);
				}
				if(i==len-3)
				{
					printf("%c",str[i+2]);
				}
				i=i+1;
			}
			else
			{
				printf("%c",str[i]);
				if(i==len-3)
				{
					printf("%c%c",str[i+1],str[i+2]);
				}
			}
			
		}
		else
		{
			if(i==len-3)
			{
				printf("%c%c%c",str[i],str[i+1],str[i+2]);
			}
			else
			{
				printf("%c",str[i]);
			}
		}
	}
 	
	
	
	
	
	
	
	
	
	
	return 0;
} 

