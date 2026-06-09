#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char line[1000];
int a[1000],b[1000];
typedef struct PolyNode* Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
};
void Attach(int c,int e,Polynomial*pRear){
	Polynomial P;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->coef=c;
	P->expon=e;
	P->link=NULL;
	(*pRear)->link=P;
	*pRear=P;
}
Polynomial ReadPoly(int g[1000],int len){
	Polynomial P,Rear,t;
	int i=0;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear=P;
	while(i<len){
		Attach(g[i],g[i+1],&Rear);
		i+=2;
	}
	t=P;
	P=P->link;
	free(t);
	return P;
}
Polynomial Mult(Polynomial P1,Polynomial P2){
	Polynomial P,Rear,t1,t2,t;
	int c,e;
	if(!P1||!P2) return NULL;
	t1=P1;
	t2=P2;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear=P;
	while(t2){
		Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
		t2=t2->link;
	}
	t1=t1->link;
	while(t1){
		t2=P2;
		Rear=P;
		while(t2){
			e=t1->expon+t2->expon;
			c=t1->coef*t2->coef;
			while(Rear->link&&Rear->link->expon>e)
			    Rear=Rear->link;
			if(Rear->link&&Rear->link->expon==e){
				if(Rear->link->coef+c)
				    Rear->link->coef+=c;
				else{
					t=Rear->link;
					Rear->link=t->link;
					free(t);
				}
			}
			else{
				t=(Polynomial)malloc(sizeof(struct PolyNode));
				t->coef=c;
				t->expon=e;
				t->link=Rear->link;
				Rear->link=t;
				Rear=Rear->link;
			}
			t2=t2->link;
		}
		t1=t1->link;
	}
	t2=P;
	P=P->link;
	free(t2);
	return P;
}
void PrintPoly(Polynomial P){
	int flag=0;
	if(!P){
		printf("0 0\n");
		return;
	}
	while(P){
		if(!flag)
		    flag=1;
		else
		    printf(" ");
		printf("%d %d",P->coef,P->expon);
		P=P->link;
	}
	printf("\n");
}
int main(){
	int i,j=0,k,len,lena,lenb;
	Polynomial P1,P2,PP;
	gets(line);
    len = strlen(line);
    for(i = 0; i < len; i++){
        while(line[i] < '0' || line[i] > '9' && i < len)i++;
        do{
            a[j] = a[j] * 10 + line[i] - '0';
            i++;
        }while(line[i] >= '0' && line[i] <= '9');
        j++;
    }lena = j;
    j = 0;
    gets(line);
    len = strlen(line);
    for(i = 0; i < len; i++){
        while(line[i] < '0' || line[i] > '9' && i < len)i++;
        do{
            b[j] = b[j] * 10 + line[i] - '0';
            i++;
        }while(line[i] >= '0' && line[i] <= '9');
        j++;
    }lenb = j;
	P1=ReadPoly(a,lena);
	P2=ReadPoly(b,lenb);
	PP=Mult(P1,P2);
	PrintPoly(PP);
	return 0;
} 

