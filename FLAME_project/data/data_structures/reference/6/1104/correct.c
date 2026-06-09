#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int x,i,t,a[100];
    while(1)
	{
        scanf("%d",&x);
        if(x==1)
		{
            if(i>=100) 
            {
                printf("error ");
            }
            scanf("%d",&t);
            if(i<100)
            {
	            a[i]=t;
                i++;
            }
        }
        if(x==0)
	    {
            if(i==0)
            {
                printf("error ");
            }
            if(i>0)
		    {
                printf("%d ",a[i-1]);
                i--;
            }
       }
       if(x==-1) 
       {
	        break;
	   }
    }
    return 0;
}
