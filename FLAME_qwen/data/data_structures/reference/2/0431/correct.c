#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int c[10000];
int main(){
	char s[10000],a[10000],b[10000];
	gets(s);
	int i=0,j=0,k=0,sum=0,len;
	len=strlen(s);
	for(;i<len;i++){
		if(s[i]!=' '){
			a[j]=s[i];
			j++;
		}
	}
	for(i=0,j=0;a[i]!='=';i++){
		if(a[i]<='9'&&a[i]>='0'){
			c[j]*=10;
			c[j]+=a[i]-'0';
		}
		else{
			j++;
			b[k]=a[i];
			k++;
		}
	}
	b[k]='=';
	for(i=0;b[i]!='=';i++){
		if(b[i]=='*'){
				c[i+1]=c[i]*c[i+1];
				c[i]=0;
				if(i==0) b[i]='+';
				else b[i]=b[i-1];
			}
		if(b[i]=='/'){
				c[i+1]=c[i]/c[i+1];
				c[i]=0;
				if(i==0) b[i]='+';
				else b[i]=b[i-1];
			}
		else continue;
	}
	sum=c[0];
	for(i=0,j=1;b[i]!='\0';i++){
		if(b[i]=='+'){
				sum+=c[j];
				j++;
		}
		if(b[i]=='-'){
				sum-=c[j];
				j++;
		}		
		else continue;
	}
	printf("%d",sum);
	return 0;
} 

