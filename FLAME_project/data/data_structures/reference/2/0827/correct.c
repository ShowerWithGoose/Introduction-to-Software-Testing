#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
void squeez(char s[],char c){
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	if(s[i]!=c)
	s[j++]=s[i];
	s[j]='\0';
}
int main(){
	char a[10000]={},c[10000]={};//数组c存运算符号 
	char signal[6]={'+','-','*','/','='};
	char *number;
	int i,j,k,p,q=0,sum=0,b[10000]={};//数组b存数字
	int r[10000]={},R=0;//分别对应连乘、连除的中间量和分别*、/的结果
	gets(a);
	squeez(a,' ');//去空格 
	for(j=k=0;a[j]!='\0';j++)
		if(a[j]=='+'||a[j]=='-'||a[j]=='*'||a[j]=='/'||a[j]=='=')
		c[k++]=a[j];
	    c[k]='\0';//把运算符号分开 
	number=strtok(a,signal);
	while(number!=NULL){
		b[i]=atoi(number);
		number=strtok(NULL,signal);
		i++;
	}//把数分开并将其由字符形式转变为整数形式 
	for(j=0;c[j]!='=';j++){	
		if(c[j]=='-')
		b[j+1]=-b[j+1];
		    }//将减一个正数变成加一个负数 
	for(j=0;c[j]!='=';j++){
		if(c[j]=='*'||c[j]=='/'){
			p=j;
			r[q]=b[p]; 
			b[p]=0;
			while(c[p]=='*'||c[p]=='/'){
				if(c[p]=='*')
				r[q]*=b[p+1];
				if(c[p]=='/')
				r[q]/=b[p+1];
				b[p+1]=0;
				p++;
			}
			j=p-1;
			R+=r[q]; 
			q++;
		}//计算每一步乘除法，并存进r中 
	}
	for(j=0;j<=i;j++){
		sum+=b[j];
	}
	printf("%d",sum+R);
	return 0;
}


