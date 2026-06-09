#include <stdio.h>
int main(){
	char a[100];
	int i, times, loc, start,flag;
	gets(a);
	for(i=0; i<strlen(a); i++){
		if(a[i]=='.'){
			loc=i;
			for(a[i]=='.'; i<strlen(a)-1; i++){
				a[i]=a[i+1];
			}
			a[strlen(a)-1]='\0';
			break;
		}
	}
	//printf("%s\n",a);
	//return 0;
	for(i=0; i<strlen(a); i++){
		if (a[i]!='0'){
			break;
		}
	}
	start=i;
	//printf("%d",start);
    //return 0;
	times=-start+loc-1;
	flag=1;
	for(i=0; i<strlen(a); i++){
		if(a[i]!='0'){
			flag=0;
		}
		if(flag==0){
		printf("%c",a[i]);
		if(i==start&&a[i+1]!='\0'){
			printf(".");
		}
	}		
	}
	printf("e%d",times);
	return 0;
}

