#include<stdio.h>
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#define ll long long
#define eps 1e-6
#define MAX 1000005
int fu1[105];
int fu2[105];
int num[105];
int num2[105];
void space(char s[]){
	int i,j;
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]!=' '){
			s[j++]=s[i];
		}
	}
	s[j]='\0';
}
int suan(char *p){
	int i=0,cnt2=0,ret=0,len2=strlen(p);
	char*ps[105];
	ps[0]=&p[0];
	for(i=0;i<len2;i++){
		if(p[i]=='*'){
			fu2[cnt2++]=3;
			p[i]='\0';
			ps[cnt2]=&p[i+1];
		}
		else if(p[i]=='/'){
			fu2[cnt2++]=4;
			p[i]='\0';
			ps[cnt2]=&p[i+1];
		}
	}
	if(cnt2==0) ret=atoi(p);
	else {
		for(i=0;i<=cnt2;i++){
			num2[i]=atoi(ps[i]);
		}
		ret=num2[0];
		for(i=0;i<cnt2;i++){
			if(fu2[i]==3) ret*=num2[i+1];
			else if(fu2[i]==4) ret/=num2[i+1];
		}
	}
	return ret;
}
int main(){
	char s[1005];
	gets(s); 
	int i,j=0;
	space(s);
	char*pt[105];
	pt[0]=&s[0];
	int cnt=0,len=strlen(s);
	for(i=0;s[i]!='=';i++){
		if(s[i]>='0'&&s[i]<='9'||s[i]=='*'||s[i]=='/') continue;
		else if(s[i]=='+') {
			fu1[cnt++]=1;
			s[i]='\0';
			pt[cnt]=&s[i+1];
		}
		else if(s[i]=='-'){
			fu1[cnt++]=-1;
			s[i]='\0';
			pt[cnt]=&s[i+1];
		}
	}
	 s[i]='\0';
	if(cnt==0){
		printf("%d",suan(pt[0]));
		return 0;
	}
	for(i=0;i<=cnt;i++){
		num[i]=suan(pt[i]);
	}
	int ret2=num[0];
	for(i=0;i<cnt;i++){
		if(fu1[i]==-1) ret2-=num[i+1];
		else if(fu1[i]==1) ret2+=num[i+1];
	}
	printf("%d",ret2);
	return 0;
}


