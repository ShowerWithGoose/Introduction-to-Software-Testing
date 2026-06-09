#include<stdio.h>
#include<string.h>

int main()
{
	char s[1000];
	gets(s);
	for(int i=0;i<strlen(s);i++)
	{    
		if(s[i]=='-')
		{    
		   if('A'<=s[i-1]&&s[i-1]<='Z'&&'A'<=s[i+1]&&s[i+1]<='Z'){
		   	//printf("  %c %c  ",s[i-1],s[i+1]);
		   	for(int j=0;j<s[i+1]-s[i-1]-1;j++)
			{//printf("%d  ",s[i+1]-s[i-1]);
		//	printf("sjgh");
			   char k=s[i-1];
				printf("%c",k+j+1);
			}
		   }else if('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z'){
		   	for(int j=0;j<s[i+1]-s[i-1]-1;j++)
			{//printf("%d  ",s[i+1]-s[i-1]);
			   char k=s[i-1];
				printf("%c",k+j+1);
			}
		   }else if('0'<=s[i-1]&&s[i-1]<='9'&&'0'<=s[i+1]&&s[i+1]<='9'){
		   	for(int j=0;j<s[i+1]-s[i-1]-1;j++)
			{//printf("%d  ",s[i+1]-s[i-1]);
			   char k=s[i-1];
				printf("%c",k+j+1);
			}
		   }else {
		   	printf("%c",s[i]);
		   }
			
		}else {
			printf("%c",s[i]);
		} 
		
	
	}
}



