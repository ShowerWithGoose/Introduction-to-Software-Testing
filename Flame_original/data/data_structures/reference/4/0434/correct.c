#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct dic
{
	char word[1000];
	int num;
	struct dic *link;
};

int main ()
{
	FILE *in;
	int i=0;
	char sreal[1000],ch;
	struct dic *first=NULL,*p=NULL,*r=NULL,*q;
	
	in=fopen("article.txt","r");
	while((ch=fgetc(in))!=EOF)
	{
		if(ch>='A'&&ch<='Z')
		{
			sreal[i]=tolower(ch);
			i++;
		}
		else if (ch>='a'&&ch<='z')
		{
			sreal[i]=ch;
			i++;
		}
		else
		{
			if (i!=0)
			{
				if (first==NULL)
				{
					q=(struct dic *)malloc(sizeof(struct dic));
					strcpy(q->word,sreal);
					q->num=1;
					q->link=NULL;
					first=q;
				}
				else
				{
					for (p=first;p!=NULL;r=p,p=p->link)
					{
						if (strcmp(sreal,p->word)<0)
						{
							q=(struct dic *)malloc(sizeof(struct dic));
							if (p==first)
							{
								strcpy(q->word,sreal);
								q->num=1;
								q->link=first;
								first=q;
							}
							else
							{
								strcpy(q->word,sreal);
								q->num=1;
								r->link=q;
								q->link=p;
							}
							break;
						}
						else if (strcmp(sreal,p->word)==0)
						{
							(p->num)++;
							break;
						}	
					}
					if (p==NULL)
					{
						q=(struct dic *)malloc(sizeof(struct dic));
						strcpy(q->word,sreal);
						q->num=1;
						r->link=q;
						q->link=NULL;
					}
				}
				i=0;
				memset (sreal,'\0',999);
			}
	
		}
			
	}
			
//		for (i=0,j=0;i<len;i++)
//		{
//			if (s[i]>='A'&&s[i]<='Z')
//			{
//				sreal[j]=tolower(s[i]);
//				j++;
//			}	
//			else if (s[i]>='a'&&s[i]<='z')
//			{
//				sreal[j]=s[i];	
//				j++;
//			}	
//		}
//		printf ("%s\n",sreal);
//		if (first==NULL)
//		{
//			q=(struct dic *)malloc(sizeof(struct dic));
//			strcpy(q->word,sreal);
//			q->num=1;
//			q->link=NULL;
//			first=q;
//		}
//		else
//		{
//			for (p=first;p!=NULL;r=p,p=p->link)
//			{
//				if (strcmp(sreal,p->word)<0)
//				{
//					q=(struct dic *)malloc(sizeof(struct dic));
//					if (p==first)
//					{
//						strcpy(q->word,sreal);
//						q->num=1;
//						q->link=first;
//						first=q;
//					}
//					else
//					{
//						strcpy(q->word,sreal);
//						q->num=1;
//						r->link=q;
//						q->link=p;
//					}
//					break;
//				}
//				else if (strcmp(sreal,p->word)==0)
//				{
//					(p->num)++;
//					break;
//				}	
//			}
//			if (p==NULL)
//			{
//				q=(struct dic *)malloc(sizeof(struct dic));
//				strcpy(q->word,sreal);
//				q->num=1;
//				r->link=q;
//				q->link=NULL;
//			}
//		}
//		memset (sreal,'\0',999);
//	}
	
	for (p=first;p!=NULL;p=p->link)
		printf ("%s %d\n",p->word,p->num);
	
	fclose(in);
	return 0;
}
