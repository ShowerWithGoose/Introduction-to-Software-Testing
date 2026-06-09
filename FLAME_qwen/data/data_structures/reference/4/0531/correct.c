#include<stdio.h>
#include<string.h>
#include  <stdlib.h>
#include <ctype.h>
	 struct words
	 {
	 	char wordname[20];
	 	int numname;
	 	
	};
	 char getwords[50];
	 struct words exchange;
	 struct words word[100];
	 int n=0;
	 void bubbleSort(int n)
{
int k, j, hold, flag;
for (k = 0; k < n-1; k++)
{
flag = 0;
for (j = 0; j < n-1-k; j++)
{
if (strcmp(word[j].wordname,word[j+1].wordname)>0)
{
exchange=word[j+1];
word[j+1]=word[j];
word[j]=exchange;
flag = 1;
}
}
if (0 == flag)
break;
}
}
int getWord(FILE *fp, char *w)
{
     int c;
    
    while(!isalpha(c=fgetc(fp)))  //读掉前面若干非字母的符号
        if(c == EOF) return c;  
       else continue;
    do  {
         *w++ = tolower(c); //转化为小写字母
    } while(isalpha(c=fgetc(fp))); 
    *w='\0'; //字符数组最后的’\0’
   return 1;
} 
int searchword(struct words word[],char w[])
{
	for(int i=0;i<n;i++)
	if(strstr(word[i].wordname,w)!=NULL)
	return  i;
	return -1;
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	
	 while(getWord(in,getwords)!=EOF)
	 {
	 	
	 	if(searchword(word,getwords)==-1)
	 	{
	 		
	 		strcpy(word[n].wordname,getwords);
	 		word[n].numname++;
			n++;
		 }
		 else 
		 {
		 	word[searchword(word,getwords)].numname++;
		 }
	 }
	 
	 bubbleSort(n);
	 for(int i=0;i<n;i++)
	 printf("%s %d\n",word[i].wordname,word[i].numname);
	 return 0;
	 
 } 

