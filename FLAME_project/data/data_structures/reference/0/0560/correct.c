#include <stdio.h>
#include<string.h>
char a[1000];
int main()
{
	gets(a);
	int i,j=1,flag=0,m;
	m=strlen(a);
	for(i=0;i<m;i++)
	{
		printf("%c",a[i]);
		if((a[i+1]=='-')&&((a[i]<='z'&&a[i]>='a'&&a[i+2]<='z'&&a[i+2]>='a')||(a[i]<='Z'&&a[i]>='A'&&a[i+2]<='Z'&&a[i+2]>='A')||(a[i]<='9'&&a[i]>='0'&&a[i+2]<='9'&&a[i+2]>='0'))&&(a[i+2]-a[i]>1))
		{
		    for(j=1;a[i]+j<a[i+2];j++)
			printf("%c",a[i]+j);
			i=i+2;
			flag=1;
		}
		if((a[i+1]=='-')&&((a[i]<='z'&&a[i]>='a'&&a[i+2]<='z'&&a[i+2]>='a')||(a[i]<='Z'&&a[i]>='A'&&a[i+2]<='Z'&&a[i+2]>='A')||(a[i]<='9'&&a[i]>='0'&&a[i+2]<='9'&&a[i+2]>='0'))&&(a[i+2]-a[i]==1))
		{
			i=i+1;
			flag=1;
		}

		if(flag==1)
		i--;
		flag=0;
	}
	return 0;
}

