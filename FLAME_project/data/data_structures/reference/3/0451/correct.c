#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char ch[105];
	char temp;
	int cnt=0, m;
	scanf("%s", ch);
	if(ch[0]!='0' && ch[1]=='.')
	printf("%se0", ch);
	else if(ch[0]=='0' && ch[1]=='.')
	{
		int i=2,k=strlen(ch);
		for(i=2;i<k;i++)
		{
			if(ch[i]!='0')
			{
				temp = ch[i];
				ch[i] = ch[i-1];
				ch[i-1] = temp;
				cnt++;
				break;
			}
			else
			{
				temp = ch[i];
				ch[i] = ch[i-1];
				ch[i-1] = temp;
				cnt++;
			}
		}
		m=cnt;
		if(ch[k-1]!='.')
		{
				for(;cnt<k;cnt++)
			{
				printf("%c", ch[cnt]);
			}
				printf("e-%d", m);
		}
		else
		{
			for(;cnt<k-1;cnt++)
		{
			printf("%c", ch[cnt]);
		}
		
			printf("e-%d", m);
		}	
	}
	else
	{
		int len1;
		len1 = strlen(ch);
		for(cnt=0;cnt<len1;cnt++)
		{
			if(ch[cnt]=='.')
			{
				m=cnt;
				break;
			}
		}
		for(;m>=2;m--)
		{
			temp = ch[m];
				ch[m] = ch[m-1];
				ch[m-1] = temp;
		}
		printf("%se%d", ch, cnt-1);
	}
	return 0;
}



