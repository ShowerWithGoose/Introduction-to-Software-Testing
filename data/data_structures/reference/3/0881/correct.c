#include <stdio.h>
#include <string.h>
int main()  
{
	char num[100];
	scanf("%s",num);
	char *start= num;
	if(num[0] == '-') {
	printf("-");
	start++;
	}
	int len = strlen(start);
	char *p = strchr(start,'.');
	if(p!=NULL)
	{
		if(p-start==1)
		{
			if(*start!='0')
			printf("%se0",start);
			else
			{
				int st=2;
				while(start[st]=='0')st++;
				printf("%c",start[st]);
				if(st<len-1){
					printf(".");
					for(int i = st+1; i < len; i++)
					printf("%c",start[i]);
				}
				printf("e-%d",st-1);
			}
		}
		else{
			printf("%c.",*start);
			for(int i = 1; i < len; i++)
			if(start[i]!='.') printf("%c",start[i]);
			printf("e%d",p-start-1);
		}
		
	}
}
