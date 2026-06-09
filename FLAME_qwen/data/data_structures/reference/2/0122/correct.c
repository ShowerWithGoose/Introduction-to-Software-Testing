#include<stdio.h>
#include<string.h>
int main(){
	int r=0,a1,a2;
	char c='+',c1,c2;
	while(c!='='){
		scanf("%d %c",&a1,&c1);
		while(c1=='*'||c1=='/'){
			scanf("%d %c",&a2,&c2);
			if(c1=='*')
			a1*=a2 ;
			if(c1=='/')
			a1/=a2;
			c1=c2;
		}
		if(c=='-')
		r-=a1;
		if(c=='+')
		r+=a1;
		if(c1=='=')
		break;
		c=c1;
	}
	printf("%d",r);
	
}



