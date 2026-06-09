#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 10000
typedef struct node *link;
struct node {
	int xi,zhi;
	link next;
};
link in1,in2,out;
link create(int xi,int zhi) {
	link temp;
	temp=(link)malloc(sizeof(struct node));
	temp->xi=xi;
	temp->zhi=zhi;
	temp->next=NULL;
	return temp;
}
void insert(link head,link in) {
	link i,p;
	i=head;
	while(i->next!=NULL) {
		if(in->zhi==i->zhi&&i->zhi!=-1) {
			i->xi+=in->xi;
			return;
		} else if(in->zhi<i->zhi&&in->zhi>i->next->zhi&&i->zhi!=-1) {
			p=i->next;
			i->next=in;
			in->next=p;
			return;
		}
		i=i->next;
	}
	if(in->zhi==i->zhi&&i->zhi!=-1) {
		i->xi+=in->xi;
		return;
	}
	i->next=in;
}
void print(link head) {
	link i=head->next;
	while(i!=NULL) {
		if(i->xi!=0)
		printf("%d %d ",i->xi,i->zhi);
		i=i->next;
	}
	printf("\n");
}
char c;
int main() {
	//FILE *IN,*OUT;
	//IN=fopen("","r");
	//OUT=fopen("","w");
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int x,y,f;
	link temp,i,j;
	in1=create(0,-1);
	in2=create(0,-1);
	out=create(0,-1);
	while(1) {
		scanf("%d %d",&x,&y);
		temp=create(x,y);
		insert(in1,temp);
		c=getchar();
		if(c=='\n')break;
	}
	while(1) {
		scanf("%d %d",&x,&y);
		temp=create(x,y);
		insert(in2,temp);
		c=getchar();
		if(c=='\n')break;
	}
	i=in1->next;
	while(i!=NULL) {
		j=in2->next;
		while(j!=NULL) {
			temp=create(j->xi*i->xi,j->zhi+i->zhi);
			insert(out,temp);
			j=j->next;
		}
//		print(out);
		i=i->next;
	}
	print(out);
	//fclose(IN);
	//fclose(OUT);
	return 0;
}


