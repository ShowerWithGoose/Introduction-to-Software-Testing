#include <stdio.h>
#include <string.h>

char s[2000];
int sw2[2000];
int sum;
int main()
{	
	fgets(s,2000,stdin);
	int len=strlen(s);
	int j=0,i=0;
	if(s[i]=='-') {sw2[j]=-2;i++;}
	else sw2[j]=-2;
	int now=0;
	for(;i<len;i++) 
	{
		now=0;
		if(s[i]==' ') continue;
		while(s[i]>='0'&&s[i]<='9') {now=now*10+s[i]-'0';i++;};
		sw2[++j]=now;
		while(s[i]==' ') i++;
		if(s[i]=='=') {sw2[++j]=-1;break;}
		if(s[i]=='+') sw2[++j]=-2;
		if(s[i]=='-') sw2[++j]=-3;
		if(s[i]=='*') sw2[++j]=-4;
		if(s[i]=='/') sw2[++j]=-5;
	}
	//for(int i=1;i<=j;i++) printf("%d ",sw2[i]);
	now=0;
	int be=0;
	for(i=0;i<=j;i++)
	{
		if(sw2[i]<0&&sw2[i]>-4)
		{
			sum+=(((sw2[be]==-3)?-1:1)*now);
			if(sw2[i]==-1) {break;}
			be=i;
			now=sw2[i+1];
			i++;
			//printf("%d %d\n",now,i);
		}
		else 
		{
			if(sw2[i]==-4) now*=sw2[i+1];
			else now/=sw2[i+1];
			i++;
		}
	}
	printf("%d",sum);
	return 0;
}
