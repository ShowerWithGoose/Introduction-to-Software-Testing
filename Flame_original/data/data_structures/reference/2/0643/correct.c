#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2000
	char s[N],a[N],b[N],c[N]; 
	int d[N],e[N],len,len1,len2,i,j,k,l,sum;
int main(){
	gets(s);
	len1=strlen(s);
	for(i=0,j=0;i<len1;i++){
		if(s[i]!=' '){
			a[j++]=s[i];
		}
	}
	len2=strlen(a);
	for(i=0,j=0,k=0,l=0;i<len2;i++){
		if((a[i]=='+')||(a[i]=='-')||(a[i]=='*')||(a[i]=='/')||(a[i]=='=')){
			b[j++]=a[i];
		}
		if((a[i]>='0')&&(a[i]<='9')){
			for(len=1;len<11;len++){
				if(a[i+len]>=48&&a[i+len]<=57){
					continue;
				}
				int x=1,num=0,p; 
				for(p=len;p>0;p--){
					num+=(a[i+p-1]-'0')*x;
					x*=10;
				}
				d[l++]=num;
				i+=len-1;
				break;
			}
		}
	}
	for(i=0,j=0;i<strlen(b);i++){
		if(b[i]=='+'||b[i]=='-'||b[i]=='='){
			c[j]=b[i];
			e[j]=d[i];
			j++;
		}
		if(b[i]=='*'){
			d[i+1]*=d[i];
		}
		if(b[i]=='/'){
			d[i+1]=d[i]/d[i+1];
		}
	}
	sum=e[0];
	for(i=0;i<strlen(c);i++){
		if(c[i]=='+'){
			sum+=e[i+1];
		}
		if(c[i]=='-'){
			sum-=e[i+1];
		}
	}
	printf("%d",sum);
	return 0;
}

