#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct DXS{
	int XS;
	int ZS;
};
int cmp(const void *p1,const void *p2)
{
	struct DXS*a=(struct DXS*)p1;
	struct DXS*b=(struct DXS*)p2;
	if(a->ZS>b->ZS)return -1;
	else return 1;
}
int multi(struct DXS A[],struct DXS B[],struct DXS C[],int m,int n)
{
	int i,j,k=0,tmpX,tmpZ,num=0,flag;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			tmpX=A[i].XS*B[j].XS;
			tmpZ=A[i].ZS+B[j].ZS;
			flag=0;
			for(k=0;k<num;k++)
			{
				if(tmpZ==C[k].ZS)
				{
					C[k].XS+=tmpX;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				C[num].XS=tmpX;
				C[num].ZS=tmpZ;
				num++;
			}
		}
	}
	return num;
}

int main()
{
	
	struct DXS A[1000],B[1000],C[1000];
	int i=0;
	char c;
	do{
		scanf("%d%d",&A[i].XS,&A[i].ZS);
		i++;
	}while((c=getchar())!='\n');
	int j=0;
	do{
		scanf("\n%d%d",&B[j].XS,&B[j].ZS);
		j++;
	}while((c=getchar())!='\n');
	/*while(sscanf(s1,"%d%d",&A[i].XS,&A[i].ZS)>0)
	{
		i++;
	}
	int j=0;
	while(sscanf(s2,"%d%d",&B[j].XS,&B[j].ZS)>0)
	{
		j++;
	}*/
	
	int n=multi(A,B,C,i,j);
	qsort(C,n,sizeof(struct DXS),cmp);
	for(i=0;i<n;i++)
	{
		if(C[i].XS!=0)
		{
			printf("%d %d ",C[i].XS,C[i].ZS);
		}
	}
	return 0;
}

