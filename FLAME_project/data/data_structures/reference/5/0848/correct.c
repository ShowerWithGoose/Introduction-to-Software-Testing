#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct node{
	int a;
	int b;
};
struct node num1[1005],num2[1005],num[1005];
int compar(const void *p1, const void *p2){
	struct node *s=(struct node *)p1;
	struct node *t=(struct node *)p2;
	return (t->b -s->b );
}
int main(){
	int x,y,i=0,j,k=0,m,n1,n2,za,zb,f;
	char ch;
	while(1){
		scanf("%d%d",&x,&y);
		ch=getchar();
		if(ch=='\n'){
			num1[i].a =x;
			num1[i].b =y;
			n1=i+1;
			i=0;
			break;
		}
		else{
			num1[i].a =x;
			num1[i].b =y;
			i++;
		}
	}
	while(1){
		scanf("%d%d",&x,&y);
		ch=getchar();
		if(ch=='\n'){
			num2[i].a =x;
			num2[i].b =y;
			n2=i+1;
			i=0;
			break;
		}
		else{
			num2[i].a =x;
			num2[i].b =y;
			i++;
		}
	}
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			za=num1[i].a *num2[j].a ;
			zb=num1[i].b +num2[j].b ;
			f=0;
			for(m=0;m<k;m++){
				if(num[m].b ==zb){
					num[m].a +=za;
					f=1;
					break;
				}
			}
			if(f==0){
				num[k].a =za;
				num[k].b =zb;
				k++;
			}
		}
	}
	qsort(num,k,sizeof(struct node),compar);
	for(m=0;m<k;m++){
		printf("%d %d ",num[m].a ,num[m].b );
	}
}

