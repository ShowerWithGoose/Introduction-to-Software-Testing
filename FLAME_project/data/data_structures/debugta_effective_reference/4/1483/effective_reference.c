#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char con[1024];
char f[50];
struct word
{
	char ch[50];
	int count;
	struct word *next;
};
int isalph(char c)
{
	if('a'<=c&&c<='z')
		return 1;
	return 0;
}
struct word *settleword(struct word* head,struct word* aword);//更新数据库
int main()
{
	FILE *in=fopen("article.txt","r");
	struct word *head=(struct word *)malloc(sizeof(struct word));
	struct word *aword;
	head=NULL;
	while(fgets(con,1024,in)!=NULL)
	{
		int c,nn,k;
		int len=strlen(con);
		for(c=0;con[c]!='\0';c++)
		{
			if(con[c]>='A'&&con[c]<='Z')
			{
				con[c]=con[c]+'a'-'A';
			}
		}
		for(c=0,nn=0;con[nn]!='\0';nn++)
		{
			aword=(struct word *)malloc(sizeof(struct word));
			for(c=nn;isalph(con[c])==0;c++)
				if(c>=len)
				break;
			for(nn=c;isalph(con[nn])!=0;nn++)
				if(nn>=len)
				break;
			for(k=0;c+k<nn;k++)
				aword->ch[k]=con[c+k];
			aword->ch[k]='\0'; 
			if(!isalph(aword->ch[0]))
				continue;
			head=settleword(head,aword);
		}
	}
	aword=head;
	while(aword)
	{
		printf("%s %d\n",aword->ch,aword->count);
		aword=aword->next;
	}
	fclose(in);
	return 0;	
}
struct word *settleword(struct word* head,struct word* aword)//更新数据 
{
	struct word *pf,*pb;
	if(head==NULL)//第一次读入
	{
		head=aword;
		aword->next=NULL;
		aword->count=1;
		return head;
	}
	pf=head;
	pb=pf->next;
	if(head!=NULL)
	{
		if(pb==NULL)//第二次读入
		{
			if(strcmp(pf->ch,aword->ch)>0)
			{
				head=aword;
				aword->next=pf;
				aword->count=1;
				return aword;
			}
			else if(strcmp(pf->ch,aword->ch)<0)
			{
				pf->next=aword;
				aword->next=NULL;
				aword->count=1;
			}
			else
			{
				pf->count++;
			}
		return pf;
		}
		else//一般情况
		{
			if(strcmp(pf->ch,aword->ch)>0)//p成为表头 
			{
				head=aword;
				aword->next=pf;
				aword->count=1;
			return aword;
			}
			else if(strcmp(pf->ch,aword->ch)==0)
			{
				pf->count++;
				return head;
			}
			else if(strcmp(pf->ch,aword->ch)<0)//否则遍历寻找插入位置
			{
				while(pb!=NULL)
				{
					if(strcmp(pb->ch,aword->ch)<0)
					{
						pf=pf->next;
						pb=pb->next;
						continue;	
					}
					if(strcmp(pb->ch,aword->ch)>0)
					{
					pf->next=aword;
					aword->next=pb;
					aword->count=1;
					return head;
					}
					else if(strcmp(pb->ch,aword->ch)==0)
					{
						pb->count++;
					}
				return head;	
				}//若pb==NULL仍未返回，则表明p应放在表尾 
				pf->next=aword;
				aword->next=NULL;
				aword->count++;
			return head;
			} 
		} 
	}
}

