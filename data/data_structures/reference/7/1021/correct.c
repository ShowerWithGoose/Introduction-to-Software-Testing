#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int a;
	struct node *s1,*s2;
};
typedef struct node tru,*tr;
void get(tr fr,int j){
	int i;
	if(fr->s1==NULL&&fr->s2==NULL)
    printf("%d %d\n",fr->a,j);
	{if(fr->s1!=NULL)
		get(fr->s1,j+1);
		if(fr->s2!=NULL)
		get(fr->s2,j+1);
	}
}
tr jud(tr ln,int p){
	while(((ln->s1!=NULL)||(ln->s2!=NULL))){
		if(p<ln->a){
		if(ln->s1==NULL)
		break;
		else
		 ln=ln->s1;}
		else if(p>=ln->a){
			if(ln->s2==NULL)
			break;
		ln=ln->s2;}
		//printf("1 ");
	}

	return ln;
}
int main(){
	int i,n,k,m;
	tr head,p=NULL,q=NULL;
	head=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(head==NULL){head=(tr)malloc(sizeof(tru));
		head->a=k;
		head->s1=NULL,head->s2=NULL;
		p=head;
		}
		else {//printf("1\n");
		    q=(tr)malloc(sizeof(tru));
		    q->a=k; 
		    q->s1=NULL;
		    q->s2=NULL;
		    p=jud(head,k);
		    if(k<p->a)p->s1=q;
		    else p->s2=q;
		    //printf("%d ",q->a);
		}
		p=NULL;q=NULL;
	}
	get(head,1);
	return 0;
}

