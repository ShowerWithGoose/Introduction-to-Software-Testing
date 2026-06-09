#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//freopen("damn.txt","r",stdin);//
	
	char input[150],output[300];
	memset(input,0,sizeof(input));
	memset(output,0,sizeof(output));
	
	gets(input);
	
	char *p1=input,*p2,start,end;
	
	int i=0,j=0;
	while(input[i]!='\0')
	{
		if(input[i]!='-')
		{
			output[j]=input[i];i++;j++;
			continue;
		}
		else
		{
			start=input[i-1];end=input[i+1];
		    if((start>='a'&&start<='z'&&end>start&&end<='z')||(start>='A'&&start<='Z'&&end>start&&end<='Z')||(start>='0'&&start<='9'&&end>start&&end<='9'))
		    {
		    	int temp=j;
		    	for( ;j<temp+end-start-1;j++)
		    	{
		    		output[j]=start+1+j-temp;
				}
				i++;
	    	}
	    	else
	    	{
	    		output[j]=input[i];i++;j++;
			    continue;
			}
		}
		
	}
	
	printf("%s",output);
	
	return 0;
}

