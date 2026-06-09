#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct words_{
	char word[50];
	int num;
}words;
int cmp(const void *p1,const void *p2);
int main()
{
    char c0[50],ch;
    words w0[1000];
    int i,j,k=-1,len,temp;
    memset(c0,'\0',sizeof(c0));	
	if(freopen("article.txt","r",stdin)==NULL)
	   {
	   	printf("Can't open the scanffile!\n'");
	   	return -1;
	   }
    while(scanf("%c",&ch)!=EOF)
     {
       temp=0;
	   do{
	   	 if((ch>='A')&&(ch<='Z')) ch=ch-'A'+'a';
		 if((ch>='a')&&(ch<='z')) c0[temp++]=ch;
		 ch=getchar();
	   }while(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z')));
	   if(c0[0]=='\0') continue;
	   for(i=0;i<=k;i++) 
	   	{
	   	  if(strcmp(c0,w0[i].word)==0)
			  {
			  	w0[i].num++;
			  	break;
			  }	
		} 
	   if(i==k+1)
		{
			k++;
			strcpy(w0[k].word,c0);
			w0[k].num=1;
		}
	   memset(c0,'\0',sizeof(c0));  
	 } 
	 qsort(w0,k+1,sizeof(words),cmp);
	 for(i=0;i<k;i++)
	 printf("%s %d\n",w0[i].word,w0[i].num);
	 printf("%s %d",w0[k].word,w0[k].num);	    
	fclose(stdin);
	/*	FILE *fp1,*fp2;
	fp1=fopen("books.txt","r");
	fp2=fopen("ordered.txt","w");	
	if(fp1==NULL) 
	  {
	  	printf("Can't open the scanffile!\n'");
	   	return -1;
	  }
	if(fp2==NULL)
	   {
	   	printf("Can't open the printffile!\n'");
	   	return -2;
	   }
	memset(c,'\0',sizeof(c));	
	fclose(fp1);
	fclose(fp2);*/ 
	
//	if(freopen("output.txt","w",stdout)==NULL)
//	   {
//	   	printf("Can't open the printffile!\n'");
//	   	return -2;
//	   }
//	fclose(stdout);
	return 0;
}

int cmp(const void *p1,const void *p2)
{
	words *w1=(words*)p1;
	words *w2=(words*)p2;
	int ans;
	ans=strcmp((w1->word),(w2->word));
	return ans;
}


