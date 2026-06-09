#include<stdio.h>
#include<string.h>
int main()
{
	char a[10001];
	gets(a);
	int i=0;
	int x,m,n=0;
	while(a[n]!='\0'){
		n++;
	}
	if(a[i]=='0'){
		i+=2;
		while(a[i]=='0'){
			i++;
		}
		printf("%c",a[i]);
		if(a[i+1]!='\0'){
			printf(".");
		}
		for(x=i+1;x<n;x++){
			printf("%c",a[x]);	
		}
		printf("e");
		printf("-%d",i-1);
	}
	else{
		while(a[i]!='.'){
			i++;
		}
		for(m=i;m<n-1;m++){
			a[m]=a[m+1];
		}
		a[n-1]='\0';
		printf("%c",a[0]);
		printf(".");
		for(x=1;x<n-1;x++){
			printf("%c",a[x]);
		}
		printf("e");
		printf("%d",i-1);
	}
	return 0;
}



