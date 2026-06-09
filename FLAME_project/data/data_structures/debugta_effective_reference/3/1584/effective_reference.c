#include<stdio.h>
#include<string.h>
#include<ctype.h> 
int main(){
	char a[100];
	scanf("%s",a);
	int i;
	int n = strlen(a);
	int b;
	int biao1=0;
	int c;
	int e;
	for(i=0;i<n;i++){
		if(a[i]=='.'){
			b=i;
			
		}
	}
	for(i=0;i<n;i++){
		if(a[i]>='1'&&a[i]<='9'&&biao1==0){
			c=i;
			biao1=1;
		}
	}
	//printf("%d %d\n ",b,d);
	printf("%c",a[c]);
	if(b>c)e=b-c-1;
	else e=b-c;
	if(c==n-1)
		printf("e%d",e);
	else {
		printf(".");
		for(i=c+1;i<n;i++){
			if(a[i]!='.')
				printf("%c",a[i]);
		}
		printf("e%d",e);
	}
	return 0;
}

