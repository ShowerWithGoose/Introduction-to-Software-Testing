#include <stdio.h>
#include<string.h>
int judge(char word){
	if(word>='a'&&word<='z')return 1;
	if(word>='A'&&word<='Z')return 2;
	if(word>='0'&&word<='9')return 3;
	return 0;
}
int main(){
     char  str1[10086],str2[10086];
     gets(str1);
	 //fgets(str1,10086,stdin);
	 int len,t,h=0;
	 int len1;
	 len =strlen(str1);
	 int i,j,k;
	 for(i=0;i<len;i++){
		 if(str1[i]!='-') printf("%c",str1[i]);
		 if(str1[i]=='-')
		 	{
				 if(judge(str1[i-1])==judge(str1[i+1])&&str1[i+1]>str1[i-1])
	 				{
	 					for(j=str1[i-1]+1;j<str1[i+1];j++)
	 					 printf("%c",j);
					
					}
	 				else	printf("%c",str1[i]);
	 		}
	 	}
	  
	 return 0;
}

