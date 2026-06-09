#include<stdio.h>
#include<string.h>
int main()
{
	int i,len,poi,step;
	char ch[101];
	memset(ch,0,sizeof(ch));
	gets(ch+1);
	//printf("%d",strlen(ch+1));
	len=strlen(ch+1);
	for(i=1;i<=len;i=i+1)
	{
		if(ch[i]=='.') break;
	} 
	poi=i;
	if(poi==2&&ch[1]!='0') printf("%se0",ch+1);
	else if(poi==2&&ch[1]=='0')
	{
		for(i=3;i<=len;i=i+1)
		{
			if(ch[i]!='0') break;
		}
		step=2-i;
		if(step!=-1) printf("%c.%se%d",ch[i],ch+i+1,step);
		else printf("%c%se%d",ch[i],ch+i+1,step);
	}
	else if(poi!=2)
	{
	    step=poi-2;
	    for(i=1;i<=len;i=i+1)
	    {
			if(ch[i]!='.') printf("%c",ch[i]);
			if(i==1) printf(".");
		}
		printf("e%d",step);
	}
	return 0;
}



