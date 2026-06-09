#include<stdio.h>
struct number{
	int number1;
	int number2;
}a[1000],b[1000],c[10000],d;
int main(){
	int i=0,j=0,m=0,n=0,q=0;
	char p;
	do{
		scanf("%d%d%c",&a[m].number1,&a[m].number2,&p);
		m++;
	}while(p!='\n');
	do{
		scanf("%d%d%c",&b[n].number1,&b[n].number2,&p);
		n++;
	}while(p!='\n'); 
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			c[q].number1=a[i].number1*b[j].number1;
			c[q].number2=a[i].number2+b[j].number2;
			q++;
		}
	}
	for(i=0;i<q;i++){
		for(j=i+1;j<q;j++){
			if(c[i].number2<c[j].number2){
				d=c[i];
				c[i]=c[j];
				c[j]=d;
			}
		}
	}
	for(i=0;i<q-1;i++){
		if(c[i].number2==c[i+1].number2){
			c[i+1].number1+=c[i].number1;
			c[i].number1=0;
		}
	}
	for(i=0;i<q;i++)
	{
		if(c[i].number1!=0)
		{
			printf("%d %d ",c[i].number1,c[i].number2);
		}
	}
	return 0;
} 

