#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct wordnum
{
	char word[55];
	int num;
	struct wordnum*link;
};
struct wordnum* build()
{
	struct wordnum *list;
	list=(struct wordnum*)malloc(sizeof(struct wordnum));
	list->link=NULL;
	list->num =0;
	return list;
}
struct wordnum* insert(struct wordnum*p)
{
	struct wordnum *r;
	r=(struct wordnum*)malloc(sizeof(struct wordnum));
	r->link=p->link;
	p->link=r;
	r->num=0;
	return r;
}
int strccmp(char *p,char *q,int len)
{
	int j=0;
	for(j=0;j<len&&p[j]==q[j];j++);
	if(j==len)return 0;
	else return p[j]-q[j];
}
char temp[1048],tem[55];
int main()
{
	int i=0,j=0,len;
	struct wordnum*list,*p,*q;
	list=build();
	p=insert(list);
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(temp,1048,in)!=NULL)
	//(temp[j]>'z'||temp[j]<'a')&&(temp[j]>'Z'||temp[j]<'A')
	{
		len=strlen(temp);
		for(i=0;i<len;i++)
		{
			memset(tem,'\0',55);
			for(;i<len&&!isalpha(temp[i]);i++);
			if(i==len)break;
			for(j=0;i<len&&isalpha(temp[i]);i++)
			{
				tem[j++]=islower(temp[i])?temp[i]:(temp[i]-'A'+'a');
			}
			for(q=list,p=list->link;p->link!=NULL&&strccmp(tem,p->word,j)>0;q=p,p=p->link);
			if(p->link==NULL)
			{
				strcpy(p->word,tem);
				p->num++;
				p=insert(p);
			}
			else if(strccmp(tem,p->word,j)==0)
			{
				p->num++;
			}
			else
			{
				p=insert(q);
				strcpy(p->word,tem);
				p->num++;
			}
		}
	}
	fclose(in);
	for(p=list->link;p->link!=NULL;p=p->link)
	{
		printf("%s %d\n",p->word,p->num);	
	} 
	return 0;
}

