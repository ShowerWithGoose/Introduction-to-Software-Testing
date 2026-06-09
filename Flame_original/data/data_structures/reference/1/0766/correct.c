#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void e(int x,int y);     //exchange
void p();               //printf
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();
void ten();
int a[10]={1,2,3,4,5,6,7,8,9,10};
int n;
int main()
{
	scanf("%d",&n);
	if(n==1){
		p();
	}
	else if(n==2){
		p();
		e(n-1,n);//1,2
		p();
		e(n-1,n);//1,2
	}
	else if(n==3){
		three();
	}
	else if(n==4){
		four();
	}
	else if(n==5){
		five();		
	}
	else if(n==6){
		six();
	}
	else if(n==7){
		seven();
	}
	else if(n==8){
		eight();
	}
	else if(n==9){
		nine();
	}  
	else if(n==10){
		ten();
	}
}
void e(int x,int y)
{
	int temp=a[y-1];
	a[y-1]=a[x-1];
	a[x-1]=temp;
}
void p()
{
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void three()
{
	p();
	e(n-1,n);//2.3
	p();
	e(n-1,n);//2.3
	e(n-2,n-1);//1.2
	p();
	e(n-1,n);//2.3
	p();
	e(n-1,n);//2.3
	e(n-2,n);//1.3
	p();
	e(n-1,n);//2.3
	p();
	e(n-2,n);//1.3
}  
void four()
{
	three();
	e(n-3,n-2);
	three();
	e(n-3,n-1);
	three();
	e(n-3,n);
	three();
}
void five()
{
	four();
	e(n-4,n-3);
	e(n-4,n);
	e(n-4,n-1);
	e(n-4,n-2);
	four();
	e(n-4,n-2);
	e(n-4,n-3);
	e(n-4,n);
	e(n-4,n-1);
	four();
	e(n-4,n-1);
	e(n-4,n-2);
	e(n-4,n-3);
	e(n-4,n);
	four();
	e(n-4,n);
	e(n-4,n-1);
	e(n-4,n-2);
	e(n-4,n-3);
	four();
}
void six()
{
	five();
	e(n-5,n-4);//1.2
	e(n-5,n);//1.6
	e(n-5,n-2);//1.4
	e(n-3,n-1);//3.5
	five();
//312456
	e(n-5,n-3);//1.3
	e(n-5,n-1);//1.5
	e(n-4,n);//2.6
	e(n-4,n-2);//2.4
	five();
//412356
	e(n-5,n-2);//1.4
	e(n-5,n-4);//1.2
	e(n-5,n);//1.6
	e(n-3,n-1);//3.5
	five();
//512346
	e(n-5,n-1);//1.5
	e(n-5,n-3);//1.3
	e(n-4,n);//2.6
	e(n-4,n-2);//2.4
	five();
//612345
	e(n-5,n);//1.6
	e(n-5,n-2);//1.4
	e(n-5,n-4);//1.2
	e(n-3,n-1);//3.5
	five();  
}
void seven()
{
	six();
}
void eight()
{
	
}
void nine()
{
	
}
void ten()
{
	
}
/*
p
e(n-1,n)
p
e(n-1,n)  换回原位
 
e(n-2,n-1)
p
e(n-1,n)
p
e(n-2,n)
p
e(n-1,n)
p

e(n-2,n)  换回原位 

e(n-3,n-2)  重复上述过程  共重复n次 
*/



