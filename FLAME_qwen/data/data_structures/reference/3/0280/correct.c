#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int len,i,position,j,num,count=0,x;//position记录小数点的位数，num记录第一个不是零的位，count记录零的数量 
	gets(a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]=='.')
		{
			position=i;
			break;
		}
	}
if(a[0]!='-')
{
		if((a[0]-'0')>0)
		{
			printf("%c",a[0]);
			printf(".");
			for(j=1;j<len;j++)
			{
				if(a[j]!='.')
				printf("%c",a[j]);
			 } 
			
			printf("e%d",position-1);
		}
		else
		{
			
			for(j=2;j<len;j++)
			{
				if((a[j]-'0')!=0)
				{
					num=j;
					break;
					
				}
				else
				{
					count++; 
				}	
				
			}
			if(num==len-1){
				printf("%c",a[num]);
				printf("e-%d",count+1);
			}
			else{
				printf("%c.",a[num]);
				for(x=num+1;x<len;x++)
				{
				printf("%c",a[x]);
				}
				printf("e-%d",count+1);
			}
			
		}
}	
if(a[0]=='-')
{
		if((a[1]-'0')>0)
		{
			printf("-%c",a[1]);
			printf(".");
			for(j=2;j<len;j++)
			{
				if(a[j]!='.')
				printf("%c",a[j]);
			 } 
			
			printf("e%d",position-2);
		}
		else
		{
			
			for(j=3;j<len;j++)
			{
				if((a[j]-'0')!=0)
				{
					num=j;
					break;
					
				}
				else
				{
					count++; 
				}	
				
			}
			if(num==len-1)
			{
				printf("-%c",a[num]);
				printf("e-%d",count+1);
			}
			else
			{
				printf("-%c.",a[num]);
				for(x=num+1;x<len;x++)
				{
				printf("%c",a[x]);
				}
				printf("e-%d",count+1);
			}
			
		}	
}	
	return 0;
 } 

