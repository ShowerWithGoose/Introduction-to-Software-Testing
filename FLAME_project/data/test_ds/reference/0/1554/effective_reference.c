#include<stdio.h>
int main(){
	char sim[101];
	char a;
	gets(sim);
	int i,j;
	for(i=0;sim[i]!='\0';i++){
		if((sim[i]=='-'&&sim[i-1]>='a'&&sim[i+1]<='z')||(sim[i]=='-'&&sim[i-1]>='A'&&sim[i+1]<='Z')||(sim[i]=='-'&&sim[i-1]>='0'&&sim[i+1]<='9')){
			for(j=1;j<sim[i+1]-sim[i-1];j++){
				printf("%c",sim[i-1]+j);
			}
		}else{
			printf("%c",sim[i]);
		}
	}
	return 0;
}

