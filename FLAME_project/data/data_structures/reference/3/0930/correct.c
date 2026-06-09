#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char ch[105];
int main()
{
	int a[105],b[105],a_,b_[105],i,count=0,temp;
	scanf("%s",ch);
	int len=strlen(ch);
	if(ch[0]!='0')
	{
		for(i=0;i<len;i++){
		if(ch[i]!='.')
		a[i]=ch[i]-'0';
		else
		{
			count=i;
			break;
		}
	}
	a_=a[0];
	for(i=count+1;i<len;i++){
		b[i]=ch[i]-'0';
	}	
	printf("%d.",a_);
	for(i=1;i<count;i++)
	printf("%d",a[i]);
	for(i=count+1;i<len;i++)
	printf("%d",b[i]);
	printf("e%d\n",count-1);
	}
	else
	{
		for(i=2;i<len;i++)
		{
			if(ch[i]=='0')
			count++;
			else
			{
				a_=ch[i]-'0';
				temp=i;
				break;
			}	
		}
		for(i=temp+1;i<len;i++){
		b[i]=ch[i]-'0';
	}	
	printf("%d",a_);
	if(len-count-4>=0)
	printf(".");
	for(i=temp+1;i<len;i++)
	printf("%d",b[i]);
	printf("e-%d\n",count+1);
	}
	return 0;
}

