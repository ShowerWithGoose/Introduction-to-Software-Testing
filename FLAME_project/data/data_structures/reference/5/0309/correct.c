#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#define Maxsize 10000

typedef struct node{
	int coe;
	int pow;
	struct node *next;
}Polynomial,* Poly;

Polynomial Po;

int num1[1000000], num2[1000000];
int coe1[1000000], pow1[1000000], coe2[1000000], pow2[1000000], coe3[1000000], pow3[1000000];
char ch1[10000]={'0'}, ch2[10000]={'0'};
int i=0, j=0, k=0;

//void CreateList(Poly list, int *coe, int *pow, int n);
//void PrintLink(Poly HeadNode);
int main()
{
	while(1)
	{
		scanf("%d",&num1[i]);
		scanf("%c",&ch1[i]);
		if(ch1[i]=='\n')
			break;
		i++;
	}
	while(1)
	{
		scanf("%d",&num2[j]);
		scanf("%c",&ch2[j]);
		if(ch2[j]=='\n')
			break;
		j++;
	}
	for(int i1=0,i2=0,i3=1;i2<=i;i1++,i2+=2,i3+=2)
	{
		coe1[i1]=num1[i2];
		pow1[i1]=num1[i3];
	}
	for(int i1=0,i2=0,i3=1;i2<=j;i1++,i2+=2,i3+=2)
	{
		coe2[i1]=num2[i2];
		pow2[i1]=num2[i3];
	}
	for(int i1=0;i1<=i/2;i1++)
	{
		for(int i2=0;i2<=j/2;i2++)
		{
			coe3[k]=coe1[i1]*coe2[i2];
			pow3[k]=pow1[i1]+pow2[i2];
			k++;
		}
	}
	//printf("%d %d\n",i/2,j/2);
	for(int i1=0;i1<k-1;i1++)
	{
		for(int i2=k-2;i2>=i1;i2--)
		{
			if(pow3[i2]<pow3[i2+1])
			{
				int temp1,temp2;
				temp1=pow3[i2];
				pow3[i2]=pow3[i2+1];
				pow3[i2+1]=temp1;
				temp2=coe3[i2];
				coe3[i2]=coe3[i2+1];
				coe3[i2+1]=temp2;
			}
			if(pow3[i2]==pow3[i2+1])
			{
				coe3[i2]+=coe3[i2+1];
				coe3[i2+1]=0;
				pow3[i2+1]=0;
			}
		}
	}
	for(int i1=0;i1<k-1;i1++)
	{
		for(int i2=k-2;i2>=i1;i2--)
		{
			if(pow3[i2]==pow3[i2+1])
			{
				coe3[i2]+=coe3[i2+1];
				coe3[i2+1]=0;
				pow3[i2+1]=0;
			}
		}
	}
	for(int i1=0;i1<k;i1++)
	{
		if(coe3[i1]!=0)
		printf("%d %d ",coe3[i1],pow3[i1]);
	}
	return 0;
}

/*void MultiPolymial(Poly list1, Poly list2, Poly list)
{
	Poly p1, p2, p, q1, q2, q;
	p1=list1;
	p2=list2;
	p=list;
	for(int i1=0;i1<=i;i1++)
	{
		for(int i2=0;i2<=j;i2++)
		{
			p->coe = p1->coe * p2->coe;
			p->pow = p1->pow + p2->pow;
			p=p->next;
			p2=p2->next;
		}
		p1=p1->next;
	}
	p=list;
	for(int i1=0;i1<(i+j)/2;i1++)
	{
		printf("%d %d ",p->coe, p->pow);
		p=p->next;
	}
}*/

/*void ZeroPolynomial(Poly PolyProd)
{
	for(int i=0;i<=)
}*/

void CreateList(Poly list, int *coe, int *pow, int n)
{
	list->next=(Poly)malloc(sizeof(Po));
	Poly p=(Poly)list->next;
	for(int i1=0;i1<=n;i1++)
	{
		p->coe=coe[i1];
		p->pow=pow[i1];
		if(i1<n)
		{
			p->next=(Poly)malloc(sizeof(Po));
			p=p->next;
		}
	}
	p->next=NULL;
}
/*void PrintLink(Poly HeadNode)
{
	Poly CurrentNode=(Poly )HeadNode->next;
	if(CurrentNode==NULL)
		printf("NULL");
	while(CurrentNode!=NULL)
	{
		printf("%d %d ",CurrentNode->coe,CurrentNode->pow);
		CurrentNode=CurrentNode->next;
	}
	printf("\n");
}*/
/*list->next=(Poly)malloc(sizeof(Polynomial));
	Poly p=(Poly)list->next;*/
	/*Poly list1=(Poly)malloc(sizeof(Polynomial));
	list1->next=(Poly)malloc(sizeof(Polynomial));
	Poly p1=(Poly)list1->next;
	for(int i1=0;i1<=i/2;i++)
	{
		p1->coe=coe1[i1];
		p1->pow=pow1[i1];
		if(i1<i/2)
		{
			p1->next=(Poly)malloc(sizeof(Polynomial));
			p1=p1->next;
		}
	}
	p1->next = NULL;*/
	/*Poly list2=(Poly)malloc(sizeof(Polynomial));
	list2->next=(Poly)malloc(sizeof(Polynomial));
	Poly p2=(Poly)list2->next;
	for(int i1=0;i1<=j/2;i++)
	{
		p2->coe=coe2[i1];
		p2->pow=pow2[i1];
		if(i1<j/2)
		{
			p2->next=(Poly)malloc(sizeof(Polynomial));
			p2=p2->next;
		}
	}
	p2->next = NULL;
	Poly list=(Poly)malloc(sizeof(Polynomial));
	list->next=(Poly)malloc(sizeof(Polynomial));
	Poly p=(Poly)list->next;
	for(int i1=0;i1<=i*j/4;i++)
	{
		p->coe=coe3[i1];
		p->pow=pow3[i1];
		if(i1<i*j/4)
		{
			p->next=(Poly)malloc(sizeof(Polynomial));
			p=p->next;
		}
	}
	p->next = NULL;*/
	/*
	Poly list1=(Poly)malloc(sizeof(Po));
	list1->coe=0;
	list1->pow=0;
	list1->next=NULL;
	Poly list2=(Poly)malloc(sizeof(Po));
	list2->coe=0;
	list2->pow=0;
	list2->next=NULL;
	Poly list=(Poly)malloc(sizeof(Po));
	list->coe=0;
	list->pow=0;
	list->next=NULL;
	CreateList(list1, coe1, pow1, i/2);
	CreateList(list2, coe2, pow2, j/2);
	Poly p1, p2, p, q1, q2, q;
	p1=list1;
	p2=list2;
	CreateList(list, coe3, pow3, i*j/4);
	p=list;
	for(int i1=0;i1<i/2;i1++)
	{
		for(int i2=0;i2<j/2;i2++)
		{
			p->coe = p1->coe * p2->coe;
			p->pow = p1->pow + p2->pow;
			p=p->next;
			p2=p2->next;
		}
		p1=p1->next;
	}
	//PrintLink(list);
	//MultiPolymial(list1, list2, list);*/
	/*for(int i1=0;i1<=i/2;i1++)
		printf("%d ",coe1[i1]);
	printf("\n");
	for(int i1=0;i1<=j/2;i1++)
		printf("%d ",coe2[i1]);
	printf("\n");
	for(int i1=0;i1<=i/2;i1++)
		printf("%d ",pow1[i1]);
	printf("\n");
	for(int i1=0;i1<=j/2;i1++)
		printf("%d ",pow2[i1]);
	printf("\n");*/



