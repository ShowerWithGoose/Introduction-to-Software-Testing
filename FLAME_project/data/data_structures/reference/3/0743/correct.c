#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define MaxTo(a,b) (a)=(a)>(b)?(a):(b)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define ull unsigned long long
#define FO2(N,M) for(int i=0;i<N;i++)for(int j=0;j<M;j++)
#define swap(type,a,b) {type t=a;a=b;b=t;}
int N,e=-123;
char a[114514];
int main()
{
	scanf("%s",a);
	if(a[0]=='0'){//开始以0为起点的操作
		int i;for(i=2;a[i]=='0';i++);e=-i+1;
		for(int i=strlen(a);a[i]=='0'||a[i]=='\0'||a[i]=='.';i--) a[i]='\0';//除去末尾的0
		printf("%c",a[i]);i++;if(a[i]!='\0')printf(".");
		for(;a[i]!='\0';i++) printf("%c",a[i]);
	}
	else{
		for(int i=0;;i++) if(a[i]=='.'||a[i]=='\0'){e=i-1;break;}//得到小数点
		for(int i=strlen(a);a[i]=='0'||a[i]=='\0'||a[i]=='.';i--) a[i]='\0';//除去末尾的0
		printf("%c",a[0]);
		if(a[1]!='\0') printf(".");
		for(int i=1;a[i]!='\0';i++) if(a[i]!='.') printf("%c",a[i]);
	}
	printf("e%d",e);
	return 0;
}




