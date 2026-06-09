#include<stdio.h>
#include<string.h>
#include<ctype.h> 
int main(){
	char a[100];
	scanf("%s",a);
	int i;
	int n = strlen(a);
	int b;
	int c=0;
	int d;
	int e;
	for(i=0;i<n;i++){
		if(a[i]=='.'){
			b=i;
			
		}
	}
	for(i=0;i<n;i++){
		if(a[i]>='1'&&a[i]<='9'&&c==0){
			d=i;
			c=1;
		}
	}
	//printf("%d %d\n ",b,d);
	printf("%c",a[d]);
	if(b>d)e=b-d-1;
	else e=b-d;
	if(d==n-1)
		printf("e%d",e);
	else {
		printf(".");
		for(i=d+1;i<n;i++){
			if(a[i]!='.')
				printf("%c",a[i]);
		}
		printf("e%d",e);
	}
	return 0;
}

