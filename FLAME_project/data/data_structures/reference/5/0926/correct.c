#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//变量循环的初始化很关键，scanf的&
void bubbleSort(int a[], int b[], int n);
int a1[1000],a2[1000];
int b1[1000],b2[1000];
int c1[1000],c2[1000];
int d1[1000],d2[1000];
int e1[1000],e2[1000];
char ch;
int main()
{
int i=0,j=0,s=0,num1=0,num2=0,p=0,mid=0,due=0;
do{
	scanf("%d%c",&d1[i],&ch);
	num1++;
	i++;
}while(ch!='\n');
i=0;
ch=' ';
do{
	scanf("%d%c",&d2[i],&ch);
	num2++;
	i++;
}while(ch!='\n');
num2=num2/2;
for(i=0;i<num2;i++){
	b1[i]=d2[2*i];
	b2[i]=d2[2*i+1];
}
num1=num1/2;
for(i=0;i<num1;i++){
	a1[i]=d1[2*i];
	a2[i]=d1[2*i+1];
}
i=0;
for(i=0;i<num1;i++){
	for(j=0;j<num2;j++){
		c1[s]=a1[i]*b1[j];
		c2[s]=a2[i]+b2[j];
	if(c1[s]!=0){
		s++;
	}
	}
}
bubbleSort(c2,c1,s);
for(i=0;i<s;i++){
	if(c2[i]!=c2[i+1]){
printf("%d %d ",c1[i],c2[i]);
}
else{
	due=0;
	p=0;
	mid=0;
	for(p=i+1;p<s;p++){
		if(c2[i]==c2[p])
		mid++;
	}
for(p=i;p<=i+mid;p++){
	due=due+c1[p];
}
printf("%d %d ",due,c2[i]);
i=i+mid;
}
}
  return 0;
}
void bubbleSort(int a[], int b[], int n){
int i, j, hold,hold2;
for( i=0; i < n-1; i++)
for(j=0; j < n-1-i; j++)
if(a[j] < a[j+1])
{
hold = a[j];
hold2=b[j];
a[j] = a[j+1];
b[j]=b[j+1];
a[j+1]=hold;
b[j+1]=hold2;
}
}


