#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct linklist{
	int x,n;
	struct linklist *next;
}result;

int main(int argc, char *argv[]) {
	int a[101][3],b[101][3];
	int i,j,k,l;
	char ch;
	i=0;
	do{
		scanf("%d %d",&a[i][0],&a[i][1]);
		i++;
	}while((ch=getchar())!='\n');
	j=0;
	do{
		scanf("%d %d",&b[j][0],&b[j][1]);
		j++;
	}while((ch=getchar())!='\n');
	
	result *p,*temp,*np;
	p=(result*)malloc(sizeof(result));
	temp=p;
	p->next=NULL;
	int flag=0;
	for(k=0;k<i;k++){
		for(l=0;l<j;l++){
			np=(result*)malloc(sizeof(result));
		    np->x=a[k][0]*b[l][0];
		    np->n=a[k][1]+b[l][1];
		    np->next=NULL;
		    if(temp==p) p->next=np,temp=np,flag=1;
		    else if(p->next->n<np->n){
		    	np->next=p->next;
		    	p->next=np;
		    	flag=1;
		    }
		    else{
		    	for(temp=p->next;temp->next!=NULL;temp=temp->next){
		    		if(temp->n>np->n&&temp->next->n<np->n){
		    			np->next=temp->next;
		    			temp->next=np;
		    			flag=1;
		    			break;
		    		}
		    		else if(temp->n==np->n) {
		    			temp->x=temp->x+np->x;
		    			flag=1;
		    			break;
		    		}
		    	}
		    }
		    if(flag==0){
		    	if(temp->n==np->n) temp->x=temp->x+np->x;
		        else temp->next=np;
		    }
		    flag=0;
		}
	}
	for(temp=p->next;temp!=NULL;temp=temp->next){
		printf("%d %d ",temp->x,temp->n);
	}
	return 0;
}



