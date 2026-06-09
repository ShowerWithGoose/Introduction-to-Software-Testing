#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
	char a[500];
	scanf("%s",a);
	int i=0,len=strlen(a);
	int j=1;
	while(1){
		while(a[i]!='-'&&i!=len){
			printf("%c",a[i]);
			i++;
		}
		if(i==len){
			break;
		}
		if(isdigit(a[i+1])&&isdigit(a[i-1])&&a[i+1]>a[i-1]){
			j=1;
			while(a[i-1]+j!=a[i+1]){
				printf("%c",a[i-1]+j);
				j++;
			}
			i++;
		}else if(islower(a[i+1])&&islower(a[i-1])&&a[i+1]>a[i-1]){
			j=1;
			while(a[i-1]+j!=a[i+1]){
				printf("%c",a[i-1]+j);
				j++;
			}i++;
			
		}else if(isupper(a[i+1])&&isupper(a[i-1])&&a[i+1]>a[i-1]){
			j=1;
			while(a[i-1]+j!=a[i+1]){
				printf("%c",a[i-1]+j);
				j++;
			}
			i++;
		}else{
			printf("%c",a[i]);
			i++;
		}
		if(i==len){
			break;
		}	
	}
	
	return 0;
	
}



