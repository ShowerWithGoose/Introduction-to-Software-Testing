#include<stdio.h>
int op,num;
int stack[101];
int main()
{
    int i=0;
    while(1)
    {
        scanf("%d", &op);
        if(op == 1)
        {
        	scanf("%d",&num);
            stack[i++]=num;
            if(i>=101){
            	printf("error ");
                i=i-1;
		}
        }
        if(op == 0)
        {
        	i--;
        	if(i>=0){
        	  printf("%d ",stack[i]);	
			}
            else 
			{
			 printf("error ");	i=0;
			}
        }
        if(op == -1)
        {
            break;
        }
    }
    return 0;
}

