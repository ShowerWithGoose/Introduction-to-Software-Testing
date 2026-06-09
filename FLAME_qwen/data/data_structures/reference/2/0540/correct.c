#include <stdio.h>
#include <math.h>
  
 int renumber()     //读数字函数
      {
   	    int number;
   	    scanf(" %d",&number);
   	    return number;
	  }   
	char refuhao()    //读符号函数
	  {
		char fuhao;
		scanf(" %c",&fuhao);
		return fuhao;
	  }  
	int caculating(int a,int b,char c)//计算函数
	   {
	   	int result;
	   	if (c=='*')
	   	    result=a*b;
	   	else if(c=='/')
	   	    result=a/b;
	   	else if (c=='+')
	   	    result=a+b;
	   	else
	   	    result=a-b;
	   	return result;
	   }
int main()
{
	char q1,q2;
	int  n1,n2;
	n1=renumber();
	q1=refuhao();
	
	if (q1!='=')
	n2=renumber();
	while (q1!='=')
	{
		if ((q1=='*')||(q1=='/'))
	    {
	    	n1=caculating(n1,n2,q1);
	    	q1=refuhao();
	    	if (q1!='=')
	    	{
	    		n2=renumber();
			}
	    	
		}
		else 
		{
			q2=refuhao();
			if ((q2=='+')||(q2=='-')||(q2=='='))
			{
			n1=caculating(n1,n2,q1);
			q1=q2;
			if (q2!='=')
			n2=renumber();
		    }
			
			else if (q2!='=')
			{
				int n3=renumber();
				n2=caculating(n2,n3,q2);
				
			}
			else
			q1=q2;
		}
		

	}
	printf("%d\n",n1);
	
		return 0;
}
		
	
  

   

