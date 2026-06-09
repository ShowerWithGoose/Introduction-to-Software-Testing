#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(){
	char a[1005];
	int b[1005]={0},j=-1,k=-1;
	gets(a);
	long long c[1005]={0},m=0;
	for(int i=0;i<=strlen(a)-1;i++){
		if(a[i]==' '){
			
		}
		else if(a[i]>='0'&&a[i]<='9'){
			j++;
			for(;a[i]>='0'&&a[i]<='9';i++){
				c[j]=c[j]*10+a[i]-'0';
			}
			i--;
		}
		else if(a[i]=='+'){
			k++;
			b[k]=1;
		}
		else if(a[i]=='-'){
			k++;
			b[k]=-1;
		}
		else if(a[i]=='*'){
			i++;
			for(;a[i]==' ';){
				i++;
			}
			for(;a[i]>='0'&&a[i]<='9';i++){
				m=m*10+a[i]-'0';
			}
			c[j]*=m;
			m=0;
			i--;
		}
		else if(a[i]=='/'){
			i++;
			for(;a[i]==' ';){
				i++;
			}
			for(;a[i]>='0'&&a[i]<='9';i++){
				m=m*10+a[i]-'0';
			}
			c[j]/=m;
			m=0;
			i--;
		}
	}
	m=c[0];
	for(int i=0;i<=k;i++){
		if(b[i]==1){
			m+=c[i+1];
		}
		else{
			m-=c[i+1];
		}
	}
	printf("%lld",m);
	
	return 0;
}
