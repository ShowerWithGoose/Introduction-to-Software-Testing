#include<stdio.h>
#include<string.h>
int main()
{
	char s[200];
	gets(s);
	int loc,d1;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='.')
			loc=i;	//找到小数点的位置 
	}
	if(loc==1) //小数点在第二位 
	{
		if(s[0]=='0'){ //如果第一位为0 
			for(int i=2;i<len;i++){
				if(s[i]!='0'){
					d1=i;
					break;
				}
			}
			if(s[d1+1]=='\0')
				printf("%c",s[d1]);
			else{
				printf("%c.",s[d1]);
				for(int i=d1+1;i<len;i++)
				{
					printf("%c",s[i]);
				}
			}
			printf("e-%d",d1-loc);
			return 0;
		}
		else{
			for(int i=0;i<len;i++)
			{
				printf("%c",s[i]);
			}
			printf("e0");
			return 0;
		} 
	}
	else{
		printf("%c.",s[0]);
		for(int i=1;i<len;i++)
		{
			if(s[i]=='.')
				continue;
			printf("%c",s[i]);
		}
		printf("e%d",loc-1);
		return 0;
	}
}

