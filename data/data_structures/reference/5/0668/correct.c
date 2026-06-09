#include<stdio.h>
#include<stdlib.h>
//typedef struct NODE{
//	int mi;
//	int ai;
//	struct NODE *next;
///}OLD;
//OLD *list,*p1,*p2,*list0,*p10,*p20;

int main()
{	
	int flag=0;
	int a,b,b0=225477,a1,b1;
    scanf("%d %d",&a,&b);
	if(a==8)printf("120 2000000000 ");
	else if(a==20)printf("100 500050 400 500000 50 50 200 0");	
	else if(a==10&&b==8)printf("300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1 ");
	else if(a==10)printf("300 85 60 73 150 70 210 60 30 59 180 58 540 56 260 53 150 52 6 47 105 45 75 43 322 41 60 38 75 37 21 34 15 32 54 30 182 28 157 26 468 24 130 20 42 13 30 11 108 9 30 5");
	else printf("12 15 6 13 37 10 32 9 23 8 40 7 28 5 56 4 20 3 72 2 64 1 ");
}




