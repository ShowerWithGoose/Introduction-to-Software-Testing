#include<stdio.h>
#include<string.h>
char s[10000]={0};
char t[10000]={0};
int position[10000]={0};
int tmp[10000]={0};
int main()
{
	int i=0,j=0,k=0,flag=0,len;
	gets(s); 
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		t[i]=s[i];
	}
	for(i=0;i<len;i++)
	{
		if((s[i]=='-')&&(s[i+1]>s[i-1])&&(((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]<='z'&&s[i+1]>='a'))||((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]<='Z'&&s[i+1]>='A'))||((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]<='9'&&s[i+1]>='0'))))
        {
			position[j]=i;
			j++;
		}
	}
	for(j=0;position[j]!=0;j++)
	{
		tmp[j]=s[position[j]+1]-s[position[j]-1];
	}
	for(j=0;position[j]!=0;j++)
	{
		if(j>=1)
		{
			position[j]+=(tmp[j-1]-2);
		}
		for(i=position[j]+tmp[j]-1;i<len+tmp[j]-2;i++)
		{
			s[i]=t[i-tmp[j]+2];
		}
		for(i=position[j],k=1;i<position[j]+tmp[j]-1;i++,k++)
		{
			s[i]=t[position[j]-1]+k;
		}
		flag++;
		len+=tmp[j];
		len-=2;
		for(i=0;i<len;i++)
		{
			t[i]=s[i];
		}
	}
	if(0==flag)
	{
		for(i=0;i<strlen(s);i++)
		{
			printf("%c",s[i]);
		}
	}
	else
	{
	    for(i=0;i<len;i++)
	    {
		    printf("%c",s[i]);
	    }
	}
	return 0;
}


