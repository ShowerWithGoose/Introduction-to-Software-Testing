#include <stdio.h> 
char a[105];
int main()
{
	int cnt=0,nota,flag=0;
	int temp=getchar();
	while(temp!='\n')
	{
		a[cnt]=temp;
		if(temp=='.')
		{
			nota=cnt;
			flag=1;
		}	
		cnt++;
		temp=getchar(); 
	}
	int f=2,k;
	if(a[0]=='0')
	{
		while(a[f]=='0')
			f++;
		printf("%c",a[f]);
		if(f+1<cnt)
			printf(".");
		for(k=f+1;k<cnt;k++)
			printf("%c",a[k]);
		printf("e%d",1-f);
	}
	else
	{
		if(flag)
		{
			printf("%c.",a[0]);
			for(k=1;k<cnt;k++)
				if(k!=nota)
					printf("%c",a[k]);
			printf("e%d",nota-1);
		}
		else
		{
			printf("%c",a[0]);
			if(cnt>1)
				printf(".");
			for(k=1;k<cnt;k++)
				printf("%c",a[k]);
			printf("e%d",cnt-1);
		}
	}
	return 0; 
}


