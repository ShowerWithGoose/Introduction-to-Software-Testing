#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//freopen("damn.txt","r",stdin);//
	
	char s[150],s2[300];
	memset(s,0,sizeof(s));
	memset(s2,0,sizeof(s2));
	
	gets(s);
	
	char *p1=s,*p2,start,end;
	
	int i=0,j=0;
	while(s[i]!='\0')
	{
		if(s[i]!='-')
		{
			s2[j]=s[i];i++;j++;
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
		    		s2[j]=start+1+j-temp;
				}
				i++;
	    	}
	    	else
	    	{
	    		s2[j]=s[i];i++;j++;
			    continue;
			}
		}
		
	}
	
	printf("%s",s2);
	
	return 0;
}

