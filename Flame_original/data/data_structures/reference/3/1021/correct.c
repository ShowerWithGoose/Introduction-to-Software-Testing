#include<stdio.h>
#include<string.h>
int main()
{
	int i,len,po=0,k[100],t=0;
	char str1[100],str2[100];
	scanf("%s",str1);
	len=strlen(str1);
	str1[len]='e';
	for(i=0;i<len;i++)
	{
		if(str1[i]=='.')
		po=i;
		else if(str1[i]!='0')
		k[t++]=i;
		else
		continue;
	}
	if(po==1&&str1[0]=='0')
	{
		strcpy(str2,&str1[k[0]+1]);
		if(k[0]==len-1)
		printf("%c%s",str1[k[0]],str2);
		else
		printf("%c.%s",str1[k[0]],str2);
		printf("%d",1-k[0]);
	}
	else if(po==1&&(str1[0]>'0'&&str1[0]<='9'))
	{
		printf("%s0",str1);
	}
	else if(po!=1)
	{
		str2[0]=str1[0];
		str2[1]='.';
		for(i=1;i<len+1;i++)
		{
			if(i>=1&&i<po)
			str2[i+1]=str1[i];
			else if(i>po)
			str2[i]=str1[i];
			else continue;
		}
		str2[i]='\0';
		if(po>0)
		printf("%s%d",str2,po-1);
		else
		printf("%c.%s%d",str2[0],&str2[1],len-1);
	}
	return 0;
}



