#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct MOde{    
	int ID;				  	
	struct MOde *boy[4];
}Leaves,*Leavesp;
struct go{	
	int ID;	
	int size;	
}go[2000];
Leaves node[2000];
int q[1000] ;
int root,tmp,boy;
int i,j,top=0,num;
void layerorder(Leavesp t)
{
	Leavesp Queue[200],p;
	int front,dear;
	if(t!=NULL)
	{
		Queue[0]=t;
		front=-1,dear=0;
		while(front<dear)	 
		{
			p=Queue[++front];
			if(p->boy[0]==NULL && p->boy[1]==NULL && p->boy[2]==NULL)
			{
				q[top]=p->ID;
				top++;
			}
			for(i=0;i<=3;i++)
			{
				if(p->boy[i]!=NULL)
				{
					Queue[++dear]=p->boy[i];
				}
			}
		}
	}
}
typedef struct art
{
	char s[20];
	int cnt;
}total;
int cmp(const void *a,const void *b)
{
	total *str1=(struct art*)a;
	total *str2=(struct art*)b;
	if(strcmp(str1->s,str2->s)>0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
total letter[100];
int main()
{
	FILE *fp1;
	fp1=fopen("article.txt","r");
	char c; 
	int i=0,j=0,k=0,l=0;
	int len=0;
	int judge=0;
	void daxunhuan()
	{

	while(fscanf(fp1,"%c",&c)!=EOF)
	{
		if(isalpha(c))
		{
			letter[i].s[j]=c;
			j++;
			judge=1;
		}
		else
		{
			if(!isalpha(letter[i].s[0]))
			{
				continue;
			}
			else if(judge==1)
			{
				letter[i].s[j]='\0';
				letter[i].cnt=1;
				i++;
				j=0;
			}
		}
	}	}daxunhuan();
	int num=i;
	void bianli()
	{
	for(i=0;i<num;i++)
	{
		for(j=0;j<strlen(letter[i].s);j++)
		{
			if(isupper(letter[i].s[j]))
			{
				letter[i].s[j]=tolower(letter[i].s[j]);
			}
		}
	}	}bianli();
	qsort(letter,num,sizeof(struct art),cmp);
	void tyu()
	{
	for(i=0;i<num;)
	{
		if(strcmp(letter[i].s,letter[i+1].s)==0)
		{
			for(j=i;j<num-1;j++)
			{
				letter[j+1]=letter[j+2];
			}
			letter[i].cnt++;
			num--;
		}
		else
		{
			i++;
		}
	}	}tyu();
	void asd()
	{
	for(i=0;i<num;i++)
	{
		if(letter[i].s[0]!='\0')
		{
			printf("%s %d\n",letter[i].s,letter[i].cnt);
		}
	}	}asd();
	return 0;
}





