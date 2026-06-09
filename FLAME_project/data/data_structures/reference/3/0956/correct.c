 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>
 int main()
 {
 	char s[105],c[105];
 	int i,k,flag=0;
	 scanf("%s",s);
	 if(s[1]=='.')
	 {
	 	if(s[0]!='0')
	 	{
	 		for(i=0;i<strlen(s);i++)
	 		{
	 			c[i]=s[i];
			 }
			printf("%se0",c);
		 }
		else
		{
			for(i=2;i<strlen(s);i++)
			{
				if(s[i]!='0')
				{
					break;
				}
			}
			if(i==strlen(s)-1)
			{
				printf("%ce-%d",s[i],i-1);
			}
			else
			{
				c[0]=s[i];
				c[1]='.';
				for(k=2;k<strlen(s)-i+2;k++)
				{
					c[k]=s[k+i-1];
				}
				printf("%se-%d",c,i-1);
			}
		}
	  } 
	  else
	  {
	  	for(i=0;i<strlen(s);i++)
	  	{
	  		if(s[i]=='.')
	  		{
	  			flag=i;break;
			  }
		  }
		c[0]=s[0];
		c[1]='.';
		for(k=2;k-1<flag;k++)
		{
			c[k]=s[k-1];
		}
		for(;k<strlen(s);k++)
		{
			c[k]=s[k];
		}
		printf("%se%d",c,flag-1);
	  }
	  return 0;
 }

 
 

