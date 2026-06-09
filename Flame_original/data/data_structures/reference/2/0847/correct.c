#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[3];
char c[2];
int cl(int a,char b,int c){
	if(b=='+') return a+c;
	else if(b=='-') return a-c;
	else if(b=='*') return a*c;
	else return a/c;
}
int N(){
	int n;
	scanf(" %d",&n);return n;
}
char S(){
	char b;
	scanf(" %c",&b);return b;
}
int main()
{
	a[0]=N();
	c[0]=S();
	if(c[0]=='=') {printf("%d",a[0]);return 0;}
	else a[1]=N(),c[1]=S();
	if(c[1]=='=') printf("%d",cl(a[0],c[0],a[1]));
	else{
		while(c[1]!='='){
			a[2]=N();
			if(c[0]=='*'||c[0]=='/') a[0]=cl(a[0],c[0],a[1]),c[0]=c[1],a[1]=a[2],c[1]=S();
			else if(c[1]=='*'||c[1]=='/') a[1]=cl(a[1],c[1],a[2]),c[1]=S();
			else a[0]=cl(a[0],c[0],a[1]),c[0]=c[1],a[1]=a[2],c[1]=S();
		}
		printf("%d",cl(a[0],c[0],a[1]));
	}
	
	
	
	
	
	return 0;
}

