#include <stdio.h>
#include <string.h>
int main()
{
	char s[110]="";
	gets(s);
	int len=strlen(s);
	int i;
	int cnt=0;
	int cnt_2=0;
	for(i=0;i<len;i++)
	{
		if(s[0]=='0')    //首位为0 
		{
			cnt_2=1;
			break;	
		}
		else
		{
			cnt_2=2;
			if(s[i] != '.')
				cnt++;
			if(s[i] == '.')
				break;
		 } 
	}
	if(cnt_2 == 1 && s[len-2] != '0' && s[len-2] != '.')        // 首位为0 
	{
		int i;
			for(i=2;i<len;i++)
			{
				if(s[i] != '0')
				{
					
					printf("%c",s[i]);
					printf(".");
					int k;
					for(k=i+1;k<len;k++)
						printf("%c",s[k]);
					printf("e");
					printf("-%d",i-1);
					break;
				}
			}
	}
	else if(cnt_2 == 1 && s[len-2] == '0')
	{
		printf("%ce-%d",s[len-1],len-2);
	}
	else if(cnt_2 == 1 && s[len-2] == '.')
		printf("%ce-1",s[len-1]);
	else if(cnt_2==2 && len != 1)
	{
		printf("%c",s[0]);
		printf(".");
		int l;
		for(l=1;l<cnt;l++)
			printf("%c",s[l]);
		int p;
		for(p=cnt+1;p<len;p++)
			printf("%c",s[p]);
		printf("e");
		printf("%d",cnt-1);
	}
	else if(cnt_2 == 2 && len == 1)
		printf("%ce0",s[0]);
	return 0;
}

