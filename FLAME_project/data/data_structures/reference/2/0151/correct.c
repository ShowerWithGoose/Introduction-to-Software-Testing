#include<stdio.h>
#include<math.h>
#include<string.h>
int numreader ();
char chreader ();
int cal(int,int,char);
int judge (char,char);

int main () {
	int fro,mid,beh;
	char c1,c2;

	fro=numreader();
	c1=chreader();
	if(c1=='=') {
		printf("%d",fro);
		return 0;
	}

	mid=numreader();
	c2=chreader();
	if(c2=='=') {
		printf("%d",cal(fro,mid,c2));
		return 0;
	}

	beh=numreader();

	while(1) {
		if(judge(c1,c2)==0) {
			fro=cal(fro,mid,c1);
			c1=c2;
			mid=beh;
			c2=chreader();
			if(c2=='=') {
				printf("%d",cal(fro,mid,c1));
				return 0;
			}
			beh=numreader();
			continue;
		}
		else {
			mid=cal(mid,beh,c2);
			c2=chreader();
			if(c2=='=') {
				printf("%d",cal(fro,mid,c1));
				return 0;
			}
			beh=numreader();
		}
	}
















	return 0;
}

int numreader () {
	int n;
	scanf("%d",&n);
	return n;
}

char chreader () {
	char m;
	scanf("%c",&m);
	if(m==' ') {
		return chreader ();
	}
	else
	return m;
}

int cal (int a,int b,char c) {
	switch (c) {
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;

	}
}

int judge (char x,char y) {
	if((x=='+'||x=='-')&&(y=='*'||y=='/')) return 1;
	else return 0;


}





















