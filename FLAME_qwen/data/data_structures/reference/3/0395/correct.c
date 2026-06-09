#include <stdio.h>
#include <string.h>
int main()
{
	char s[110]="";
	gets(s);
	int len=strlen(s);
	int i;
	int cnt=0;
	int flag=0;
	for(i=0;i<len;i++)
	{
		if(s[0]=='0')    //首位为0 
		{
			flag=1;
			break;	
		}
		else
		{
			flag=2;
			if(s[i] != '.')
				cnt++;
			if(s[i] == '.')
				break;
		 } 
	}
	if(flag == 1 && s[len-2] != '0' && s[len-2] != '.')        // 首位为0 
	{
		int j;
			for(j=2;j<len;j++)
			{
				if(s[j] != '0')
				{
					
					printf("%c",s[j]);
					printf(".");
					int k;
					for(k=j+1;k<len;k++)
						printf("%c",s[k]);
					printf("e");
					printf("-%d",j-1);
					break;
				}
			}
	}
	else if(flag == 1 && s[len-2] == '0')
	{
		printf("%ce-%d",s[len-1],len-2);
	}
	else if(flag == 1 && s[len-2] == '.')
		printf("%ce-1",s[len-1]);
	else if(flag==2 && len != 1)
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
	else if(flag == 2 && len == 1)
		printf("%ce0",s[0]);
	return 0;
}

