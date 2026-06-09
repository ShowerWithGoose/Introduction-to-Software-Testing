#include<stdio.h>
#include<string.h>
#include<ctype.h>
int kexue(char *a);
int main(){
	char a[1005];
	gets(a);
int i,j;
int n1=0,n2=0,n3=0;

if(strlen(a)==3){
	printf("%ce-1",a[2]);return;
}

for(i=0;i<strlen(a);i++){
	if(a[i]=='.')break;
} //a[i]='.'
n1=i;
for(i=0;i<strlen(a);i++){
	if(a[i]!='0'&&a[i]!='.')
	break;
} //a[i]=第一个非0数字 
n2=i;
	n3=n1-n2;
	if(n1>n2){
		for(i=0;i<n3-1;i++,n1--){
			a[n1]=a[n1-1];a[n1-1]='.';
		};
	}
	
	if(n1<n2){
		a[0]=a[n2];a[1]='.';
		for(i=n2,j=2;i<strlen(a);i++,j++){///7.000000745645 
		 a[j]=a[i+1];
		}
	//	a[j+2]=\0;
		/*for(i=j+2;i<strlen(a);i++){
			a[i]='0';
		}*/
	}
	




if(n1>n2){printf("%s",a);printf("e%d",n3-1);
}
if(n1<n2){
	for(i=0;i<j-1;i++){
		printf("%c",a[i]);
	}
	printf("e%d",n3);
}
	return 0;
} 





