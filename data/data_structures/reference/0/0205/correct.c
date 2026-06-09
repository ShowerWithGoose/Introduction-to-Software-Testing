#include<stdio.h>
int main()
{
	char s[1000];
	int i,j;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i+1]=='-')
		{
			if((s[i]>47&&s[i]<58&&s[i+2]>47&&s[i+2]<58)||(s[i]>64&&s[i]<91&&s[i+2]>64&&s[i+2]<91)||(s[i]>96&&s[i]<122&&s[i+2]>96&&s[i+2]<122))
			{
				for(j=i;s[j]!=s[i+2];)
				{
					printf("%c",s[j]++);
				}
				i++;
			}
			else
				printf("%c",s[i]);
		}
		else
			printf("%c",s[i]);
	}
	return 0;
}

