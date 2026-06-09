#include <stdio.h>
#include <stdlib.h>
int cmp(const void *e1,const void *e2);
struct multi{
	int num;
	int index;
};
int main(){
	struct multi a[200];
	struct multi b[200];
	struct multi c[1000];
	int i=-1,j=0,k=0;
	char ch;
	int number1=0,number2=0,number3=0;
	do{
		i++;
		scanf("%d%d%c",&a[i].num,&a[i].index,&ch);
	}while(ch!='\n');
	number1=i+1;
	i=-1;
	do{
		i++;
		scanf("%d%d%c",&b[i].num,&b[i].index,&ch);
	}while(ch!='\n');
	number2=i+1;
	for(i=0;i<number1;i++){
		for(j=0;j<number2;j++){
			c[k].num=a[i].num*b[j].num;
			c[k].index=a[i].index+b[j].index;
			k++;
		}
	}
	number3=k;
	qsort(c,number3,sizeof(c[0]),cmp);
	for(i=0;i<number3;i++){
		if(c[i].index==c[i+1].index){
			c[i+1].num+=c[i].num;
			c[i].num=0;
		}
	}
	for(i=0;i<2*number3;i++){
		if(c[i].num){	
		    printf("%d %d ",c[i].num,c[i].index);
	    }
		
	}
}
int cmp(const void *e1,const void *e2){
	return ((struct multi*)e2)->index-((struct multi*)e1)->index;
}

