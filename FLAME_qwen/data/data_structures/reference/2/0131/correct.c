#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int main()
{
char s[300];
long long a,b,c;
char x,y,z;
a=0;
x='+';
while(x!='='){
	scanf("%lld %c",&b,&y);
	while(y=='*'||y=='/'){
		scanf("%lld %c",&c,&z);
		if(y=='*')
		b=b*c;
		else if(y=='/'){
			b=b/c;
		}
		y=z;
	}
	if(x=='+')
	a=a+b;
	else if(x=='-'){
	a=a-b;
	}
	x=y;
}	
printf("%lld",a);
return 0;
}

