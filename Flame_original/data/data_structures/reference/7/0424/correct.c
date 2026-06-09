#include <stdio.h>
#include <stdlib.h>

struct dot{
	struct dot * Lson;
	struct dot * Rson;
	int val;
	int H;
}Dad;

int n,a;

void print(struct dot* now){
	if(now->Lson!=NULL)print(now->Lson);
	if(now->Rson!=NULL)print(now->Rson);
	if(now->Lson==NULL&&now->Rson==NULL)printf("%d %d\n",now->val,now->H);
	return;
}

int main(){
	scanf("%d %d",&n,&Dad.val);
	Dad.H=1;
	while(--n)
	{
		scanf("%d",&a);
		struct dot* Now=&Dad;
		while(!(a>=Now->val&&Now->Rson==NULL)&&!(a<Now->val&&Now->Lson==NULL))
			Now=(a>=Now->val?Now->Rson:Now->Lson);
		if(a>=Now->val){
			Now->Rson=(struct dot*)malloc(sizeof(Dad));
			Now->Rson->val=a;
			Now->Rson->Lson=Now->Rson->Rson=NULL;
			Now->Rson->H=Now->H+1;
		}
		else{
			Now->Lson=(struct dot*)malloc(sizeof(Dad));
			Now->Lson->val=a;
			Now->Lson->Rson=Now->Lson->Lson=NULL;
			Now->Lson->H=Now->H+1;
		}
	}
	print(&Dad);
	return 0;
}
