#include<stdio.h>
char s[10000];
int a[10000];
int b[10000];
int main(){
	gets(s);
	int j=0;
	//将字符数据化成整数数据并去掉空格 
	for(int i=0; s[i]!='\0'; i++){
		if(s[i]==' ')continue;
		else if('0'<=s[i]&&s[i]<='9'){
			for(; '0'<=s[i]&&s[i]<='9'; i++){
				a[j]=a[j]*10+s[i]-'0';
			}i--;j++;
		}
		else if(s[i]=='+')a[j++]=-1;
		else if(s[i]=='-')a[j++]=-2;
		else if(s[i]=='*')a[j++]=-3;
		else if(s[i]=='/')a[j++]=-4;
		else if(s[i]=='=')a[j++]=-5;
	}
	int k=j;
	j=0;
	//先计算乘除，再计算加减 
	for(int i=0; i<k; i++){
		if(a[i]==-3){
			if(i>=2&&(a[i-2]==-3||a[i-2]==-4))	 b[j-1]*=a[i+1];//连乘或者连除 
			else 	                             b[j-1]=a[i-1]*a[i+1];
			i++;
		}
		else if(a[i]==-4) {
			if(i>=2&&(a[i-2]==-3||a[i-2]==-4))	 b[j-1]/=a[i+1];//连乘或者连除 
			else 	                             b[j-1]=a[i-1]/a[i+1];
			i++;
		}
		else b[j++]=a[i];
	}int ans=b[0];
	for(int i=1; b[i]!=-5; i++){
		if(b[i]==-1)       ans+=b[i+1];
		else if(b[i]==-2)  ans-=b[i+1];
	}
	printf("%d",ans);
}

