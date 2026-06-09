#include<stdio.h>
int main()
{
	int s1, s2, s3;
	char f1, f2, f3;
	f1='+';
	s1=0;
	while(f1!='=')
	{
		scanf("%d %c", &s2, &f2);
		while(f2=='*' || f2=='/')
		{
			scanf("%d %c", &s3, &f3);
			if(f2=='*') s2=s2*s3;
			else if(f2=='/') s2=s2/s3;
			f2=f3;
		}
		if(f1=='+') s1+=s2;
		else if(f1=='-') s1-=s2;
		f1=f2;
	}
	printf("%d", s1);
}

