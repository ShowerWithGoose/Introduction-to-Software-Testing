#include<stdio.h>
#include<string.h>
int main(){
	char a[1000],b[1000],c[1000];
	int i=0,j=0,n=0,m=0;
	gets(a);
	if(a[0]=='0'&&a[1]=='.'){
		i=2;
		while(a[i]=='0')
		{i++;}
		printf("%c",a[i]);
		j=i-1;
		if(a[i+1]!='\0'){
		printf(".");}
		for(i=i+1;a[i]!='\0';i++){
		printf("%c",a[i]);
	}
	    printf("e-");
	    printf("%d",j);
	}
	else if(a[0]!='0'&&a[1]=='.'){
	printf("%s",a);
	printf("e0");
    }
	else {
	for(i=1;a[i]!='.';i++){
		b[j++]=a[i];
	}
	m=i-1;
	printf("%c",a[0]);
	printf(".");
	b[j]='\0';
	for(i=i+1;a[i]!='\0';i++){
		c[n++]=a[i];
	}
	c[n]='\0';
	printf("%s",b);
	printf("%s",c);
	printf("e");
	printf("%d",m);
    }

	
	return 0;
}

