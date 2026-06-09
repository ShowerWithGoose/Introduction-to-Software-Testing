#include<stdio.h>
#include<math.h>
#include<string.h>
int ans;
int n;
int len;
char s[1000];
char a[1000];
int c[1000];
char d[1000];
int fl[1000];
int k,j;
int main(){
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]!=' '){
			a[len]=s[i];
			len++;
		}
		if(s[i]=='=') break;
	}
	for(int i=0;i<len;i++){
		if('0'<=a[i]&&a[i]<='9'){
			k++;
			c[k]=(int)(a[i]-'0');
			while('0'<=a[i+1]&&a[i+1]<='9'){
				i++;
				c[k]=c[k]*10+(int)(a[i]-'0');
			}
		}
		else{
			j++;
			d[j]=a[i];
		}
		if(i>=len) break;
	}
	for(int i=1;i<=j;i++){
		if(d[i]=='+') fl[i]=1;
		if(d[i]=='-') fl[i]=2;
		if(d[i]=='*') fl[i]=3;
		if(d[i]=='/') fl[i]=4;
		if(d[i]=='=') fl[i]=5;
		if(d[i]==' ') fl[i]=6;
	}
	
	for(int i=1;i<=j-1;i++){
		
			if(fl[i]==3||fl[i]==4){
				if(fl[i]==3) {
					c[i]=c[i]*c[i+1];
					for(int m=i+1;m<=k;m++){
						c[m]=c[m+1];
					}
					k--;
					for(int m=i;m<=j;m++){
						d[m]=d[m+1];
						fl[m]=fl[m+1];
					}
					j--;
					i--;
					
				}
				if(fl[i]==4){
					c[i]=c[i]/c[i+1];
					for(int m=i+1;m<=k;m++){
						c[m]=c[m+1];
					}
					k--;
					for(int m=i;m<=j;m++){
						d[m]=d[m+1];
						fl[m]=fl[m+1];
					}
					j--;
					i--;
					
				} 
			}
			
	}
	for(int i=1;i<=j-1;i++){
			if(fl[i]==1||fl[i]==2){
				if(fl[i]==1) {
					c[i]=c[i]+c[i+1];
					for(int m=i+1;m<=k;m++){
						c[m]=c[m+1];
					}
					k--;
					for(int m=i;m<=j;m++){
						d[m]=d[m+1];
						fl[m]=fl[m+1];
					}
					j--;
					i--;
					
				}
				else{
					c[i]=c[i]-c[i+1];
		
					for(int m=i+1;m<=k;m++){
						c[m]=c[m+1];
					}
					k--;
					for(int m=i;m<=j;m++){
						d[m]=d[m+1];
						fl[m]=fl[m+1];
					}
					j--;
					i--;
					
				} 
			}
			
	}
	printf("%d",c[1]);
	
	return 0;
}


