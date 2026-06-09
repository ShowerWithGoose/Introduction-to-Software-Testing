#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char arr[1000];
	int time;
};
struct node art[1000];
int top=0;

void qvchong(){
	int i,j;
	for(i=0;i<top;i++){
		for(j=i+1;j<top;j++){
			if(strcmp(art[i].arr,art[j].arr)==0){
				strcpy(art[j].arr,"\0");
				art[i].time+=art[j].time;
			}
		}
	}
}
void shuchu(){
	int i;
	for(i=0;i<top;i++){
		if(strcmp(art[i].arr,"\0")!=0)
		printf("%s %d\n",art[i].arr,art[i].time);
	}
}
void paixv(){
	int i,j;
	for(i=0;i<top;i++){
		for(j=top-1;j>i;j--){
			if(strcmp(art[j-1].arr,art[j].arr)>0){
				struct node temp;
				temp=art[j-1];
				art[j-1]=art[j];
				art[j]=temp;
			}
		}
	}
}
int main(){
	char s[2000];
	FILE* p;
	p=fopen("article.txt","r");
	while((fgets(s,2000,p))!=NULL){
		int i;
		for(i=0;i<strlen(s);i++){
			if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
				if(s[i]>='A'&&s[i]<='Z'){
					s[i]=s[i]+'a'-'A';
				}
				struct node temp;int k=0;
				while(1){
					if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
							if(s[i]>='A'&&s[i]<='Z'){
					s[i]=s[i]+'a'-'A';
				}
						temp.arr[k++]=s[i];
						i++;
					}else{
						break;
					}
				}
				temp.arr[k]='\0';
				temp.time=1;
				art[top++]=temp;
			}
		}
	}	//	shuchu();
	qvchong();
	paixv();
		shuchu();
	return 0;
}

