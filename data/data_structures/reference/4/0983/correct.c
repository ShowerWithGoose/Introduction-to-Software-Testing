#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct node {
	char word[25];
	int num;
}in[2005];
int cmp(const void *a,const void *b){
	struct node c=*(struct node *)a;
	struct node d=*(struct node *)b;
	if(strcmp(c.word,d.word)>0){
		return 1;
	}
	else{
		return -1;
	}
}
int main(){
	int i=0,j=0,sum=0,cotton=0,flag=0,k,k1;
	char c;
	FILE *in1;
	in1=fopen("article.txt","r");
	while(fscanf(in1,"%c",&c)==1){
		if(isupper(c)){
			c=tolower(c);
			in[i].word[j]=c;
			cotton=1;
			j++;
		}
		else if(islower(c)){
			in[i].word[j]=c;
			cotton=1;
			j++;
		}
		else{
			if(cotton==1){
				in[i].word[j]='\0';
				cotton=0;
				j=0;
				for(k=0;k<i;k++){
					if(strcmp(in[k].word,in[i].word)==0){
						in[k].num++;
						for(k1=0;in[i].word[k1]!='\0';k1++){
							in[i].word[k1]='\0';
						}
						flag=1;
						break;
					}
				}
				if(flag==0){
					in[i].num++;
					i++;
				}
				flag=0;
			}
			else{
				cotton=0;
			}
		}
	}
	if(cotton==1){
		in[i].word[j]='\0';
		for(k=0;k<i;k++){
			if(strcmp(in[k].word,in[i].word)==0){
				in[k].num++;
				flag=1;
				sum=i;
				break;
			}
		}
		if(flag==0){
			sum=i+1;
		}
		flag=0;
	}
	else if(cotton==0){
		sum=i;
	}
	qsort(in,sum,sizeof(in[0]),cmp);
	for(k=0;k<sum;k++){
		printf("%s %d\n",in[k].word,in[k].num);
	}
	fclose(in1);
	return 0;
}

