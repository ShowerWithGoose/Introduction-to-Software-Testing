#include<stdio.h>
#include<string.h>
int main()
{
	int data,i=0,j=0,x1=0,x2=0;
	int flag1=0,flag2=1;
	int in=0;
	char op='\0',c,d;
	int sum=0;

	
	while(flag1!=1&&op!='='){
		scanf("%d %c",&data,&op);
		if(in==0){//第一次进入 
			x1=data;
			in=1;
		}
		else //in==1,第二次进入 
		{
			x1=d=='*'?x1*data:x1/data;
		}
		
		
		if(op=='*'||op=='/'){
			d=op;flag1=0;
		}
		else if(op=='+'||op=='-'){
			c=op;flag1=1;
		}
	}
	

	while(op!='='&&flag1==1){//flag1==1
		scanf("%d %c",&data,&op);
		if(flag2==1){
			x2=data;
		}
		else //flag2==0
		{
			x2=(d=='*')?x2*data:x2/data;
		}
		
		
		if(op=='*'||op=='/'){
			d=op;flag2=0;
		}
		else if(op=='+'||op=='-'){
			x1=(c=='+')?x1+x2:x1-x2;
			c=op;
			flag2=1;
		}
	}
	if(flag1==0){//从情况1进入 
		sum=x1;
	}
	else if(flag2==0)// 情况2进入 
	{
		sum=(c=='+')?x1+x2:x1-x2;
	} 
	else if(flag2==1) 
		sum=(c=='+')?x1+x2:x1-x2;
	printf("%d",sum);
}


