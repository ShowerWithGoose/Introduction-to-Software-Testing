#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[100];

int tong(int a,int b){
	if(isdigit(a)&&isdigit(b)){
		return 1;
	}
	if(isupper(a)&&isupper(b)){
		return 1;
	}
	if(islower(a)&&islower(b)){
		return 1;
	}
	return 0;
}

int main(){
	scanf("%s",a);
	int i=0;
	char c;
	for(i=0;a[i]!='\0';i++){
		putchar(a[i]);
		if(a[i+1]=='-'&&tong(a[i],a[i+2])){
			for(c=a[i]+1;c<a[i+2];c+=1){
				putchar(c);
			}
			i++;
		}
	
	}
	
}

