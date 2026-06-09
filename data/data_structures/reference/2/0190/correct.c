#include <stdio.h>
#include <string.h>
int main()
{
    int sum=0,a1,a2;
    char b='+',b1,b2;
    while (1)
    {
        scanf("%d %c",&a1,&b1);
 
        while(b1=='*'||b1=='/')
        {
            scanf("%d %c",&a2,&b2);
            if(b1=='*')
			a1=a1*a2;
			else a1=a1/a2;
            b1=b2;
        }
 
 
        if(b=='+')
		sum=sum+a1;
        else if(b=='-')
		sum=sum-a1;
 
        b=b1;
 
        if(b=='=')
		{
		printf("%d\n",sum);break;
		}
   } 
 
    return 0 ;
}
 



