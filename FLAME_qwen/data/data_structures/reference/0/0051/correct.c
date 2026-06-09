//1_1
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char s[100005];
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]!='-') printf("%c",s[i]);
		else if((s[i+1]>s[i-1])&&((s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]>='a'&&s[i-1]<='z')||(s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]>='A'&&s[i-1]<='Z')||(s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]>='0'&&s[i-1]<='9')))
		{
			for(int j=1;j<s[i+1]-s[i-1];j++) printf("%c",s[i-1]+j);
		}
		else printf("-");
	}
	return 0;
}

/*int main(int argc, char const *argv[])
{
	int i;
	char c,a;
	do{
		c=getchar();
		if(c=='-')
		{

			char b;
			b=getchar();
			if((a>='a'&&a<='z'&&b>='a'&&b<='z'&&b>a)||(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&b>a)||(a>='0'&&a<='9'&&b>='0'&&b<='9'&&b>a))
				for(i=1;i<b-a;i++) printf("%c",a+i);
			else printf("-");
			printf("%c",b);
			a=b;
		}
		else
		{
			printf("%c",c);
			a=c;
		}
	}while(c!='\n');
	return 0;
}*/
