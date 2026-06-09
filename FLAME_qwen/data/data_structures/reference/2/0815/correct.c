#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h> 
int main(){
	char a[100],c[100];
	int i,j=0,l,b[100]={0},m=0,n,tmp,res=0,q=0;
	gets(a);
	l=strlen(a);
	for(i=0;i<l-1;i++){
		while(a[i]>='0'&&a[i]<='9'||a[i]==' '){//可能会有两位数的情况 
			if(a[i]==' ')
				i++;
			else{
				b[j]=b[j]*10+a[i]-'0';
				i++;				
			}
		}
		j++;	
	}	
	for(i=0;i<l;i++)//存符号 
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
			c[m]=a[i];
			m++;			
		}
	for(n=0;n<m;n++){
		if(c[n]=='*'){//两个积数都变成结果，后面会跳过一个 
			tmp=b[n]*b[n+1];
			b[n]=tmp;
			b[n+1]=tmp;			
		}
		else if(c[n]=='/'&&b[n+1]!='0'){//除数和被除数都变成商 
			tmp=b[n]/b[n+1];
			b[n]=tmp;
			b[n+1]=tmp;									
		}		
	}
	for(i=m;i>0;i--){
		if(c[i]=='*'&&c[i-1]=='*'|| c[i]=='/'&&c[i-1]=='/' || c[i]=='*'&&c[i-1]=='/' || c[i]=='/'&&c[i-1]=='*')
			b[i-1]=b[i];
	} 
	res=b[0];
	for(i=0;i<m;i++){//把*、/跳过 
		if(c[i]=='+')
			res+=b[i+1];
		else if(c[i]=='-')
			res-=b[i+1];			
	}
	printf("%d",res);
	return 0;
} 

