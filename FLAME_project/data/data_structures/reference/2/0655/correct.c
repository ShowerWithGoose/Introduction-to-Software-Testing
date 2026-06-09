#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))
int main(){
	int i,j,k,z=0,len,u=0,b=0,t;
	char s[1005];
	long long  n[1001]={0},m[1001]={0},c;
	gets(s);
	len=strlen (s);
	memset(m,-1,sizeof(m));
	for(i=0,j=0;i<len;i++){
		if(s[i]==' ') continue;
		s[j++]=s[i];
	}
	s[j]='\0';
	len=strlen (s);
	for(i=0,j=0;i<len;i++){//读取每一个数字 
		if(s[i]>='0'&&s[i]<='9'){
			n[j]=10*n[j]+s[i]-'0';
		}
		else j++;
	} if(s[0]=='-'){
		u=-1;
		n[0]=-n[0];
	} 
	for(i=0,j++,t=u;i<len;i++){//进行 乘法 和 除法 
		if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
			t++;//记录是第几个符号，后对 n[t-1] 和 n[t] 进行计算 
			if(s[i]=='*'){
				k=t-1;
				while(m[k]!=-1) k=m[k];
				c=n[k]*n[t];
				m[t]=t-1;
				k=t;
				do{
					n[k]=c;
					k=m[k];
				}while(k!=-1);
			}
			else if(s[i]=='/'){
				k=t-1;
				while(m[k]!=-1) k=m[k];
				c=n[k]/n[t];
				m[t]=t-1;
				k=t;
				do{
					n[k]=c;
					k=m[k];
				}while(k!=-1);
			}
		}
	}
	for(i=0,j++,t=u;i<len;i++){
		if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
			t++;
			if(s[i]=='+'){
				k=t-1;
				while(m[k]!=-1) k=m[k];
				c=n[k]+n[t];
				m[t]=t-1;
				k=t;
				do{
					n[k]=c;
					k=m[k];
				}while(k!=-1);
			}
			else if(s[i]=='-'){
				k=t-1;
				while(m[k]!=-1) k=m[k];
				c=n[k]-n[t];
				m[t]=t-1;
				k=t;
				do{
					n[k]=c;
					k=m[k];
				}while(k!=-1);
			}
		}
	}
	printf("%lld",n[0]);
	getchar();getchar();
    return 0;
}


