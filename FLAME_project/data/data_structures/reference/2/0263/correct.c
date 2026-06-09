#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(){
char str[1000],s[1000];
int a=0,b=0,c=0,d=0,i=0,n=0,k=0,r;
gets(str);
n=strlen(str);
str[n+1]='\0';
for(i=0;i<n+1;i++)//去空格 
	if(str[i]!=' '){
		s[k]=str[i];
		k++;
	}
n=k;//总长度n	
k=0;
for(i=0;i<n;i++){//计算符号个数 
	if(s[i]=='+')
	a++;
	else if(s[i]=='-')
	b++;
	else if(s[i]=='*')
	c++;
	else if(s[i]=='/')
	d++;
}

int position[100]={0},j=1;//j=符号数 
for(i=0;i<n;i++){//记符号位置 
	if(s[i]>'9'||s[i]<'0'){
		position[j]=i;
		j++;
	}
}
j=j-1;//去掉等于号

if(a==0&&b==0&&c==0&&d==0){//只输入数字则输出结束
for(i=0;i<n-2;i++)
printf("%c",s[i]);
return 0;} 

int shu[1000]={0},num[1000]={0},p=1;//shu=临时数字数组，num=数字数组 
for(r=0;r<position[1];r++){
	shu[p]=shu[p-1]*10+s[r]-'0';//解决两位数问题 
	p++;
} 
num[1]=shu[p-1]; //把shu数字给num

for(i=0;i<=p;i++)
	shu[i]=0;
p=1; //初始化shu和p 

int q;
for(q=2;q<j;q++){
	for(r=position[q-1]+1;r<position[q];r++){
		shu[p]=shu[p-1]*10+s[r]-'0';//两位数
		p++;
	}
	num[q]=shu[p-1];//shu赋给num
	for(i=0;i<=p;i++)
	shu[i]=0;
	p=1;//初始化shu和p
}

int u,pos;
for(u=1;u<j;u++){//开始计算过程 
	pos=position[u];
	if(s[pos]=='*'){//先判断乘法 
		num[u]*=num[u+1];
		position[u]=position[u+1];
		for(i=u+1;i<j;i++){
			num[i]=num[i+1];
			position[i]=position[i+1];
		}
		u--;
		j--;
	}
	else if(s[pos]=='/'){//同步判断除法 
		num[u]/=num[u+1];
		position[u]=position[u+1];
		for(i=u+1;i<j;i++){
			num[i]=num[i+1];
			position[i]=position[i+1];
		}
		u--;
		j--;
	}
}

for(u=1;u<j;u++){
	pos=position[u];
	if(s[pos]=='+')
	num[1]+=num[u+1];
	else if(s[pos]=='-')
	num[1]-=num[u+1];
}

printf("%d",num[1]);
return 0; 
}

