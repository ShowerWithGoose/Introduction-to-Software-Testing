#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct LLN{
	int times;
	char word[100];
	struct LLN *pNext;
}linklist;
int searchlist(linklist *Headnode,char *currentword){
	linklist *Currentnode=Headnode->pNext;
	if(Currentnode==NULL) return 0;//Null list
	if(Currentnode->pNext==NULL){//The list has only one member
		if(strcmp(Currentnode->word,currentword)==0){
			Currentnode->times++;
			return 1;
		}
		else return 0;
	}
	else{
		while(Currentnode!=NULL){
				if(strcmp(Currentnode->word,currentword)==0){
					Currentnode->times++;
					return 1;
				}
				else Currentnode=Currentnode->pNext;
			}
		return 0;
	}
}
void AddToList(linklist *Headnode,char *currentword){
	int count=0; 
	linklist *Currentnode=Headnode->pNext;
	linklist *nodeToInsert=(linklist*)malloc(sizeof(linklist));
	if(Currentnode==NULL){//If the link list is null
		strcpy(nodeToInsert->word,currentword);
		nodeToInsert->times=1;
		nodeToInsert->pNext=Headnode->pNext;
		Headnode->pNext=nodeToInsert;
		return;
	}
	while(Currentnode!=NULL){//The problem is here.I didn't search the last one of the list
		if(strcmp(Currentnode->word,currentword)>=0) break;
		else{
			count++;
			Currentnode=Currentnode->pNext;
		}
	}//Sort and find the former letter 
	Currentnode=Headnode->pNext;
	if(count==0){
		strcpy(nodeToInsert->word,currentword);
		nodeToInsert->times=1;
		nodeToInsert->pNext=Headnode->pNext;
		Headnode->pNext=nodeToInsert;
	}
	else{
		for(int i=1;i<count;i++) Currentnode=Currentnode->pNext;
		strcpy(nodeToInsert->word,currentword);
		nodeToInsert->times=1;
		nodeToInsert->pNext=Currentnode->pNext;
		Currentnode->pNext=nodeToInsert;
	}
	return;
}
void PrintList(linklist *Headnode){
	linklist *Currentnode=Headnode->pNext;
	while(Currentnode!=NULL){
		printf("%s %d\n",Currentnode->word,Currentnode->times);
		Currentnode=Currentnode->pNext;
	}
	return;
}
char article[10000],currentword[100];
int main(){
	linklist *Headnode=(linklist*)malloc(sizeof(linklist));
	Headnode->times=0;Headnode->word[0]='\0';Headnode->pNext=NULL;
	FILE *in;
	in=fopen("article.txt","r");
	int c;
	int a1=0;
	while((c=fgetc(in))!=EOF){
		if(c>='A'&&c<='Z') article[a1++]=c-'A'+'a';
		else article[a1++]=c;
	}
	int len=strlen(article);
	for(int i=0;i<len;i++){
		if(article[i]>='a'&&article[i]<='z'){
			int k=0;
			while(article[i+k]>='a'&&article[i+k]<='z') k++;
			memset(currentword,'\0',sizeof(currentword));
			for(int j=0;j<k;j++) currentword[j]=article[i+j];
			if(searchlist(Headnode,currentword)==1){
				i+=k-1;continue;
			}
			else{
				AddToList(Headnode,currentword);
				i+=k-1;
			}
		}
	}
	PrintList(Headnode);
	fclose(in);
	return 0;
} 

