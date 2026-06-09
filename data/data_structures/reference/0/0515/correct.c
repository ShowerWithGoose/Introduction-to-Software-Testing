#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char ch[500],ch_[500];
	char* p;
	int i,j;
	gets(ch);
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='-')
		{
			j=i;
			if(isdigit(ch[i-1])&&isdigit(ch[i+1]))
			{
				if(ch[i-1]<ch[i+1])
				{
					p=&ch[i+1];
					strcpy(ch_,p);
					for(j=i;ch[j-1]+1!=ch_[0];j++)
					{
						ch[j]=ch[j-1]+1;
					}
					ch[j]='\0';
					strcat(ch,ch_);
				}
			}
			else if(islower(ch[i-1])&&islower(ch[i+1]))
			{
				if(ch[i-1]<ch[i+1])
				{
					p=&ch[i+1];
					strcpy(ch_,p);
					for(j=i;ch[j-1]+1!=ch_[0];j++)
					{
						ch[j]=ch[j-1]+1;
					}
					ch[j]='\0';
					strcat(ch,ch_);
				}
			}
			else if(isupper(ch[i-1])&&isupper(ch[i+1]))
			{
				if(ch[i-1]<ch[i+1])
				{
					p=&ch[i+1];
					strcpy(ch_,p);
					for(j=i;ch[j-1]+1!=ch_[0];j++)
					{
						ch[j]=ch[j-1]+1;
					}
					ch[j]='\0';
					strcat(ch,ch_);
				}
			}
		}
	}
	puts(ch);
	return 0;
}



