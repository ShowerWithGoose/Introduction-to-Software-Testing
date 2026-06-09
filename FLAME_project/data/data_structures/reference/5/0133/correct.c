# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
typedef struct student {
	int num;
	int pow;
	struct student *link;
} LinkList;

int main () {
	int a1,b1;
	char c;
	LinkList *head1=NULL,*p1,*q1;
	do {
		scanf("%d%d%c",&a1,&b1,&c);
		q1=(LinkList*)malloc(sizeof(LinkList));
		q1->num=a1;q1->pow=b1;q1->link=NULL;
		if(head1==NULL) head1=p1=q1;
		else {
			p1->link = q1;
			p1=p1->link;
		}
	} while(c!='\n');
	while(1){break;}
	int a2,b2;
	LinkList *head2=NULL,*p2,*q2,*p0;
	do {
		scanf("%d%d%c",&a1,&b1,&c);
		for(p1=head1; p1!=NULL; p1=p1->link) {
			a2=a1*p1->num;
			b2=b1+p1->pow;
			q2=(LinkList*)malloc(sizeof(LinkList));
			q2->num=a2;q2->pow=b2;q2->link=NULL;
			if(head2==NULL) head2=p2=q2;
			else {
				for(p2=head2; p2!=NULL; p0=p2,p2=p2->link) {
					if(q2->pow > p2->pow) {
						if(p2==head2) {
							q2->link=head2;
							head2=q2;
							break;
						} else {
							q2->link=p2;
							p0->link=q2;
							break;
						}
					} else if(q2->pow == p2->pow) {
						p2->num+=q2->num;break;
					}
				}
				if(p2==NULL) p0->link=q2;
			}
		}
	} while(c!='\n');
	for(p2=head2; p2!=NULL; p2=p2->link) {
		printf("%d %d ",p2->num,p2->pow);
	}
	return 0;
}

