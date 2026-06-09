#include <stdio.h>
#include <ctype.h>
char a[100],b[100],op[100];
int num[100];
int main(){
	int m,n,p,q;
	m=n=p=q=0;
	int i=0,j=0;
	gets(a);
	while(a[i]){
		if(!isspace(a[i])){	
			b[j++]=a[i++];
		}
		else
			i++;
	}
	i=0;
	int i1=1,i2=1;
	while(b[i]){
		if(isdigit(b[i])){
			while(isdigit(b[i])){
				num[i1]=10*num[i1]+b[i]-'0';
				i++;
			}
			i1++;
		}
		else{
			switch(b[i++]){
				case'+':op[i2++]=1;break;
				case'-':op[i2++]=2;break;
				case'*':op[i2++]=3;break;
				case'/':op[i2++]=4;
			} 
		}
	}
	for(int j1=1;j1<=i2-1;j1++){
		switch(op[j1]){
			case 3:num[j1+1]=num[j1]*num[j1+1];op[j1]=op[j1-1];num[j1]=0;break;
			case 4:num[j1+1]=num[j1]/num[j1+1];op[j1]=op[j1-1];num[j1]=0;break;
		}
	}
	for(int j1=1;j1<=i2-1;j1++){
		switch(op[j1]){
			case 1:num[j1+1]=num[j1]+num[j1+1];op[j1]=1;num[j1]=0;break;
			case 2:num[j1+1]=num[j1]-num[j1+1];op[j1]=1;num[j1]=0;break;
		}
	}
	printf("%d",num[i2]);
	return 0;
}

