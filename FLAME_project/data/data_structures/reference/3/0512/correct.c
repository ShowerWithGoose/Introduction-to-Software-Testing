#include<stdio.h>
#include<string.h>
int main(){
	char a[105],b[105];
	int i,j,k,len,keep,x;
	gets(a);
	len=strlen(a);
	if(a[1]=='.'&&a[0]!='0'){
		printf("%se0",a);
	}
	else if(a[0]=='0'&&a[1]=='.'){
		for(i=2;i<len;i++){
			if(a[i]!='0')
			break;
		}
		keep=i;
		for(j=0;i<len;j++,i++){
			b[j]=a[i];
		}
		printf("%c",b[0]);
		if(j!=1)
		printf(".");
		for(k=1;k<j;k++){
			printf("%c",b[k]);
		}
		printf("e-%d",keep-1);
	}
	else{
		for(i=0,j=0;i<len;i++){
			if(a[i]=='.')
			break;
			b[j]=a[i];
			j++;
		}
		keep=i;
		printf("%c.",b[0]);
		for(x=1;x<j;x++){
			printf("%c",b[x]);
		}
		for(i=i+1;i<len;i++){
			printf("%c",a[i]);
		}
		printf("e%d",keep-1);
	}
	return 0;
}

