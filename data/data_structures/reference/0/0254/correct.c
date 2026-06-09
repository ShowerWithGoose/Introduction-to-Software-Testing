#include<stdio.h>  
#include<math.h>
#include<string.h>
#include<stdlib.h>


int main()
{  char s[1000],str[1000]={'\0'};
     gets(s);
     int i=0;
     for(i=1;i<strlen(s)-1;i++)
	 {
	 if(s[i]=='-'&&s[i-1]<s[i+1])
	    {
		if((s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')||(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')||(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'))
	     {
		 strcpy(str,&s[i+1]);
	     char tmp=s[i+1],cat=s[i-1]+1;
	     while(cat<tmp)
		 {
	     	s[i]=cat;
	     	i++;
	     	cat=cat+1;
		 }
	     	for(int j=i;j<=strlen(s);j++)
	     	s[j]='\0';
	     	strcat(s,str);
	     	for(int k=0;k<=strlen(str);k++)
	     	str[k]='\0';
		 }	
		}	
	 }
     puts(s);
    return 0;  
}



