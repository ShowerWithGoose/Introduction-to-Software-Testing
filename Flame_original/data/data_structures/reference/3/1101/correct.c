#include<stdio.h>
#include<string.h>
int main()
{
	char s[105];
	int i,j,counter1=0,counter2=0,counter3=0;
	gets(s);
	for(i=0;s[i]!='.';i++)
	{
		counter1++;
	}
	if(counter1==1&&s[0]=='0')
	{
		for(i=2;s[i]=='0';i++)
		{
			counter2++;
		}
		for(i=counter2+2;s[i]!='\0';i++)
		{
			counter3++;
		}
		if(counter3==1)
		printf("%c",s[counter2+2]);
		else
		{
		    printf("%c.",s[counter2+2]);
		   for(i=counter2+3;s[i]!='\0';i++)
		   {
			   printf("%c",s[i]);
		   }
    	}
		printf("e-%d",counter2+1);
	}
	else
	{
		printf("%c.",s[0]);
		for(i=1;i<counter1;i++)
		{
			printf("%c",s[i]);
		}
		for(i=counter1+1;s[i]!='\0';i++)
		{
			printf("%c",s[i]);
		}
		printf("e%d",counter1-1);
	}
	return 0;
}

