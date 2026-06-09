#include<stdio.h>

int main()
{
	char w,a,b;
	int ok=0;
	while(scanf("%c",&w)!=EOF)
	{
		a=b;b=w;
		if(w!='-') printf("%c",w);
		else
		{
			char c;
			int at=0,ct=0;
			scanf("%c",&c);
			if(a>='0'&&a<='9') at=1;
			if(c>='0'&&c<='9') ct=1;
			if(a>='a'&&a<='z') at=2;
			if(c>='a'&&c<='z') ct=2;
			if(a>='A'&&a<='Z') at=3;
			if(c>='A'&&c<='Z') ct=3;
			if(c>a && at==ct)
			{
				char x=a+1;
				for(;x<=c;x++) printf("%c",x);
			}
			else	printf("-%c",c);
			a=b;b=c;
		}
	}
	return 0;
}

