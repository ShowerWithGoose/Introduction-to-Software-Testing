#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
	long long a[10000],out=0;
	int i=0,n=0,m=0,sl=1;
	char s[10000],ch[10000]={0};
	gets(s);
	while(s[i]!='='){
		if(isdigit(s[i])){
			a[n]=a[n]*10+s[i]-'0';
			i++;
		}
		else if(s[i]==' '){
			i++;
		}
		else {
			ch[m]=s[i];
			m++;
			n++;
			i++;
		}
	}
	for(i=0;i<=m;i++){
		if (ch[i]=='*'){
			a[i+1]*=a[i];
			a[i]=0;
		}
		else if(ch[i]=='/'){
			a[i+1]=a[i]/a[i+1];
			a[i]=0;
		}
	}
	for(i=0;i<=n;i++){
		
		if(sl==1){
			out+=a[i];
		}
		if(sl==0){
			out-=a[i];
		}
		if(ch[i]=='+'){
			sl=1;
		}
		if(ch[i]=='-'){
			sl=0;
		}
	
	}
	printf("%d",out);
	return 0;
}

