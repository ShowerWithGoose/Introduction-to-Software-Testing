#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char a[10000],c[10000];
	int b[1000]={0};
	int i=0,j=0,k=0;
	char m;
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='-'){
			b[j++]=i;
		}
	}
	int l=i;
	for(i=0;i<j;i++){
		if(b[i]>0&&b[i]<l){
		if(a[b[i]-1]<='z'&&a[b[i]-1]>='a'&&a[b[i]+1]<='z'&&a[b[i]+1]>='a');
		else if(a[b[i]-1]<='Z'&&a[b[i]-1]>='A'&&a[b[i]+1]<='Z'&&a[b[i]+1]>='A');
		else if(a[b[i]-1]<='9'&&a[b[i]-1]>='0'&&a[b[i]+1]<='9'&&a[b[i]+1]>='0');
		else b[i]=-1;
	}else b[i]=-1;
	}
	for(i=0;i<l;i++){
		m=0;
		if(i!=b[k]) printf("%c",a[i]);
		else{
			for(m=a[i-1]+1;m<a[i+1];m++){
				printf("%c",m);
			}
			k++;
		}
	}
	return 0;
}




