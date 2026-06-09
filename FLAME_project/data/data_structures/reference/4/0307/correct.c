#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sen{
	int n;
	char w[100];
	struct sen *l;
}*h,*p,*q,*r,*z;

int main()
{
	char s[5000],s1[100];
	int i,j,k=0,A=1,b;
	FILE *fr;
	fr=fopen("article.txt","r");
	if(fr==NULL)
	return 1;
	h=(struct sen *)malloc(sizeof(struct sen));
	h->n=0;
	h->w[0]='\0';
	h->l=NULL;
	while(fgets(s,2000,fr))
	{
		for(i=0;s[i]!='\0';i++)
		if(s[i]>='A'&&s[i]<='Z')
		s[i]=s[i]-'A'+'a';
		for(i=0;s[i]!='\0';i=i)
		{
			for(i=i;s[i]!='\0'&&!(s[i]>='a'&&s[i]<='z');i++);
			if(s[i]=='\0')
			break;
			for(j=0;s[i]!='\0'&&s[i]>='a'&&s[i]<='z';j++,i++)
			s1[j]=s[i];
			s1[j]='\0';
			if(A)
			{
				h->n=1;
				strcpy(h->w,s1);
				A=0;
				continue;
			}
			r=h;
			while(r!=NULL)
			{
				b=strcmp(s1,r->w);
				if(b==0)
				{
					r->n++;
					break;
				}
				else if(b>0)
				{
					p=r;
					r=r->l;
				}
				else
				{
					q=(struct sen *)malloc(sizeof(struct sen));
					strcpy(q->w,s1);
					q->n=1;
					q->l=r;
					if(h==r)
					h=q;
					else
					p->l=q;
					break;
				}
			}
			if(r==NULL)
			{
				q=(struct sen *)malloc(sizeof(struct sen));
				strcpy(q->w,s1);
				q->n=1;
				p->l=q;
				q->l=NULL;
			}
		}
	}
	fclose(fr);
	r=h;
	while(r!=NULL)
	{
		printf("%s %d\n",r->w,r->n);
		r=r->l;
	}
	return 0;
}

