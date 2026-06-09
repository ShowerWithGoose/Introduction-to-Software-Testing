#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct s{
		int coe;
		int pow;
		struct s *link;
	} *p,*q,*r,*list=NULL;
	int a1[100][2],a2[100][2],i1=0,i2=0,i,j,k=0,a=1;
	char c;
	while((c=getchar())!=EOF){
		if(c==' '&&a==1){
			a1[i1/2][i1%2]=k;
			k=0;
			i1++;
		}
		else if(c==' '&&a==2){
			a2[i2/2][i2%2]=k;
			k=0;
			i2++;
		}
		else if(c=='\n'&&a==1){
			a1[i1/2][i1%2]=k;
			a=2;k=0;
		}
		else if(c=='\n'&&a==2)
			a2[i2/2][i2%2]=k;
		else
			k=k*10+c-'0';
	}
	i1=i1/2+1;i2=i2/2+1;
	for(i=0;i<i1;i++){
		for(j=0;j<i2;j++){
			q=(struct s*)malloc(sizeof(struct s));
			q->coe=a1[i][0]*a2[j][0];
			q->pow=a1[i][1]+a2[j][1];
			q->link=NULL;
			if(list==NULL)
				list=p=q;
			else{
				for(p=list;p!=NULL;p=p->link){
					if(p->pow==q->pow){
						p->coe+=q->coe;
						free(q);
						break;
					}
					else if(p->pow<q->pow){
						q->link=p;
						if(p==list)
							list=q;
						else{
							for(r=list;r->link!=p;r=r->link);
							r->link=q;
						}
						break;
					}
				}
				if(p==NULL){
					for(r=list;r->link!=p;r=r->link);
					r->link=q;
				} 
			}
		}
	}
	for(p=list;p!=NULL;p=p->link){
		printf("%d %d ",p->coe,p->pow);
	}
	return 0;
}

