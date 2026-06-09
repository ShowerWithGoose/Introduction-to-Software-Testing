#include<stdio.h>
char a[10000];
int main(){
	int i,j=0;
	gets(a);
	if(a[0]!='0'){
		while(a[j]!='.'){
			j++;
		}
	    printf("%c.",a[0]);
	    for(int k=1;a[k]!='\0';k++){
	    	if(a[k]!='.') printf("%c",a[k]);
		}
		printf("e%d",j-1);
	}
	else {
		j=2;
		while(a[j]=='0'){
			j++;
		}
		i=j;
		printf("%c",a[j]);
		j++;
		if(a[j]!='\0'){
		printf(".");
		for(j;a[j]!='\0';j++) printf("%c",a[j]);
		printf("e%d",-(i-1));	}
		else	{
			printf("e%d",-(j-2));
		}
	}
	return 0;
}


