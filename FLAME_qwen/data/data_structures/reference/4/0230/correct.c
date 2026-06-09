
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef	struct pp{
		char word[55];
		int count;
	}nodes,*p;
	 nodes node[505];

	int num=0;
	
	 int flag=0;
	 int i,j,k;
		int getword(FILE *fp,char word[])
		{ int c,i=0;
			while(!isalpha(c=fgetc(fp)))
			if(c==EOF)
			return 0;
			else
			continue;
			
			word[i++]=tolower(c);
			
			while((c=fgetc(fp))!=EOF)
			{if(!isalpha(c))
				break;
				else
				word[i++]=tolower(c);
			}
			word[i]='\0';
			return 1;
			
		 } 
	 	int cmp_count(const void *p1,const void *p2)
	 	{
	 	int a;
		p node1=(p)p1;//转化格式 
		p node2=(p)p2;
		a=strcmp(node1->word,node2->word);
		 
		return a;
		 }
	 //char *w;
	 	// int insert(struct nodes list[],int pos,char *w,int n);
	/* int search(struct nodes list[],char *w,int len,int n)
	 {	int low=0;
	 	int high=len-1;
	 	int mid=0;
	 	while(low<=high)
	 	{
	 		mid=(high+low)/2;
	 		if(strcmp(w,list[mid].word)<0)
	 		high=mid-1;
	 		else if(strcmp(w,list[mid].word)>0)
	 		low=mid+1;
	 		else
	 		{list[mid].count++;
	 		return 0;
			 }
		 }
	 	return insert(list,low,w,n);
	 }*/
	/* int insert(struct nodes list[],int pos,char *w,int n)
	 {	int i;
	 for(i=n-1;i>=pos;i--)
	 {strcpy(list[i+1].word,list[i].word);
	 list[i+1].count=list[i].count; 
	 }
	 	strcpy(list[pos].word,w);
	 	list[pos].count=1;
	 	
	 	return 1;
	 	
	 }*/
	int main()
	{	char word[55];
		FILE *fp=fopen("article.txt","r");//打开文件 
		while(getword(fp,word))
		{  
		for(j=0;j<num;j++)
		{if(strcmp(word,node[j].word)==0)
			{node[j].count++;
			flag=1;
			}
			
		}
		if(flag==0)
		{strcpy(node[num].word,word);
		node[num].count=1;
		num++;
		}
		flag=0;
		}
		qsort(node,num,sizeof(nodes),cmp_count);
		
		for(i=0;i<num;i++)
		printf("%s %d\n",node[i].word,node[i].count);
		
		
		
	}



