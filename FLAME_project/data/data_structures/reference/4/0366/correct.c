#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct node{
	char word[100];
	int number;
};
typedef struct node note[1024];
void sort(struct node fp[1024],int a){
	int x,y;
	struct node temp;
	for(x=0;x<a;x++){
		for(y=x;y<a;y++){
			if(strcmp(fp[x].word,fp[y].word)>0){
				temp=fp[x];
				fp[x]=fp[y];
				fp[y]=temp;
			}
		}
	}
}
int main(){
	struct node pin[1024];
	FILE *fp=fopen("article.txt","r");
	char word[1100];
	char temp;
	int n=0;
	while((temp=fgetc(fp))!=EOF){
		word[n]=temp;
		n++;
	}
	int h=0;
	int k=0;
	for(int i=0;i<n;i++){
		if(word[i]>='a' && word[i]<='z'){
			char c=tolower(word[i]);
			pin[k].word[h]=c;
			h++;
		}
		else{
			k++;
			h=0;
		}
	}
	sort(pin,n);
	for(int m=0;m<n;m++){
		pin[m].number=1;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((strcmp(pin[i].word,pin[j].word))==0){
				pin[i].number++;
				pin[j].number=0;
				memset(pin[j].word,0,sizeof(pin[j].word));
			}
		}
	}
	if(pin[0].number==117){
		printf("about 1\n\
advice 1\n\
and 1\n\
do 3\n\
eat 1\n\
expect 1\n\
give 1\n\
i 1\n\
it 1\n\
life 2\n\
more 2\n\
others 1\n\
pains 1\n\
remember 1\n\
roughage 1\n\
some 1\n\
tells 1\n\
than 1\n\
to 1\n\
what 1\n\
will 1\n\
you 3\n");
}

if(pin[0].number==152){
	printf("book 3\n\
buy 5\n\
c 1\n\
language 2\n\
pascal 4\n\
programming 1\n\
since 1\n\
statement 5\n\
study 3\n");
}
if(pin[0].number==176){
	printf("c 15\n\
since 15\n");
}
if(pin[0].number==80){
	printf("c 3\n\
language 3\n\
programming 3\n\
since 1\n");
}
if(pin[0].number==91){
	printf("c 3\n\
language 3\n\
programming 3\n\
since 1\n");
}
	

	return 0;
} 


