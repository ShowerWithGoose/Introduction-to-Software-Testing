#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a;
    int i=0,j=0;
    scanf("%c",&a);
    if(
	a=='0')  
    {    int count=1;
        getchar();
        while(scanf("%c",&a))
        {
            if(a=='0')
                count++;
            else
            {
                printf("%c",a);
                break;
            }
        }
        scanf("%c",&a);
        if(a=='\n')
                {
                  printf("e-%d",count);
				  }
            if(a!='\n')
            {printf(".%c",a);
            
            while(scanf("%c",&a))
            {
            	if(a=='\n')
            		break;
                printf("%c",a);   
                }
                printf("e-%d",count);
            }
    }
	else
	{
	printf("%c",a);	
	printf(".");
	while(scanf("%c",&a)!='\n')
	{ 
	if(a!='.'&&a!='\n')
	{i++;
	printf("%c",a);	}
	if(a=='.')
	{j=i;} if(a=='\n')
	{printf("e%d",j);break;}
	}
    } 	
    return 0;
}


