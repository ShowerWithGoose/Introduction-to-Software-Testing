#include<string.h>
#include<stdio.h>
int main(){
	char a[1000],x;
	int i;
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if(a[i+1]=='-'){
			printf("%c",a[i]);
			if(a[i]>='a'&&a[i]<='z'&&a[i+2]>='a'&&a[i+2]<='z'&&a[i]<a[i+2]){
				for(x=a[i]+1;x<a[i+2];x++)printf("%c",x);
				i++; 
			}
			else if(a[i]>='A'&&a[i]<='Z'&&a[i+2]>='A'&&a[i+2]<='Z'&&a[i]<a[i+2]){
				for(x=a[i]+1;x<a[i+2];x++)printf("%c",x);
				i++;
			}
			else if(a[i]>='0'&&a[i]<='9'&&a[i+2]>='0'&&a[i+2]<='9'&&a[i]<a[i+2]){
				for(x=a[i]+1;x<a[i+2];x++)printf("%c",x);
				i++;
		    }
		} 
		else{
			printf("%c",a[i]);
		} 
	} 
	return 0;
} 

