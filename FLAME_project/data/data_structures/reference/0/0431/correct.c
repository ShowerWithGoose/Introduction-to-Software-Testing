#include<stdio.h>
#include<string.h>
int m(char c){
	if(c<='9'&&c>='0') return 0;
	else if(c<='z'&&c>='a') return 1;
	else if(c<='Z'&&c>='A') return 2;
	else return 3;
}
int main(){
	char a[100];
	gets(a);
	int i=0,f,t;
	while(a[i]!='\0'){
		f=m(a[i-1]);
		t=m(a[i+1]);
		if((a[i]=='-')&&(f==t)&&(a[i-1]<a[i+1])){
			a[i-1]+=1;
			while(a[i-1]<a[i+1]){
			    printf("%c",a[i-1]);
			    a[i-1]++;
			}
		}
		else printf("%c",a[i]);
		i++;
	}
}





