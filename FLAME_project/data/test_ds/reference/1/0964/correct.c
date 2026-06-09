/*#include<stdio.h>
#include<string.h>

long func(int x)
{
switch(x)
{
	case 0:return 0;
	case 1:
	case 2:return 1;
}
return(func(x-1)+func(x-2));
}
int main()
{
int x=6;
printf("%lld\n",func(x));
	return 0;
}*/
#include<stdio.h>
#include<string.h>
int main()
{
	char s[999999],ans[999999];
	scanf("%s",s);
	ans[0]=s[0];
	int i=1,j=1,len,k,m;
	len=strlen(s)-1;
	for(i=1;i<=len-1;i++)
	{
		if(s[i]!='-'){
			ans[j]=s[i];
			j++;
		}
		else
		{
			if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1];
				for(m=1;m<k;m++){
					ans[j]=s[i-1]+m;
					j++;
				}
				continue;
			}
			if((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z')&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1];
				for(m=1;m<k;m++){
					ans[j]=s[i-1]+m;
					j++;
				}
				continue;

			}
			if((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z')&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1];
				for(m=1;m<k;m++){
					ans[j]=s[i-1]+m;
					j++;
				}
				continue;
			}
			else
			{
				ans[j]='-';
				j++;
			}
		}
	}
	ans[j]=s[i];
		printf("%s",ans);
	return 0;
}



