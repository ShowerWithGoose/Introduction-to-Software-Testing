#include <stdio.h>
int main()
{
	char ch1='+',ch2;
	int a0=0,a1,a2;
	scanf("%d",&a1);
	while(1)
	{
		scanf("%c",&ch2);
		while(ch2==' ')
		scanf("%c",&ch2); 
		if(ch2=='=') break;
		scanf("%d",&a2);
		if(ch2=='/'||ch2=='*'){
			if(ch2=='/') a1/=a2;
			else a1*=a2;
		}
		else{
			if(ch1=='-') a0-=a1;
			else a0+=a1;
			a1=a2;
			ch1=ch2;
		}
	}
	switch(ch1){
		case '+':printf("%d",a0+a1);break; 
		case '-':printf("%d",a0-a1);break;
		case '*':printf("%d",a0*a1);break;
		case '/':printf("%d",a0/a1);break;
	}
 } 

