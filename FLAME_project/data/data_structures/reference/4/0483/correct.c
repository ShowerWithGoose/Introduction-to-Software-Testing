#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dia
{
	char word[10];
	int num;
	int cont;
};
void search (struct dia voca[],int n);
int main ()
{
	FILE*in;
	int temp=0,i=0,j=0,x,c;
	struct dia voca[100];
	in=fopen("article.txt","r");
	if(NULL==in)
	{
	 printf ("Failed to open the file !\n");
	 exit(0);
	}
	while((c=fgetc(in))!=EOF)
	{
		if((c>=65&&c<=90)||(c>=97&&c<=122))
		{
			temp=1;
			if(c>=65&&c<=90)
			{
		    c=c+32;
		    }
		    voca[i].word[j]=c;//字符串末尾没有'\0' 在输出时出现问题 
		    voca[i].num=0;
		    voca[i].cont=0;
		    j++;
	    }
	    else
	    {
	    	if(temp==1)
	    	{
	    	temp=0;
	    	voca[i].word[j]='\0';
	    	i++;
	    	j=0;
	        }
		}
	}
	if(temp==1)
	i++;
	search(voca,i);
	 for(x=0;x<i;x++)
	{
	  if(voca[x].cont==0)
	  printf("%s %d\n",voca[x].word,voca[x].num);
	} 
	return 0;
}
void search (struct dia voca[],int n)
{
	int i,j,x,y;
	struct dia c;
	for(i=n;i>0;i--)
 	{
 		for(j=0;j<i-1;j++)
 		{
 		  if(strcmp(voca[j].word,voca[j+1].word)>0)
 		 {
 			c=voca[j+1];
 			voca[j+1]=voca[j];
 			voca[j]=c;
		 }
 	    } 
    }
    for(x=0;x<n;x++)
    {
    	for(y=0;y<n;y++)
    	{
    		 if(voca[x].cont==0)
    		{
    		     if(strcmp(voca[x].word,voca[y].word)==0)
    		   {
			       voca[x].num++;
			       if(y!=x)
			         voca[y].cont=1;
    	       }
			}
		}
	}
	
	
	
}

