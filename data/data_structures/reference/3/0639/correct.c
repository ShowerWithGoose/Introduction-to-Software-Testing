#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	gets(a);
	int i,j,k;
	if(a[0]!='0'){
	for(i=0;i<strlen(a);i++){
		if(a[i]=='.'){
			for(j=i;j>1;j--){
				a[j]=a[j-1];
			}
			a[1]='.';
			break;
		}
	}
	printf("%se%d",a,i-1);
}
    else{
    	for(i=2;i<strlen(a);i++){
    		if(a[i]!='0')
    		break;
		}
		char b[100];
		b[0]=a[i];
		b[1]='.';
		for(j=2;j<=strlen(a)-i;j++){
			b[j]=a[i+j-1];
		}
		if(b[2]=='\0'){
			b[1]='\0';
		}
		printf("%se-%d",b,i-1);
	}
	return 0;
}

