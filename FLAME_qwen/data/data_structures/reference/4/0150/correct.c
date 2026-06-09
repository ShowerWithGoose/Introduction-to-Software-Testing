#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
#define MAX 1000
struct node{
	char word[max];
	int count;
	struct node*link;
};
typedef struct node Node;
int getWord(FILE *fp,char str[]);
void bubble(Node*p[],int n);

int main()
{
	FILE * fp_article;
	Node * p=NULL,*q=NULL,*list=NULL,*r=NULL;
	fp_article=fopen("article.txt","r");
	char str[max];
	int i,j;
	Node * point[MAX];
while(!feof(fp_article))
{
		getWord(fp_article,str);
		if(str[0]=='\0') continue;
//		printf("%s1\n",str);
		if(list==NULL)
		{
			q=(Node*)malloc(sizeof(Node));
			q->link=NULL;
			strcpy(q->word,str);
			q->count=1;
			list=q;
			p=q;
		}
		else
		{
			for(r=list;r->link!=NULL;r=r->link)
			{
				if(strcmp(str,r->word)==0)
				{
					r->count++;
					goto end;
				}
			}
			if(strcmp(str,r->word)==0) r->count++;
		    else if(r->link==NULL)
			{
				q=(Node*)malloc(sizeof(Node));
				q->link=NULL;
				strcpy(q->word,str);
				q->count=1;
				p->link=q;
				p=q;
			}
		}
end:    continue;
}
	for(i=0,r=list;r->link!=NULL;r=r->link,i++) 
	{
	    point[i]=r;
	}
	point[i]=r;
	bubble(point,i+1);
	for(j=0;j<=i;j++) printf("%s %d\n",point[j]->word,point[j]->count);
	return 0;
}

//函数部分
int getWord(FILE*fp,char str[])
{
	int i=0;
	char tmp;
	while(1)
	{
		tmp=fgetc(fp);
		if(isalpha(tmp)) str[i++]=tolower(tmp);
		else break; 
	}
	str[i]='\0';
	return 1;
} 

void bubble(Node*p[],int n)
{
	int i,j,flag;
	Node* tmp;
	for(i=0;i<n-1;i++)//进行n-1次 
	{
		flag=0; 
		for(j=0;j<n-1-i;j++)//每次将最大的数沉到第n-i位 
		{
			if(strcmp(p[j]->word,p[j+1]->word)>0)//如果下一位比自己大就进行一次交换 
			{
				tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
				flag=1;//如果每一位的下一位都比自己小，代表已经排好，flag=0不变；否则flag=1； 
			}
		}
		if(flag==0)
		{break;}
	}
	return ;
}

