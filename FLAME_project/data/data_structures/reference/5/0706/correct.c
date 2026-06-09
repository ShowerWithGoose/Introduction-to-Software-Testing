#include<stdio.h>
#include<stdlib.h>
int a[1000008][4];
typedef struct node{
	int coe;
	int index;
	int flag;
	struct node *pnext;
}multi1,multi2;
int main()
{
	char ge;
	multi1 *head1=(multi1 *)malloc(sizeof(multi1));
	multi1 *r1,*s1;
	r1=head1;
	while(1)
	{
		s1=(multi1 *)malloc(sizeof(multi1));
		scanf("%d%d",&s1->coe,&s1->index);
		s1->flag=0;
		r1->pnext=s1;
		r1=s1;
		scanf("%c",&ge);
		if(ge!=' ')
		{
			r1->flag=1;
			break;
		}
	}
	multi2 *head2=(multi2 *)malloc(sizeof(multi2));
	multi2 *r2,*s2;
	r2=head2;
	while(1)
	{
		s2=(multi2 *)malloc(sizeof(multi2));
		scanf("%d%d",&s2->coe,&s2->index);
		s2->flag=0;
		r2->pnext=s2;
		r2=s2;
		scanf("%c",&ge);
		if(ge!=' ')
		{
			r2->flag=1;
			break;
		}
	}
	multi1 *x1;
	multi2 *x2;
	x1=head1->pnext;
	x2=head2->pnext;
	int i=0,j=0,k=0;
	while(x1->flag==0)
	{
		while(x2->flag==0)
		{
			a[i][1]=x1->coe*x2->coe;
			a[i][2]=x1->index+x2->index;
			i++;
			x2=x2->pnext;
		}
		a[i][1]=x1->coe*x2->coe;
		a[i][2]=x1->index+x2->index;
		i++;
		x2=head2->pnext;
		x1=x1->pnext;
	} 
	while(x2->flag==0)
	{
		a[i][1]=x1->coe*x2->coe;
		a[i][2]=x1->index+x2->index;
		i++;
		x2=x2->pnext;
	}
	a[i][1]=x1->coe*x2->coe;
	a[i][2]=x1->index+x2->index;
	i++;
	for(j=0;j<i;j++)
	{
		if(a[j][2]==-1)
		continue;
		for(k=j+1;k<i;k++)
		{
			if(a[j][2]==a[k][2])
			{
				a[j][1]+=a[k][1];
				a[k][1]=0;
				a[k][2]=-1;
			}
		}
	}
	int tmp1,tmp2;
	for(j=0;j<i;j++)
	for(k=0;k<i-j-1;k++)
	{
		if(a[k][2]<a[k+1][2])
		{
			tmp1=a[k][1];
			tmp2=a[k][2];
			a[k][1]=a[k+1][1];
			a[k][2]=a[k+1][2];
			a[k+1][1]=tmp1;
			a[k+1][2]=tmp2; 
		}
	}
	for(k=0;k<i;k++)
	{
		if(a[k][2]==-1)
		break;
		printf("%d %d ",a[k][1],a[k][2]);
	}
	return 0;
}




