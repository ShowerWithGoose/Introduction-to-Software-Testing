#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
	char b[200];
	int number;
	
}node[600];

int main()
{
	int i,j,k;
int num,judge=1,ppp=0;
char line[1000];
char word[200],space[200];
char wor;
	for(i=0;i<50;i++)
	space[i]='\0';
	for(i=0;i<500;i++)
	{
		strcpy(node[i].b,space);
	}
	strcpy(word,space);
	i=0;
	 FILE *fp;
    fp= fopen("article.txt","r");
    j=0,k=0;
 	while(fgets(line,1024,fp)!=NULL)
 	{
 		
 		num=strlen(line);
 		for(i=0;i<num;i++)
 		{
 			k=0;
 			
		if(line[i]>='a'&&line[i]<='z'||line[i]>='A'&&line[i]<='Z')
		{
			if(line[i]>='A'&&line[i]<='Z')
			line[i]=line[i]+32;
			k=0;
			word[k]=line[i];
			while(1)
			{
				i++;
				
				if(line[i]>='a'&&line[i]<='z'||line[i]>='A'&&line[i]<='Z')
				{
					if(line[i]>='A'&&line[i]<='Z')
					line[i]=line[i]+32;
					k++;
					word[k]=line[i];
				}
				else
				{
					for(j=0;j<ppp;j++)
					{
						if(strcmp(word,node[j].b)!=0)
						continue;
						else break;
						
					}
					if(j==ppp)
					{
						strcpy(node[ppp].b ,word);
						
						node[ppp].number =1;
						ppp++;
					}
					else
					node[j].number ++;
					for(j=0;j<k+1;j++)
					{
						word[j]='\0';
					}
					
					break;	
					
				}
				
			}
		}
		else
		continue;
		}
 		
 		
	 }
	 
	 for(i=0;i<ppp;i++)
	 {
	 	for(j=i+1;j<ppp;j++)
	 	{
	 		if(strcmp(node[i].b ,node[j].b )>0)
	 		{
	 			strcpy(word,node[j].b );
	 			num=node[j].number;
	 			for(k=j-1;k>=i;k--)
	 			{
	 				strcpy(node[k+1].b ,node[k].b );
	 				node[k+1].number =node[k].number ;
				 }
				 strcpy(node[i].b ,word);
				 node[i].number=num;
				 
			 }
		 }
	 }
	 
	 
	 for(i=0;i<ppp;i++)
	 {
	 	
	 	printf("%s %d\n",node[i].b ,node[i].number );
	 }
	 
}



