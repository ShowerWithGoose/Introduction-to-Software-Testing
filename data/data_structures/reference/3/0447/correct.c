#include<stdio.h>
#include<string.h>
int main()
{
	char s[200];
	int len1=0,len2=0,i=0,k=0,t=0,flag=0;//len1=小数点前长度   len2=小数点后长度 
	gets(s);
	for(i=0;s[i]!='.'&&s[i]!='\0';i++)
		len1++;
	for(;s[i]!='\0';i++)
		len2++;
	len2--;
	if(len1==1)
	{
		if(s[0]=='0')
		{
			for(i=2;s[i]=='0';i++)
			k++;//flag=0表示0.0002或0.0000263类型,从s[k+2]开始输出 ,e后数字为k+1 ,k记录了小数点后前导0的个数 
			for(;s[i]!='\0';i++)
			t++;//t>1时，是0.0000263类型， 需要先输出s[k+2].,再输出%s,s+k+3,输出e + k+1 
		}
		else
		{
			flag=1;//flag=1表示5.23646665类型 ,直接输出原字符串+ e + 0
		}
	}
	else if(len1==strlen(s))
		flag=3;//flag=3表示整数 
	else 
	{
		flag=2;//flag=2表示256.23622154类型 ，先输出s[0]再输出.在输出后面的字符，e后数字为 len1-1
	}
	
	
	
	if(flag==0)
	{
		if(t>1)
		{
			printf("%c.",s[k+2]);
			for(i=k+3;s[i]!='\0';i++)
			if(s[i]!='.')
			printf("%c",s[i]);
			printf("e-%d",k+1);
		}
		else{
		printf("%s",s+k+2);
		printf("e-%d",k+1);}
	}
	else if(flag==1)
	{
		printf("%s",s);
		printf("e0");
	}
	else if(flag==2)
	{
		printf("%c.",s[0]);
		for(i=1;s[i]!='\0';i++)
		if(s[i]!='.')
		printf("%c",s[i]);
		printf("e%d",len1-1);
	}
	else if(flag==3)
	{
		printf("%c.",s[0]);
		for(i=1;s[i]!='\0';i++)
		if(s[i]!='.')
		printf("%c",s[i]); 
		printf("e%d",strlen(s)-1);
	}
	return 0;
}

