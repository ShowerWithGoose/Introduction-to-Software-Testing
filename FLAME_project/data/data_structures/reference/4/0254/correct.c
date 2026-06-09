#include<stdio.h> 
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct _node{
	char word[100];
	int num;
	struct _node *link;
}node,*pnode;
pnode search(char *,pnode); 
int main()
{  int i,j;
   pnode p,q,rlist;
   rlist=(pnode)malloc(sizeof(node));//头结点 
   rlist->link=NULL;
   FILE *in;
   in=fopen("article.txt","r");
   char ch,oneword[100];
   i=0;
   while((ch=fgetc(in))!=EOF)
   {
   	if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))//字母保留 
   	{
   		while((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
   		{
   			if(ch>='A'&&ch<='Z')//大写转小写 
   	        ch=ch-'A'+'a';
   	        oneword[i]=ch;
   	        i++;
   	        ch=fgetc(in);
		}//此时ch为非字母,找到一个单词oneword,
		oneword[i]='\0'; 
		i=0;
		if(rlist->link==NULL)//开头 
		{   p=(pnode)malloc(sizeof(node));
			strcpy(p->word,oneword);
			p->num=1;
			p->link=NULL;
			rlist->link=p;
		}
		else if(search(oneword,rlist)==NULL)//有序插入新单词 
		{   pnode t;
		    p=(pnode)malloc(sizeof(node));
		    strcpy(p->word,oneword);
		    p->num=1;
		    p->link=NULL;
		    for(t=rlist;t->link!=NULL;t=t->link)
		    {    
		    	if(strcmp(t->link->word,oneword)>0)//插入t和t->link之间 
		    	break;
			}
			if(t->link!=NULL)//t不是最后一个 
			p->link=t->link;
			
			t->link=p;  
		}
		else if(search(oneword,rlist)!=NULL)//单词数+1 
		{
			pnode tmp;
			tmp=search(oneword,rlist);
			(tmp->num)++;
		} 
		 for(j=0;oneword[j]!='\0';j++)
		 oneword[j]='\0';//重置oneword 
	}
   }
     
     for(p=rlist;p!=NULL;p=p->link)
     {  if(p==rlist)
       {
       	continue;
	   }
        else 
		{
     	printf("%s %d\n",p->word,p->num);
        }
	 }
	 for(p=rlist;p!=NULL;p=p->link)
	 free(p);
	 fclose(in); 
    return 0;  
}
pnode search(char *oneword,pnode rlist)//查找 
{
	pnode p;
	int flag=0;
	for(p=rlist;p!=NULL;p=p->link)
	{
		if(p==rlist)
		continue;
		if(strcmp(p->word,oneword)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	return p;
	else 
	return NULL;
}




