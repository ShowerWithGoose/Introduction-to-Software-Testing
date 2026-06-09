#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){
	char xiaoshu[100];
	char a[100];
	char b[100];
	int flag=0;
	gets(xiaoshu);
	int count=0;
	if(xiaoshu[0]!='0'&&xiaoshu[1]=='.')flag=1;
	int i=0;
	int j=0;
	for(i=0;xiaoshu[i]!='\0';i++){
		if(xiaoshu[i]!='.'){
			count++;
			a[j]=xiaoshu[i];
			j++;
		}
		
	}
	a[j]='\0';
	int m=0,n=0;
	for(m=0;a[m]=='0';m++){
		
	}
	for(;a[m]!='\0';m++){
		b[n++]=a[m];
		if(n==1){
			b[n++]='.';
		}
	}
	b[n]='\0';
	n--;
	for(;b[n]=='0';n--){
		b[n]='\0';
		count--;
	}
	count--;
	for(int qq=2;b[qq]!='\0';qq++){
		count--;
	}
	if(xiaoshu[1]!='.'){
		int pp;
		for(pp=0;xiaoshu[pp]!='.';pp++){
		}
		pp--;
		count=pp;
	}
	if(n==1)b[n]='\0';
	i--;
	//printf("%d",count);
	//puts(b);
	printf("%s",b);
	printf("e");
	if(flag==1){
		printf("0");
		return 0;
	}
	else if(xiaoshu[1]=='.'){
		printf("-");
	}
	printf("%d",count);
	return 0;
}
