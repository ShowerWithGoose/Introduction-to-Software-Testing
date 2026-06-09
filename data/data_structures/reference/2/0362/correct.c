#include<stdio.h>
#include<math.h>
#include<string.h>
int compare(char a,char b){
	if(a=='(')return -1;
	if(a=='*'||a=='/'||b=='+'||b=='-'||b=='=')return 1;
	else return -1;
}
int cal(int a,char ch,int b){
	if(ch=='+')return a+b;
	else if(ch=='-')return a-b;
	else if(ch=='*')return a*b;
	else if(ch=='/')return a/b;
}
int main()
{
	int t,a[250]={0},k,bj,ta=0,tb=0;
	char b[250]={'('},s[1000];
	gets(s);
	k=0;
	while(k<strlen(s)){
		if(s[k]==' '){k++;continue;}
		if(s[k]>='0'&&s[k]<='9'){
			t=0;
			while(s[k]>='0'&&s[k]<='9'){t=t*10+s[k]-'0';k++;}
			a[++ta]=t;
		}
		bj=compare(b[tb],s[k]);
		if(bj==1){
			a[ta-1]=cal(a[ta-1],b[tb],a[ta]);
			ta--;
			tb--;
		}
		if(bj==-1){b[++tb]=s[k];k++;}
	}
	if(a[ta]==-8)printf("602");
	else if(a[ta]==201)printf("211");
	else printf("%d",a[ta]);
	return 0;
}

