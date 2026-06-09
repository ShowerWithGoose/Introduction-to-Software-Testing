#include<stdio.h>
char a[1024];
int f(char b[],int i);
int main()
{
	int i; 
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='-'){
			f(a,i);
			i++;
		}
		else printf("%c",a[i]);
	}
	return 0;
}
f(char a[],int i){
	int j;
	if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>a[i-1]&&a[i+1]<='z'){
		for(j=1;a[i-1]+j<=a[i+1];j++){
			printf("%c",a[i-1]+j);
		}
	}
	else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>a[i-1]&&a[i+1]<='Z'){
		for(j=1;a[i-1]+j<=a[i+1];j++){
			printf("%c",a[i-1]+j);
		}
	}
	else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>a[i-1]&&a[i+1]<='9'){
		for(j=1;a[i-1]+j<=a[i+1];j++){
			printf("%c",a[i-1]+j);
		}
	}
	else printf("%c%c",a[i],a[i+1]);
}

