#include <stdio.h>
#include <string.h>
int main()
{
	 char a;
	 int i=1,p=0,q=0,h,l=1,e=0;
	 scanf("%c",&a);
	 if(a=='0')
	 {
	 	scanf(".");//这个是去除小数点，我看答案用的gets 我就用这个了 
	 	while(scanf("%c",&a))
	 	{
			if(a=='0'&&p==q)//0开头的算法 
	 		{
	 			i=i+1;//几个0 
				p=p+1;//上边比较如果p!=q就说明已经不是连续的0了就往下进行 	
			}
			else
			{
				printf("%c",a);
				break;
			}
			q=q+1;
		}
			scanf("%c",&a);
			if(a!='\n')
			{
				printf(".%c",a);
			}
			
				while(scanf("%c",&a))
				{
				if(a!='\n')
				{
				printf("%c",a);
				}
				else
				break;
				}
			printf("e-%d",i);
	 			i=0;
		}
	 
	 
	 else
	 {
	 	printf("%c.",a);
	 	while(scanf("%c",&a))
	 	{
	 		if(a=='.')
	 		{
	 			break;
			 }
			 else
			 {
			 	printf("%c",a);
			 	i=i+1;
			 }
		 }
		
		while(scanf("%c",&a))//继续输入小数点后的梳子 
		{
			if(a!='\n')//
			{
			printf("%c",a);
		}
			else
			{
			break;
		}
		}
	 printf("e%d",i-1);
}


	
		
	 	
	 	
	 	
	 	
	 
	 
	 
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}



