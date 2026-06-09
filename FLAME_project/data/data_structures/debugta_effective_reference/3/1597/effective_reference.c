#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	char str[100+10];
	scanf("%s",str);
	int a=0,i;
	if(str[0]=='-')
	{
		for(i=0;i<strlen(str);i++)
		{
			str[i]=str[i+1];
		}
		if(atoi(str)==0)
		{
			for(i=0;i<strlen(str);i++)
			{
				if(str[i]!='.'&&str[i]!='0')
					break;
				a++;
			}
			//printf("count=%d\n",count);
			printf("-%de-%d\n",atoi(str+a),a-1);
		}
		else if(0<atoi(str)&&atoi(str)<10)
			printf("-%se0\n",str);
		else
		{
			for(i=0;i<strlen(str);i++)
			{
				if(str[i]=='.')
					break;
				a++;
			}
			//printf("count=%d\n",count);
			for(i=a;i>=1;i--)
			{
				str[i]=str[i-1];
			}
			str[1]='.';
			printf("-%se%d\n",str,a-1);
		}
	}
	else
	{
		if(atoi(str)==0)
		{
			for(i=0;i<strlen(str);i++)
			{
				if(str[i]!='.'&&str[i]!='0')
					break;
				a++;
			}
			char s1[100],b[100];
			strcpy(s1,str+a);
			b[0]=s1[0];
			if(strlen(s1)>1)
			{
				b[1]='.';
				strcat(b,s1+1);
			}
			//printf("count=%d\n",count);
			printf("%se-%d\n",b,a-1);
		}
		else if(0<atoi(str)&&atoi(str)<10)
			printf("%se0\n",str);
		else
		{
			for(i=0;i<strlen(str);i++)
			{
				if(str[i]=='.')
					break;
				a++;
			}
			//printf("count=%d\n",count);
			for(i=a;i>=1;i--)
			{
				str[i]=str[i-1];
			}
			str[1]='.';
			printf("%se%d\n",str,a-1);
		}
	}
 	system("pause");
	return 0;
}


