#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char a[100]={0},x[100]={0};
	int i=0,count[100]={0},j=0,len=0,m=1,sum=0,n[100]={0},nu;
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]!=' '&&a[i]!='='){
			x[len]=a[i];
			len++;
		}
	}
	for(i=0,nu=0;x[i]!='\0';i++){
		if(x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'){
			count[nu]=i;
			nu++;
		}
	}
	count[nu]=len;
	for(i=0;count[j]!='\0';i++){
		for(m=1,i=count[j]-1;(j>=1)?i>count[j-1]:i>=0;i--){
			n[j]+=(x[i]-'0')*m;
			m*=10;
		}
		if(j>=1){
			if(x[count[j-1]]=='-'){
				n[j]*=-1;
			}
			else if(x[count[j-1]]=='*'){
				n[j]=n[j-1]*n[j];
				n[j-1]=0;
			}
			else if(x[count[j-1]]=='/'){
				n[j]=n[j-1]/n[j];
				n[j-1]=0;
			}
		}
		j++;
		m=1;
	}
	for(i=0;i<nu+1;i++){
		sum+=n[i];
	}
	printf("%d",sum);
	return 0;

}

