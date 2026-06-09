#include <stdio.h>
#include<string.h>
int pd(char a,char b)
{
	if(('a'<=a)&&(a<='z')&&('a'<=b)&&(b<='z'))
	return 1;
	else if(('A'<=a)&&(a<='Z')&&('A'<=b)&&(b<='Z'))
	 return 2;
	 else if(('0'<=a)&&(a<='9')&&('0'<=b)&&(b<='9'))
	 return 3;
	 else return 0;

}  
int main()
{
   char str[BUFSIZ];
   char m,ch1,ch2;
   scanf("%s",str);
   int n=strlen(str);
   for(int i=0;i<n;i++)
   {
   	  if(str[i]!='-')
   	  printf("%c",str[i]);
   	  else if(str[i]=='-')
   	  {
   	  	if(pd(str[i-1],str[i+1])==0)
   	  	printf("%c",str[i]);
   	  	else if(pd(str[i-1],str[i+1])>0)
   	  	{
   	  		ch1=str[i-1];
   	  		ch2=str[i+1];
   	  		while(ch1<ch2-1)
   	  		printf("%c",++ch1);
		}
	  }
   }
   
   
  
	return 0;
}
