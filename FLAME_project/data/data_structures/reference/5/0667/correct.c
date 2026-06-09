#include<stdio.h>
#include<stdlib.h>
struct line1{
	int xi1;
	int zhi1;
};
struct line2{
	int xi2;
	int zhi2;
};
struct line3{
	int xi3;
	int zhi3;
	struct line3* link;
};
	struct line1 s1[1000];
	struct line2 s2[1000];
	struct line3 s3[10000];
void sort(struct line3 s3[],int n)
{
	int i=0,j=0; struct line3 tmp;
	while(j<n-1)
	{
		while(i<n-1-j)
		{
			if(s3[i].zhi3<s3[i+1].zhi3) //升序排 
			{
				tmp=s3[i];
				s3[i]=s3[i+1];
				s3[i+1]=tmp;
			}
			i++;
		}
		j++; i=0;
	}
}
struct line3* createlist()
{
	struct line3* headnode=(struct line3*)malloc(sizeof(struct line3));
	headnode->link=NULL; 
	return headnode;
}
void makelist(struct line3* headnode,int n,struct line3 s3[]) //制表 
{
	int i=0;
	struct line3* list=headnode;
	while(i<n)
	{
		struct line3* newnode=(struct line3*)malloc(sizeof(struct line3));
		newnode->xi3=s3[i].xi3; newnode->zhi3=s3[i].zhi3;
		list->link=newnode;
		list=list->link;
		newnode->link=NULL;
		i++;
	}
}
void combine(struct line3* headnode)
{
	struct line3* move=headnode->link;
	struct line3* moveback=headnode->link->link;
	struct line3* tmp;
	while(moveback!=NULL)
	{
		if(move->zhi3==moveback->zhi3) //将moveback加到move中 并删除moveback 
		{
			move->xi3=move->xi3+moveback->xi3;
			tmp=moveback;
			move->link=moveback->link;
			moveback=move->link; 
			free(tmp);
		}
		else 
		{
			move=move->link;
			moveback=moveback->link;
		}
	}
}
void printflist(struct line3* headnode)
{
	struct line3* pmove=headnode->link;
	while(pmove!=NULL)
	{
		printf("%d %d ",pmove->xi3,pmove->zhi3);
		pmove=pmove->link;
	}
}
int main()
{
	int i=0,len1=0,len2=0,j=0,k=0; char c;
	while(c!='\n')
	{
		scanf("%d%d%c",&s1[len1].xi1,&s1[len1].zhi1,&c);
		len1++; 
	}
	c=' ';
	while(c!='\n')
	{
		scanf("%d%d%c",&s2[len2].xi2,&s2[len2].zhi2,&c);
		len2++;
	}
	while(i<len1)
	{
		while(j<len2)
		{
			s3[k].xi3=s1[i].xi1*s2[j].xi2; s3[k].zhi3=s1[i].zhi1+s2[j].zhi2;
			s3[k].link=NULL;
			j++; k++;
		}
		i++; j=0;
	}
	i=0;
	sort(s3,k);
	struct line3* headnode=createlist();
	makelist(headnode,k,s3);
	combine(headnode);
	printflist(headnode);
	return 0;
}


