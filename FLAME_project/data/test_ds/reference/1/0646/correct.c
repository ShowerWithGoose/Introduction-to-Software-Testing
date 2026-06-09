#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[1000];
char ans[1000];
int main()
{
	int i=0,j=0;
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
	{
		int flag=0;
		if(a[i+1]=='-')
		{
			if(islower(a[i])&&islower(a[i+2])&&a[i]<a[i+2])
			{
				flag=1;
				for(char t=a[i];t<a[i+2];t++)
				{
					ans[j++]=t;
				}
			}else if(isupper(a[i])&&isupper(a[i+2])&&a[i]<a[i+2])
			{
				flag=1;
				for(char t=a[i];t<a[i+2];t++)
				{
					ans[j++]=t;
				}
			}else if(isdigit(a[i])&&isdigit(a[i+2])&&a[i]<a[i+2])
			{
				flag=1;
				for(char t=a[i];t<a[i+2];t++)
				{
					ans[j++]=t;
				}
			}
			if(flag)i++;
		}
		if(!flag){
			ans[j++]=a[i];
		}
	}
	printf("%s",ans);
}

