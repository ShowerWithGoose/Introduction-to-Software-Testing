#include<stdio.h>
#include<string.h>
int main()
{
	char a[10005];
	int i,j,p,q,m,t,z,temp,temp1=0,count;
	scanf("%s",a);
      if(a[0]=='0')
	{
		for(i=0;i<strlen(a);i++)	
		{
		  if(a[i]>'0'&&a[i]<='9')
		  {
		  	temp=i-1;
		  	break;
		  }
		}
		if((temp+2)==strlen(a))
		printf("%c",a[temp+1]);
		else
		printf("%c.",a[temp+1]);
		for(j=temp+2;j<strlen(a);j++)
		{
			printf("%c",a[j]);
		}
		printf("e-%d",temp);
    } 
    else
    {
    	if(a[1]=='.')
    	{
    		printf("%c.",a[0]);
    		for(p=2;p<strlen(a);p++)
    		{
    		printf("%c",a[p]);
    	    }
    	    printf("e0");
		}
		else
		{
			for( q=0;q<strlen(a);q++)
			{
				if(a[q]=='.')
				{
				temp1=1;
				count=q; 
	            }
			}
			    if(temp1==1)
				{
					printf("%c.",a[0]);
					for(m=1;m<count;m++)
					printf("%c",a[m]);
					for(z=count+1;z<strlen(a);z++)
					printf("%c",a[z]);
					printf("e%d",count-1);
				}
	            else
	            {
	            	printf("%c.",a[0]);
	            	for(t=1;t<strlen(a);t++)
	            	{
	                printf("%c",a[t]);
	                }
	                printf("e%d",strlen(a)-1);
	                
	            }
		}
    	
	}
    return 0;
 } 

