//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define eps 1e-6
char word[105]={'\0'};
typedef struct node{
	char name[105];
	int cnt;
	struct node* next;
}wo;

wo* cha(wo* head){
	wo* temp=head->next;
	wo* a=(wo*)malloc(sizeof(wo));
	int l=strlen(word),i;
	for(i=0;i<l;i++) a->name[i]=word[i];
	a->name[l]='\0';
	while(1){
		if(temp==NULL||strcmp(word,temp->name)<0){
			a->next=head->next;
			head->next=a;
			a->cnt=1;
			return head;
		}else if(strcmp(word,temp->name)==0){
			temp->cnt++; return head;
		}else if(temp->next==NULL||strcmp(word,temp->next->name)<0){
			a->next=temp->next;
			temp->next=a;
			a->cnt=1;
			return head;
		}else temp=temp->next;
	}
}

int main(){
	wo* head=(wo*)malloc(sizeof(wo));
	head->next=NULL;
	FILE *in;
	in=fopen("article.txt","r");
	int i;
	char ch;
	while(fscanf(in,"%c",&ch)!=EOF){
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
			if(ch>='A'&&ch<='Z')
				ch=ch-'A'+'a';
			word[i++]=ch;
		}
		else{
			if(i!=0){
				word[i]='\0';
				i=0;
				head=cha(head);
			}
			continue;
		}
	}
	wo* temp=head->next;
	while(temp!=NULL){
		printf("%s %d\n",temp->name,temp->cnt);
		temp=temp->next;
	}
	
	fclose(in);
	return 0;
}



