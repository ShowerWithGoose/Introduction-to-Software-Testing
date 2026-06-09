/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main()
{
	int i;
	char a[1006], j;

	gets(a);
	
	printf("%c", a[0]);
	for(i=1;a[i]!='\0';i++)
	{
		if(a[i]=='-'&&a[i-1]<a[i+1])
		{
			if(a[i-1]>='a'&&a[i+1]<='z')
    	{
	    	for(j=a[i-1]+1;j<a[i+1];j++)
		    {
		    	printf("%c", j);
	    	}
    	}
	    else if(a[i-1]>='A'&&a[i+1]<='Z')
    	{
	    	for(j=a[i-1]+1;j<a[i+1];j++)
		    {
		    	printf("%c", j);
	    	}
    	}
	    else if(a[i-1]>='0'&&a[i+1]<='9')
    	{
		    for(j=a[i-1]+1;j<a[i+1];j++)
		    {
		    	printf("%c", j);
	    	}
	    }
	    else
	    {
	    	printf("%c", a[i]);
		}
		}
		
		else
		{
			printf("%c", a[i]);
		}
	    
	}
	
	
	return 0;
}


