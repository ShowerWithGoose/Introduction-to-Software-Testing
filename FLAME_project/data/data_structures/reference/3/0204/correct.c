#include<stdio.h>
int main()
{
	char ch[105],s[105];
	int i=2,j=1,m=0,k=2;
	scanf("%s",ch);
	if(ch[0]=='0'&&ch[1]=='.')
	{
		if(ch[2]!='0')
		{
		s[0]=ch[2];
		j=1;
	    }
		else 
		{
		    for(i=2;ch[i]=='0';i++)
		    j++;
		    s[0]=ch[i];
		    
		}
		m=j;
		if(ch[m+2]=='\0')
		{
		    printf("%ce-",s[0]);
		    printf("%d",m);
	    }
    	else
		{   
		    for(k=2;ch[i]!='\0';i++,k++)
			s[k]=ch[i+1];
		    s[1]='.';
		    printf("%s",s);
		    printf("e-");
		    printf("%d",m);
	    }
		
    }
	else if(ch[0]<='9'&&ch[0]>'0'&&ch[1]=='.')
	{
	    printf("%s",ch);
	    printf("e0");
    }
	else 
	{
		s[0]=ch[0];
		s[1]='.';
	    for(i=1,k=2;ch[i]!='.';i++,k++)
	    {
		s[k]=ch[i];
		m++;
	    }
		for(;ch[i]!='\0';i++,k++)
		s[k]=ch[i+1];
		printf("%s",s);
		printf("e");
		printf("%d",m);
	}    
    return 0;
} 

