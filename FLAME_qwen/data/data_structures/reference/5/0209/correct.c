#include<stdio.h>
#include<stdlib.h>
struct Trem_struct{
	int coefficient;
	int index;
}head1[20],head2[20],head_out[405];
int cmp(const void *p1,const void *p2){
	return ((struct Trem_struct*)p2)->index -((struct Trem_struct*)p1)->index;
}
int i=0,j,k,ii,jj,kk,count;
int main()
{
	
	char c;
	do{
		scanf("%d%d",&head1[i].coefficient,&head1[i].index);
		i++;
	}while(getchar()!='\n');
	ii=i;
	do{
		scanf("%d%d",&head2[j].coefficient,&head2[j].index);
		j++;
	}while(getchar()!='\n');
	jj=j;
	for(i=0;i<ii;i++)
	{
		for(j=0;j<jj;j++)
		{
			head_out[count].coefficient=head1[i].coefficient*head2[j].coefficient;
			head_out[count].index=head1[i].index+head2[j].index;
			count++;
		}
	}
	qsort(head_out,count,sizeof(struct Trem_struct),cmp);
	for(k=0;k<count-1;k++)
	{
		if(head_out[k].index==head_out[k+1].index)
		{
			head_out[k+1].coefficient+=head_out[k].coefficient;
			head_out[k].coefficient=0;
		}
	}
	for(k=0;k<count;k++)
	{
		if(head_out[k].coefficient!=0)
		{
			printf("%d %d ",head_out[k].coefficient,head_out[k].index);
		}
	}
	return 1;

}





