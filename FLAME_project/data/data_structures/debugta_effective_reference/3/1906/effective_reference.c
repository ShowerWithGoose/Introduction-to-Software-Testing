#include <stdio.h>

char a[200];

int n, N, N, i;


int main()
{
	gets (a);
	
	for(n=0;n<=100;n++)
	{
		if((int)a[n] == 46)
		{
			N=n;
			break;
		}
	}
	
	for(n=0;n<=100;n++)
	{
		if((int)a[n] == '\0')
		{
			N=n;
			break;
		}
	}
	//printf("%d",I);
	if(a[N-1] != '0'){
		if(N == 1)
		{
		for(n=0;n<N;n++)
		printf("%c", a[n]);
		printf("e0");	
		}
		else
		{
		printf("%c.",a[0]);
		for(n=1;n<N;n++){
		printf("%c", a[n]);
		}
		for(n=N+1;n<N;n++){
		printf("%c", a[n]);
		}
		printf("e%d", N-1);
		}
	}
	else{
	for(n=2;n<N;n++)
	{
		if(a[n] != '0')
		{
			i=n;
			break;
		}
	}

		if(N-1 != i){
		printf("%c.", a[i]);
		for(n=i+1;n<N;n++)
		{
			printf("%c", a[n]);
		}
		printf("e-%d", i-1);
		}
		else
		{
		printf("%c",a[i]);
		printf("e-%d", i-1);
		}
	}
	
	return 0;
} 

