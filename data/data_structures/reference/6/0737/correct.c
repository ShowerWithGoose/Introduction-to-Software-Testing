#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdlib.h>

typedef struct list{
	int value;
	struct list* plist;
} plist;
void delete(plist*head);
plist* createanew(plist* head);
int main(){
	int n;
	plist *h;
	plist *head=(plist*)malloc(sizeof(plist));
	head->plist=NULL;
	head->value=0;
	while(1){
		scanf("%d",&n);
		if(n==-1)
		break;
		
		
		else if(n==0){
		if(head->value==0){
		printf("error ");
		continue;
		}
		else if(head->value==1){
			printf("%d ",head->plist->value);
			head->plist=NULL;
			head->value--;
		} 
		else{
			printf("%d ",head->plist->value);
			head->value--;
			h=head->plist;
			head->plist=head->plist->plist;
			free(h);
		}
		}
		
		
		else if(n==1){
		if(head->value==100){
			printf("error ");
			continue;
		}
		head=createanew(head);
		head->value++;
		}
	}
return 0;	
}

plist* createanew(plist* head){
	plist * q;
	int a;
	q=(plist*)malloc(sizeof(plist));
	scanf(" %d ",&a);
	q->value=a;
	q->plist=head->plist;
	head->plist=q;
	return head;
}




