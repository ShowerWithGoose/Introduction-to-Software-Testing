#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<malloc.h>
char temps1[20],temps2[20],rubbish[20];
typedef struct character{
	char s[20];
	struct character *next;
	int num;
}CH;
CH* find(CH *l,char *cmp){
	while(l!=NULL){
		if(strcmp(l->s,cmp)>0)return NULL;
		if(l->next==NULL)return l;
		if(strcmp(l->next->s,cmp)>0)return l;
		l=l->next;	
	}
}
int main(){
	FILE *fpr=fopen("article.txt","r");
	int iread,iwrite,i;
	CH *temp1,*temp2,*list=NULL;
	fscanf(fpr,"%[^a-zA-Z]",rubbish);
	while((fscanf(fpr,"%[a-zA-Z]",temps1))!=EOF){//从file读至temps1
		fscanf(fpr,"%[^a-zA-Z]",rubbish);
		memset(temps2,'\0',sizeof(temps2));
		for(iwrite=0,i=0;temps1[i]!=0;i++){
			if(isalpha(temps1[i])){
				temps2[iwrite++]=tolower(temps1[i]);//temps1处理为没有符号的temps2
			//	printf("/%c/",tolower(temps1[i]));
			}
		}
		if(list==NULL){//第一个结点
			list=(CH*)malloc(sizeof(CH));
			list->num=1;
			list->next=NULL;
			strcpy(list->s,temps2);
			continue;
		}
		temp1=find(list,temps2);//应放置的位置附近
		if(temp1==NULL){//应插至list前
			temp2=(CH*)malloc(sizeof(CH));
			temp2->num=1;
			temp2->next=list;
			list=temp2;
			strcpy(list->s,temps2);
		}else {
			if(strcmp(temp1->s,temps2)==0)temp1->num++;
			else{
			temp2=(CH*)malloc(sizeof(CH));
			temp2->num=1;
			strcpy(temp2->s,temps2);
			temp2->next=temp1->next;
			temp1->next=temp2;
			}
		}
	}
	while(list!=NULL){
		printf("%s %d\n",list->s,list->num);
		list=list->next;
	}
}
