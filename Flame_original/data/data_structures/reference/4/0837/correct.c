#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
	
	char ans[200];
	int ans_;
}node[100000];
FILE *in;
char s[1000];
int total=0;
char c[1000];
/*int cmp(void const *a,void const *b)
{
	
	struct Node *c=(struct Node *)a;
	struct Node *d=(struct Node *)b;
	if(cmp(c->ans,d->ans)>0)
	return 1;
	else return -1;
}*/
int main()
{
   in=fopen("article.txt","r");
   while(fgets(s,1000,in)!=NULL)
    {
    	for(int i=0;i<strlen(s);i++)
			if(s[i]>='A'&&s[i]<='Z')
				s[i]=s[i]+32;
		for(int i=0;i<strlen(s);i++)
		{   
		    if(s[i]<='z'&&s[i]>='a')
		  	{     int ji=0;
			  	while(s[i]<='z'&&s[i]>='a')
				  		  	{		
				  		  		c[ji++]=s[i];
				  		  		i++;
				  			}
				  			c[ji]='\0';
				int mark=0;		
			   for(int j=0;j<total;j++)
			   if(strcmp(node[j].ans,c)==0)
			   {
			   	mark=1;
			   	node[j].ans_++;
			//	printf("%s %s %d\n",node[j].ans,c,node[j].ans_);
			   	break;
			   }  	
			   if(mark==0)
			   {
			   	strcpy(node[total].ans,c);
			   	node[total].ans_=1;
				  
				  // printf("%s\n",node[total].ans); 
				   total++;
			   }
			  }
		}
			}
	for(int i=0;i<total;i++)
			for(int j=i;j<total;j++)
			{
				if(strcmp(node[i].ans,node[j].ans)>0)
				{
					struct Node u;
					u=node[i];
					node[i]=node[j];
					node[j]=u;		}}
				for(int i=0;i<total;i++)
				{
					printf("%s %d\n",node[i].ans,node[i].ans_);
				}	
}

