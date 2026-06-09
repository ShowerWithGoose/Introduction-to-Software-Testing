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
int N;
char Input[200000],Output[400000];
int OT=0;//输出字符串的内容
int Cate(char x){//0数字，1大写字母，2小写字母
	if(x>='0'&&x<='9') return 0;
	if(x>='A'&&x<='Z') return 1;
	if(x>='a'&&x<='z') return 2;
	return -1;//程序出现问题，读入未知字符
}
void Expand(char Start,char End){
	if(Cate(Start)==Cate(End)&&Start<End){
		for(char i=Start+1;i<End;i++) Output[OT++]=i;
	}
	else Output[OT++]='-';
}
int main()
{
	scanf("%s",Input);
	for(int i=0;Input[i]!='\0';i++){
		if(Input[i]=='-') Expand(Input[i-1],Input[i+1]);
		else Output[OT++]=Input[i];
	}
	printf("%s",Output);
	return 0;
}


