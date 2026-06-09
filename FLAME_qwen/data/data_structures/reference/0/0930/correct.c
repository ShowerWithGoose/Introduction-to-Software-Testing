#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char ch[1000],ans[1000];
int main()
{
	int i,j=1,k,t;
	scanf("%s",ch);
	ans[0]=ch[0]; 
	for(i=1;ch[i+1]!='\0';i++)
	{
		k=0;
		if(ch[i]=='-'&&ch[i-1]>='0'&&(ch[i+1]-ch[i-1]>1)&&ch[i+1]<='9')
		{
			k=ch[i+1]-ch[i-1];
			for(t=1;t<k;t++)
			{
				ans[j++]=ch[i-1]+t;
			}
		}
		else if(ch[i]=='-'&&ch[i-1]>='a'&&(ch[i+1]-ch[i-1]>1)&&ch[i+1]<='z')
		{
			k=ch[i+1]-ch[i-1];
			for(t=1;t<k;t++)
			{
				ans[j++]=ch[i-1]+t;
			}
		}
		else if(ch[i]=='-'&&ch[i-1]>='A'&&(ch[i+1]-ch[i-1]>1)&&ch[i+1]<='Z')
		{
			k=ch[i+1]-ch[i-1];
			for(t=1;t<k;t++)
			{
				ans[j++]=ch[i-1]+t;
			}
		}
		else
		    ans[j++]=ch[i];
	ans[j]=ch[i+1];
	}
	printf("%s",ans);
	return 0;
}



