#include<stdio.h>
#include<stdlib.h>
struct Node {
	int coe;
	int pow;
	struct Node*next;
};
int main() {
	int a,n,i=0;
	int num1[1000][2];
	char c;
	struct Node *p,*q,*head,*p0;
	head=p=NULL;
	do {
		scanf("%d%d%c",&num1[i][0],&num1[i][1],&c);
		i++;
	} while(c!='\n');
	do {
		scanf("%d%d%c",&a,&n,&c);
		for(int j=0; j<i; j++) {
			q = (struct Node *)malloc(sizeof(struct Node));
			q->coe=a*num1[j][0];
			q->pow=n+num1[j][1];
			q->next=NULL;
			//printf("%d %d\n",q->coe,q->pow);
			if(head==NULL) head=p=q;
			else {
				for(p=head; p!=NULL; p0=p,p=p->next) {
					if(q->pow>p->pow) {
						if(p==head) {
							q->next=head;
							head=q;
							break;
						} else {
							q->next=p;
							p0->next=q;
							break;
						}
					} else if(q->pow==p->pow) {
						p->coe+=q->coe;
						break;
					}
				}
				if(p==NULL) p0->next=q;
				//printf("%d %d\n",p0->coe,p0->pow);
			}
		}
	} while(c!='\n');
	for(p=head; p!=NULL; p=p->next) {
		printf("%d %d ",p->coe,p->pow);
	}
	return 0;
}
