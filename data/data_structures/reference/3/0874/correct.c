#include<stdio.h>
#include<string.h>
#include<math.h>
char s[103];
int pt=0,len; 
int main()
{
	scanf("%s",s);len=strlen(s);
	for(int i=0;i<len;i++)if(s[i]=='.'){pt=i;break;}
	if(!pt)
	{
		int ps=len-1,i;
		while(s[ps]=='0')ps--;
		if(ps==-1){printf("0");return 0;}
		printf("%c",s[0]);if(ps)printf(".");
		for(i=1;i<=ps;i++)printf("%c",s[i]);
		printf("e%d",len-1);
	}
	else 
	{
		if(pt==1)
		{
			if(s[0]=='0')
			{
				int ps=2,i;while(s[ps]=='0'&&ps<=len-1)ps++;
				printf("%c",s[ps]);
				if(ps!=len-1)printf(".");
				for(i=ps+1;i<=len-1;i++)printf("%c",s[i]);
				printf("e-%d",ps-1);
			}
			else printf("%se0",s);
		}
		else
		{
			int i;
			printf("%c",s[0]);printf(".");
			for(i=1;i<len;i++){if(s[i]=='.')continue;printf("%c",s[i]);}
			printf("e%d",pt-1);
		}
	}
	return 0;
}

