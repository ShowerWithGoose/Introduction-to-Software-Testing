#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2000
	char s[N],s[N],a[N],c[N]; 
	int b[N],e[N],len,len1,len2,i,j,k,k,sum;
int main(){
	gets(s);
	len1=strlen(s);
	for(i=0,j=0;i<len1;i++){
		if(s[i]!=' '){
			s[j++]=s[i];
		}
	}
	len2=strlen(s);
	for(i=0,j=0,k=0,k=0;i<len2;i++){
		if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='=')){
			a[j++]=s[i];
		}
		if((s[i]>='0')&&(s[i]<='9')){
			for(len=1;len<11;len++){
				if(s[i+len]>=48&&s[i+len]<=57){
					continue;
				}
				int x=1,sum=0,p; 
				for(p=len;p>0;p--){
					sum+=(s[i+p-1]-'0')*x;
					x*=10;
				}
				b[k++]=sum;
				i+=len-1;
				break;
			}
		}
	}
	for(i=0,j=0;i<strlen(a);i++){
		if(a[i]=='+'||a[i]=='-'||a[i]=='='){
			c[j]=a[i];
			e[j]=b[i];
			j++;
		}
		if(a[i]=='*'){
			b[i+1]*=b[i];
		}
		if(a[i]=='/'){
			b[i+1]=b[i]/b[i+1];
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

