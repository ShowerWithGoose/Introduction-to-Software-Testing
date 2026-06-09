#include<stdio.h>
#include<string.h>

int main()
{
	char s[105],start;
	int len,k,num,startnum;
	gets(s);
	len=strlen(s);
	int i;
	if(s[0]=='-')
	  k=1;
	else
	  k=0;
	if(s[k]=='0')
	{
		if(s[k+1]=='.')
		{
			for(i=k+2;i<len;i++)
			{
				if(s[i]!='0')
				{
				   start=s[i];
				   startnum=i;
				   num=i-k-1;
				   break;	
				}
			}
		//	for(i=startnum+1;i<len;i++);
			//int weishu=i-startnum-1;
		    //printf("%d\n",weishu);  
			if(k==0)
			{
				printf("%c",start);
				if(startnum!=len-1)
				printf(".");
				for(i=startnum+1;i<len;i++)
				   printf("%c",s[i]);
				printf("e-%d",num);	
			}
			else
			{
		        printf("-%c",start);
				for(i=startnum+1;i<len;i++)
					printf("%c",s[i]);
				printf("e-%d",num);	
			}
		}
		else
		  printf("0");
		  
	}
	else
	{
		if(s[k+1]=='.')
		{
			for(i=0;i<len;i++)
			   printf("%c",s[i]);
			printf("e0");
		}
		else if((s[k+1]>='0')&&(s[k+1]<='9'))
		{
			for(i=k;i<len;i++)
			{
			   if(s[i]=='.')
			   {
			   	start=s[k];
				num=i-k-1;
				break;
				//printf("%d",num);   
			   }	
			}
		
			if(i==len)
			{
				for(i=0;i<len;i++)
				printf("%c",s[i]);
			
			}
			else{
			if(k==0)
			{
				printf("%c.",start);
				for(i=k+1;i<k+1+num;i++)
				   printf("%c",s[i]);
				for(i=k+2+num;i<len;i++)
				  printf("%c",s[i]);
				printf("e%d",num);
			}
			else
			{
			printf("-%c.",start);
			for(i=k+1;i<k+1+num;i++)
				printf("%c",s[i]);
			for(i=k+2+num;i<len;i++)
				printf("%c",s[i]);
			printf("e%d",num);	
			}
			}
		}
		
	}
	return 0;
}

