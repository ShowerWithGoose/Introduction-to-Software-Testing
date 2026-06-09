#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//freopen("damn.txt","r",stdin);//
	
	char s[150],r[300];
	memset(s,0,sizeof(s));
	memset(r,0,sizeof(r));
	
	gets(s);
	
	char *p1=s,*p2,start,end;
	
	int i=0,j=0;
	while(s[i]!='\0')
	{
		if(s[i]!='-')
		{
			r[j]=s[i];i++;j++;
			continue;
		}
		else
		{
			start=s[i-1];end=s[i+1];
		    if((start>='a'&&start<='z'&&end>start&&end<='z')||(start>='A'&&start<='Z'&&end>start&&end<='Z')||(start>='0'&&start<='9'&&end>start&&end<='9'))
		    {
		    	int temp=j;
		    	for( ;j<temp+end-start-1;j++)
		    	{
		    		r[j]=start+1+j-temp;
				}
				i++;
	    	}
	    	else
	    	{
	    		r[j]=s[i];i++;j++;
			    continue;
			}
		}
		
	}
	
	printf("%s",r);
	
	return 0;
}

