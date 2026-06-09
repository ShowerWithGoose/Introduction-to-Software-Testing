#include<stdio.h>
char number[105];
int check(int flag,char num[])
{
	int i;
	if (flag==0)
	{
		for(i=0;num[i]!='.';i++);
		return i;
	}    
	if (flag==1)
	{
		for(i=2;num[i]=='0';i++);
		return i;
	}
}
int main()
{
	gets(number);
	int flag;
	if(number[0]!='0'&&number[1]=='.')
		printf("%se0",number);
	if(number[0]=='0'&&number[1]=='.')
	{
		flag=0;
		int l;
		for(l=0;number[l]!='\0';l++)
		{
			if(flag==1)
			    printf("%c",number[l]);
			if(flag==0&&number[l]!='0'&&number[l]!='\0'&&number[l]!='.')
			{
				if(number[l+1]=='\0')
				    printf("%c",number[l]);
				else
			        printf("%c.",number[l]);
			    flag=1;
			}
		}
		printf("e-%d",check(1,number)-1);
	}
	if(number[0]!='0'&&number[1]!='.')
	{
		printf("%c.",number[0]);
		int l=1;
		for(l=1;number[l]!='.'&&number[l]!='\0';l++)
		    printf("%c",number[l]);
		for(l=l+1;number[l]!='\0';l++)
		    printf("%c",number[l]);
		printf("e%d",check(0,number)-1);
	}
	return 0;
}

