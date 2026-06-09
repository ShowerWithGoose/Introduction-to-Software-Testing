#include<stdio.h>
#include<string.h>
int main()
{
	char ch[110],dec_part[100];
	char* p,q;
	int int_part,i,j,k;
	gets(ch);
	if(ch[0]=='0')
	{
		for(i=2;i<strlen(ch);i++)
		{
			if(ch[i]>='1')
			{
				int_part=ch[i]-'0';
				if(ch[i+1]!='\0')
				{
				p=&ch[i+1];
				strcpy(dec_part,p);
				k=strlen(p);
				j=&ch[i]-&ch[2]+1;
				printf("%d.%se%d",int_part,dec_part,-j);
				return 0;
				}
				else
				{
				j=&ch[i]-&ch[2]+1;
				printf("%de%d",int_part,-j);
				return 0;
				}
			}
		}
	}
	else
	{
		int_part=ch[0]-'0';
		for(i=1;i<strlen(ch);i++)
		{
			if(ch[i]=='.')
			{
				ch[i]='\0';
				p=&ch[i+1];
				strcat(ch,p);
				strcpy(dec_part,&ch[1]);
				j=&ch[i-1]-&ch[1]+1;
				printf("%d.%se%d",int_part,dec_part,j);
				return 0;
			}
		}
		strcpy(dec_part,&ch[1]);
		for(i=0;i<strlen(dec_part);i++)
		{
			if(dec_part[i]!=0)
			{
				j=strlen(dec_part);
				printf("%d.%se%d",int_part,dec_part,j);
				return 0;
			}
		}
		j=strlen(ch)-1;
		printf("%de%d",int_part,j);
	}
	return 0;
}

