#include<stdio.h>
#include<string.h>
int main(){
	int c=1;
	char a[101],b;
	gets(a);
	for(int i=0;a[i]!='\0';i++){
		if(a[i]=='.'){
			if(i==1){
				if(a[i-1]=='0'&&a[i+2]=='\0'){
					printf("%ce-1",a[2]);
				}
				else if(a[i-1]<='9'&&a[i-1]>='1'){
					printf("%se0",a);
				}
				else if(a[i-1]=='0'){
					for(int k=i+1;k<strlen(a)-1;k++){
						if(a[k]=='0'){
						    c++;
						}
					}
					c--;
					a[0]=a[1+c];
					for(int j=2;j<100;j++){
						a[j]=a[j+c];
					}
					printf("%se-%d",a,c);
				}
			}
			else{
				b=a[i];
				for(int j=i-1;j>0;j--){
					a[j+1]=a[j];
				}
				a[1]=b;
				printf("%se%d",a,i-1);
			}
		}
	}
	return 0;
}



