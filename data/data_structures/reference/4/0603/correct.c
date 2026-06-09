#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h> 
int len,i,j,flag;
typedef struct node{
		char word[50];
		struct node *link;
		int times;
	}Lnode,*Linklist;
	Linklist list=NULL,r,p,q,k;
void ss(char *b)
{
	r=(Linklist)malloc(sizeof(Lnode));
			r->link=NULL;
			r->times=1;
			strcpy(r->word,b);
			if(list==NULL){
				list=r;
				p=r;
			}
			else{
				q=list;
				while(q!=NULL)
				{
					flag=0;
					if(strcmp(r->word,q->word)>0)
					{k=q;q=q->link;}
					else if(strcmp(r->word,q->word)==0)
					{q->times++;free(r);flag=1;break;}
					else if(strcmp(r->word,q->word)<0)
					{
						if(q==list){r->link=list;list=r;flag=1;break;}
						else{k->link=r;r->link=q;flag=1;break;}
					}
				}
				if(flag==0)
				{
					p->link=r;
					p=r;
				}
			}
}
int main() 
{
	char a[50],b[50];int flagg;
	freopen("article.txt","r",stdin);
	while(scanf("%s",a)!=EOF){
		flagg=0;
		len=strlen(a);
		while((a[0]<65||a[0]>90)&&(a[0]<97||a[0]>122))//qu qian
		{
			for(i=0;i<len;i++)
			{
				a[i]=a[i+1];
			}len--;
			if(len==0){flagg=1;break;}
		}
		if(flagg==1)continue;
		while((a[len-1]<65||a[len-1]>90)&&(a[len-1]<97||a[len-1]>122))
		{
			a[len-1]=a[len];//qu hou
			len--;
			}
		for(i=0;i<len;i++)
		{
			if(a[i]>=65&&a[i]<=90)a[i]+=32;	
		}
		for(i=0,j=0;i<=len;i++,j++)
		{if((a[i]>=97&&a[i]<=122)||a[i]=='\0')b[j]=a[i];
		 else
		 { b[j]='\0';ss(b);j=-1;
		   while(a[i]<97||a[i]>122){i++;}
		   i--;
		   continue;
		 }
		}
		if(i==j)ss(a);
		else if(i>j)ss(b);
	}
	while(list!=NULL){printf("%s %d\n",list->word,list->times);list=list->link;}
	return 0;
}

