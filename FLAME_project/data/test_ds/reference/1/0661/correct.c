/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<ctype.h>
char num1,num2;
char s[10000],str[10000];
int main()
{
	gets(s);
	int i=0,j=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='-')
		{
			int flag=0;
			//printf("\n");
			num1=s[i-1];
			num2=s[i+1];
		//	printf("%c %c\n",num1,num2);
			if(isdigit(num1)&&isdigit(num2)) flag=1;
			if(islower(num1)&&islower(num2)) flag=1;
			if(isupper(num1)&&isupper(num2)) flag=1;
			if(flag)
			{
				//printf("\n");
				if(num2>num1)
				{
					int k=0;
					for(k=num1+1;k<=num2-1;k++)
					{
						str[j++]=k;
					}
				}	
			}
			else
			{
				str[j++]=s[i];
			}
		}
		else
		{
			str[j++]=s[i];
		}
	}
	str[j]='\0';
	puts(str);
	return 0;
}




