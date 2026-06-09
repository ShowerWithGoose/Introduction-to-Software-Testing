#include <stdio.h>
int main()
{
   int i=0;
   char s[120],n;
   while ((n=getchar())!=EOF)
   {
	  if(n=='\n') break;   	
   	  s[i]=n;
   	  i++;
   }
   int k;

      for (k=0;k<i;k++)
     {
   if (s[k]=='.') 
    {
   	if ((s[0]!='0')&&(s[0]!='-'))    //大于一的正数
   	 {
   	   	int j=1;
	  	printf("%c",s[0]);
		printf(".");
		if (k>=2)
	        {
	        	while (j<k)
	        	{
	        		printf("%c",s[j]);
	        		j++;
				}
			}
		for (j=k+1;j<i;j++)
	       	{
			printf("%c",s[j]);
	     	}
		    printf("e%d",k-1);
	  } 
	else if(s[0]=='0')    //正小数
	 {
		int l;
		if (i==3)
		{
		
	    	printf("%c",s[2]);
	    	printf("e-1");
		}
		else
	{
		for (l=0;l<i;l++)
		{
		if((s[l]=='0')&&(s[l+1]!='.')&&(s[l+1]!='0'))
		{
		int p;
		printf("%c",s[l+1]);
		if (l<i-2)
		{
			printf(".");
			for (p=l+2;p<i;p++)
			printf("%c",s[p]);
		}
		printf("e-%d",l);
	    break;
	    }
	    
		  }
}
      }break;
      }
   }return 0;
}
   
   



