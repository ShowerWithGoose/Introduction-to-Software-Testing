#include <stdio.h>
#include <stdio.h>
#define MAX 500
#define MAXMAX 250000 

struct item{
	int a;
	int pow;
};

typedef struct item Item;
Item many1[MAX];
Item many2[MAX];
Item many3[MAXMAX]; 

int compare(const void *a,const void * b){
	int x1 = ((struct item *)b)->pow;
	int x2 = ((struct item *)a)->pow;
	return x1 - x2;
}

int main(){
	int i1=1,i2=1;
	int flag=1;
	while(1){
		if(flag==1)
		{	scanf("%d%d",&many1[i1].a,&many1[i1].pow);
			if(getchar()=='\n') flag=2;
			else i1++;
		}
		if(flag==2)
		{	scanf("%d%d",&many2[i2].a,&many2[i2].pow);
			if(getchar()=='\n') {
				flag=3;
				break;
			}
			else i2++;
		}
	}//read
	
	int i=1,j=1,i3=1;
	for(;i<=i1;i++){
		for(j=1;j<=i2;j++,i3++){
			many3[i3].a = many1[i].a * many2[j].a;
			many3[i3].pow = many1[i].pow + many2[j].pow;
		}
	}//multi;
	
	int k=1;
	if(i3>=2){
	qsort(many3+1,i3-1,sizeof(Item),compare);
	for(k=1;k<=i3-1;k++){
		int l;
		for(l=1;many3[k].pow==many3[k+l].pow&&many3[k+l].a!=0;l++){
			many3[k].a+=many3[k+l].a;
			many3[k+l].a = 0;
		}
	}//add
	qsort(many3+1,i3-1,sizeof(Item),compare);
	}
	for(k=1;k<=i3-1;k++){
		if(many3[k].a!=0)
		printf("%d %d ",many3[k].a,many3[k].pow);
	}
	
	return 0;
}

