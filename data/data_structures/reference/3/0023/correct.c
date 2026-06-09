#include <stdio.h>
#include <string.h>
int main ()
{
	char s[9999],str[9999];
	int a,i,j,k=0,b,c,x;
	scanf("%s",s);
	a=strlen(s);
	for(i=0;i<a;i++)
	{
		if(s[i]=='.')
		{
			break;
		}
		k++;
	}
		x=k;
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]!='.'){
			s[j++]=s[i];
		}
	}
	s[j]='\0';

	if(k==1){
		if(s[0]=='0'){
			for(i=0;i<s-1;i++)
			{
				if(s[i]!='0')
				{
					str[0]=s[i];
					break;
				}
			}
			c=a-i;
			if(s[i+1]!='\0')
			{
				for(j=1;j<c;j++)
				{
					str[j]=s[i+1];
					i++;
				}
				b=strlen(str);
				
				printf("%c.",str[0]);
				for(j=1;j<b;j++)
				{
				printf("%c",str[j]);}
				printf("e-%d",a-14);	}
			
			else
			{
				printf("%ce-%d",str[0],a-2);
			}
			
		}
		else{
		
		printf("%c.",s[0]);
		for(i=1;i<a-1;i++)
		
			printf("%c",s[i]);
		
		printf("e0");
		}
		
	}
	else
	{
		printf("%c.",s[0]);
		for(i=1;i<a-1;i++)
		
			printf("%c",s[i]);
		
		printf("e%d",k-1);
	
	}	
	return 0;
} 



