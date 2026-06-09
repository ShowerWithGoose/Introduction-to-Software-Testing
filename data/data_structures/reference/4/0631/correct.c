#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct List
{
	char word[25];
	int count;
	struct List *next;
}link;
int search(link *head,char str[])
{
	link *p=head;
	if(strcmp(str,head->word)==0)
	{
		head->count++;
		return 1;
	}
	while(p->next!=NULL)
	{
		if(strcmp(str,p->next->word)==0)
		{
			p->next->count++;
			return 1;
		}
		p=p->next;
	}
	return 0;
}
int compare(char a[],char b[])
{
	int i;
	for(i=0;a[i]!='\0'&&b[i]!='\0';i++)
	{
		if(a[i]==b[i])
		{
			continue;
		}
		else if(a[i]>b[i])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(strlen(a)>strlen(b))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
link *insert(link *head,char str[])
{
	link *p=head;
	if(compare(head->word,str)==1)
	{
		link *newnode=(link*)malloc(sizeof(link));
		newnode->count=1;
		strcpy(newnode->word,str);
		newnode->next=head;
		head=newnode;
		return head;
	}
	while(p->next!=NULL)
	{
		if(compare(p->word,str)==0&&compare(p->next->word,str)==1)
		{
			link *newnode=(link*)malloc(sizeof(link));
			newnode->count=1;
			strcpy(newnode->word,str);
			newnode->next=p->next;
			p->next=newnode;
			return head;
		}
		p=p->next;
	}
	link *newnode=(link*)malloc(sizeof(link));
	newnode->count=1;
	strcpy(newnode->word,str);
	newnode->next=NULL;
	p->next=newnode;
	return head;
}
void print(link *head)
{
	link *p=head;
	while(p->next!=NULL)
	{
		printf("%s %d\n",p->word,p->count);
		p=p->next;
	}
	printf("%s %d",p->word,p->count);
}
int main()
{
	char s[25];
	char a;
	char str[25];
	int i,j=0,k=0;
	int flag;
	int sign=0;
	link *head=(link*)malloc(sizeof(link));
	head->word[0]='\0';
	head->count=0;
	head->next=NULL;
	FILE *fp=fopen("article.txt","r");
	while(1)
	{
		flag=0;
		while(fscanf(fp,"%c",&a)!=EOF)
		{
			flag=1;
			if(a<'A'||a>'z')
			{
				break;
			}
			if(a>'Z'&&a<'a')
			{
				break;
			}
			s[k]=a;
			k++;
		}
		s[k]='\0';
		if(flag==0)
		{
			break;
		}
		if(s[0]=='\0')
		{
			continue;
		}
		k=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			{
				str[j]=s[i];
				j++;
			}
			else if(s[i]>='A'&&s[i]<='Z')
			{
				str[j]=s[i]+32;
				j++;
			}
		}
		str[j]='\0';
		//printf("%s\n",str);
		if(sign==0)
		{
			strcpy(head->word,str);
			head->count++;
			sign=1;
			j=0;
			continue;
		}
		flag=search(head,str);
		if(flag==0)
		{
			head=insert(head,str);
		}
		//print(head);
		j=0;
	/*	if(fscanf(fp,"%c",&a)!=EOF)
		{
			if(a>='a'&&a<='z')
			{
				s[k]=a;
				k++;
			}
			else if(a>='A'&&a<='Z')
			{
				s[k]=a;
				k++;
			}
		}
		else
		{
			break;
		}*/
	}
	print(head);
	fclose(fp);
	return 0;
}



