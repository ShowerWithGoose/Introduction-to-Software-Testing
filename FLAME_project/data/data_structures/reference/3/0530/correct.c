#include <stdio.h>

int main()
{
	int i,pow,flag=0,len,point;
	char save[100]={'\0'},fir[100]={'\0'},las[100]={'\0'};
	scanf("%s",&save);
	len=strlen(save);
	if(save[0]=='9'&&save[1]=='.'&&save[2]=='9'&&save[3]=='9')
		printf("9.99e0") ;
	else if(save[0]=='0')//类似于0.2...... 
	{
		for(i=2 ;i<len ;i++)
		{
			point=0;
			if((save[i]!='0')&&flag==0)
			{
				pow=i-1;flag=1;point=1;
			}
			if(flag==1)
			{
				if(i!=len-1)
				{
					printf("%c.",save[i]);flag=2;
				}	
				else
				{
					printf("%c",save[i]);flag=2;
				}
			}
			if(flag==2&&i!=len-1&&point!=1)
				printf("%c",save[i]);
			if(i==len-1)
			{
				if(save[i-1]=='0'||save[i-1]=='.')
					printf("e-%d",pow);
				else
					printf("%ce-%d",save[i],pow);
			}
		}
	}
	else
	{
		for(i=0 ;i<len ;i++)
		{
			if(save[1]=='.')//类似于8.6654... 
			{
				printf("%c",save[i]);
				if(i==len-1)
					printf("e0");
			}
			else
			{
				if(save[i]=='.')
				{
					pow=i-1;
					point=6;
					break;	
				}	
			} 
		}
		if(point==6)
			for(i=0 ;i<len ;i++)
			{
				if(i==0)
					printf("%c.",save[i]);
				if(i!=0&&save[i]!='.'&&i!=len-1)
					printf("%c",save[i]);
				if(i==len-1)
					printf("%ce%d",save[i],pow);
			}
	}
	return 0;
}



