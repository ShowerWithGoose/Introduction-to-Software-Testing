#include<stdio.h>

int main()
{
    int s[100],input;
    int tab,top=-1;
    while(1)
    {
    	scanf("%d",&tab);
    	if(tab==-1) break;
    	switch(tab)
    		{
    		     case 1:
				 {
				 	scanf("%d",&input);
				 	if(top==99) printf("error ");
				 	else
				 	{
				 		s[++top] = input;
					 }
				 	break;
				 }
				 case 0:
				 {
				 	if(top==-1) printf("error ");
				 	else
				 	{
				 		printf("%d ",s[top]);
				 		top--;
					}
				 	
				 }	
			}
	}
	return 0;
}

