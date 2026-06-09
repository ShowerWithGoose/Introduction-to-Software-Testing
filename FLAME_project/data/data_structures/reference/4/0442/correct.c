#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#define cre_node (node*)malloc(sizeof(node))
typedef struct node{
	int time;
	char w[101];
	struct node *next;
}node;

node *head;

/*void print(node* x)
{
	for(int i=0; i < 25 ;i++)
	{
		if(x->next[i])
		{
			if(x->next[i]->time)
			{
				printf("%s %d",x->next[i]->w,x->time);	
			}
			print(x->next[i]);
		}
	}
}*/
char a[2001];
int main ()
{
	FILE *in;
	in =fopen("article.txt","r");
	head = cre_node;
	head->time = 0;
	//out = fopen("")
//	fclose(out);
	//char a[1001];
//	fscanf(in,"%s",a);
	while(fgets(a,2001,in)!=NULL)
	{
		int i = 0;
		while(a[i] != '\0')
		{
		char word[1001];
		memset(word,0,sizeof(word));
		int top = 0;
		while((a[i] <='z' && a[i] >= 'a')||(a[i]<='Z'&&a[i]>='A'))
		{
		if(a[i]>='A'&&a[i]<='Z') word[top++] = a[i]-'A'+'a';
		else if((a[i]>='a'&&a[i]<='z'))
		{
			word[top++] = a[i];
		}
		i++;
		}
		int fflag = 0;
		for(int k = 0;word[k] != '\0';k++)
		{
			if(word[k] <'a'||word[k] >'z')	
			{
			fflag=1;
			break;}
		}
		if(fflag)
		{
			i++;
			continue;
		}
		node *p = head;
		node *last;
		int flag = 0;
		if(strcmp(head->w,word)>0||head->time == 0)
		{
			node *new_node = cre_node;
			new_node->next = head;
			head = new_node;
			head->time = 0;
			new_node->time++;
			strcpy(new_node->w,word);
			flag = 1;
		}
		else
		while(p->time != 0)
		{
			if(strcmp(word,p->w) < 0)
			{
				flag = 1;
				node* new_node = cre_node;
				new_node->next = last->next;
				strcpy(new_node->w,word);
				new_node->time=1;
				last->next =  new_node;
				break;	
			}
			else if(strcmp(word,p->w) == 0)
			{
				p->time++;
				flag=1;
				break;
			}
			last = p;
			p = p->next;
		}
		if(!flag)
		{
			p->next = cre_node;
			p->next->time = 0;
			p->time++;
			strcpy(p->w,word);
		}
		i++;
		}
		/*for(int j = 0; j <strlen(word);j++)
		{
			if(p->next[word[j]-'a'] != NULL)
			{
				p=p->next[word[j]-'a'];
			}
			else 
			{
				p->next[word[j]-'a']= cre_node;
			}
		}
		strcpy(p->w,word);
		p->time++;
		for(node *i = head;i->time !=0 ;i=i->next)
		{
			printf("%s ",i->w);
		}
		printf("\n");*/
	}
	node *p= head;
	while(p->time != 0)
	{
		
		if((p->w)[0] != NULL)
		{
		if(p->next->time == 0)
		printf("%s %d",p->w,p->time);
		else
		printf("%s %d\n\n",p->w,p->time);
		}
		p=p->next;
	}
	//print(head);
	fclose(in);
	return 0;
}



