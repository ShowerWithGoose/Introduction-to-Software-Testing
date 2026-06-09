#include<stdio.h>
#include<string.h>
int main(){
	char a[105];
	int len,i,j,s;
	gets(a);
	len=strlen(a);
	for(i=0;i<len;i++){
		if(a[i]=='.')
		s=i;
	}
	if(s==1&&a[0]=='0'){
	for(i=2;i<len;i++){
		if(a[i]!='0'&&i==len-1)
		printf("%de-%d",a[i]-48,len-2);
		if(a[i]!='0'&&i!=len-1){
			printf("%d.",a[i]-48);
			for(j=i+1;j<len;j++)
			printf("%d",a[j]-48);
			printf("e-%d",i-1);
			break;
		}
	}
	}
	if(s==1&&a[0]!='0'){
		for(i=0;i<len;i++){
			if(i==1)
			printf(".");
			else if(i!=1)
			printf("%d",a[i]-48);
		}printf("e0");
	}
	if(s!=1){
		for(i=0;i<len;i++){
			if(i==1)
			printf(".%d",a[i]-48);
			if(i!=1&i!=s)
			printf("%d",a[i]-48);
			if(i==s)
			continue;
	}printf("e%d",s-1);}
}

