#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int x,y,z;
char a,b,c;
int main()
{
	a='+';
	while(a!='='){
		scanf("%d %c",&y,&b);
		while(b=='*'||b=='/'){
			scanf("%d %c",&z,&c);
			if(b=='*')	y*=z;
			else if(b=='/')	y/=z;
			b=c;
		}
		if(a=='+')	x+=y;
		else if(a=='-')	x-=y;
		a=b;
	}
	printf("%d\n",x);
	return 0;
}

