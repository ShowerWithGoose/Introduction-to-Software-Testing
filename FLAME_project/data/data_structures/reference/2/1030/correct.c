#include<stdio.h>
int zhuanhuan(int m,char s[]){
	int zhi=0;
	int beishu=1;
	for(int i=0;i<m;i++){
		zhi=zhi+(s[i]-'0')*beishu;
		beishu=beishu*10;
	}
	return zhi;
}
int yunsuan(int a,char b,int c){
	if(b=='+'){
		return a+c;
	}
	if(b=='-'){
		return a-c;
	}
	if(b=='*'){
		return a*c;
	}
	if(b=='/'){
		return a/c;
	}
}
void shanchu(int i,char a[]){
	for(;a[i]!='\0';i++){
		a[i]=a[i+1];
	}
}
int main()
{
	char s[100];//原输入 
	char m[100]={'\0'};
	int a[100]={0};
	char n[100]={'\0'};
	char fuhao[100]={'\0'};
	int xiansuan[100]={0};
	int housuan[100]={0};
	int ans=0;//答案 
	int shu=0;//参与计算的数字个数
	int temp1=0;
	int temp2=0;
	int two=0;//加减个数 
	int one=0;//乘除个数
	int j;
	int l;
	int i;
	int k;
	gets(s);//输入 
	for(int i=0,j=0;s[i]!='\0';i++){//去掉空格 √ 
		if(s[i]!=' '){
			m[j]=s[i];
			j++;
		}
	}
	for(int i=0;m[i]!='\0';i++){
		if(m[i]=='*'||m[i]=='/'){//统计乘除个数 √ 
			one++;
		}
		else if(m[i]=='+'||m[i]=='-'){//统计加减个数 √ 
			two++;
		}
	}
	for(i=0;m[i]!='\0';i++){
		if(m[i]=='-'||m[i]=='+'||m[i]=='*'||m[i]=='/'||m[i]=='='){
			l=0;
			for(j=i-1;m[j]!='-'&&m[j]!='+'&&m[j]!='*'&&m[j]!='/'&&m[j]!='='&&j>=0;j--){
				n[l]=m[j];
				l++;
			}
			k=zhuanhuan(l,n);
			a[shu]=k;
			shu++;
		}
	}
	for(i=0,j=0;m[i]!='\0';i++){
		if(m[i]=='-'||m[i]=='+'||m[i]=='*'||m[i]=='/'){
			fuhao[j]=m[i];
			j++;
		}
	}
	while(one){	
		for(i=temp1;fuhao[i]!='\0';i++){
			if(fuhao[i]=='*'||fuhao[i]=='/'){
				a[i]=yunsuan(a[i],fuhao[i],a[i+1]);
				shanchu(i,fuhao);
				for(j=i;j<shu;j++){
					a[j+1]=a[j+2];
				}
				shu--;
				one--;
				temp1=i;
				break;
			}
		}
	}
	if(two==0){
		printf("%d",a[0]);
	}
	else{
		for(i=0;fuhao[i]!='\0';i++){
			a[i+1]=yunsuan(a[i],fuhao[i],a[i+1]);
			ans=a[i+1];
		}
		printf("%d",ans);
	}
}

