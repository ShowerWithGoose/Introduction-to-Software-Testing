#include <stdio.h>
int main()
{
	int zhan[200];
    int i=0,op,num;
    for(i=0;;)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            if(i==100)
            {
            	printf("error ");
			}
            else
            {
            	zhan[i]=num;
                i++;
			}
        }
        if(op==0)
        {
            if(i==0)
            {
            	printf("error ");
			}
            else
            {
            	i--;
                printf("%d ",zhan[i]);
			}
        }
        if(op==-1)
        {
        	break;
		}  
    }
}


