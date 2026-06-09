#include<stdio.h>
#include<stdlib.h>
struct yi{
	int xi1;
	int zhi1;
	struct yi *next1;
};
struct er{
	int xi2;
	int zhi2;
	struct er *next2;
};
int A, B, n, k, cx[2000], cz[2000], l, h, L, H, i, j, J, J1, mjz, mjx, z;
char ch;
int main()
{
	struct yi *first1, *a;
	struct er *first2, *b;
	first1=a=(struct yi*)malloc(sizeof(struct yi));
		do
	{
		scanf("%d %d%c", &A, &B, &ch);
		a->xi1=A; a->zhi1=B;
		a->next1=(struct yi*)malloc(sizeof(struct yi));
		a=a->next1;
		l=l+1;
		
	}while(ch!='\n');
	a=NULL;
	a=first1;
	first2=b=(struct er*)malloc(sizeof(struct er));
		do
	{
		scanf("%d %d%c", &A, &B, &ch);
		b->xi2=A; b->zhi2=B;
		b->next2=(struct er*)malloc(sizeof(struct er));
		b=b->next2;
		h=h+1;
	}while(ch!='\n');
	b=NULL;
	b=first2;
	i=H=L=0;
	while(L<l)
	{
		while(H<h)
		{
			cx[i]=(b->xi2)*(a->xi1);
			cz[i]=(b->zhi2)+(a->zhi1);
			i++;
			H++;
			b=b->next2;
		}
		H=0;
		a=a->next1; b=first2;
		L++;
	}
	z=l*h;
	i=0;
	j=1;
	while(i<z)
	{
		J=j;
		while(J<z)
		{
			if(cz[i]==cz[J])
			{
				cx[i]=cx[i]+cx[J];
				J1=J;
				while(J1<z-1)
				{
					cz[J1]=cz[J1+1];
					cx[J1]=cx[J1+1];
					J1++;
				}
				cx[z-1]=cz[z-1]=0;
				z=z-1;
			}
			else
			{
				J=J+1;
			}
		}
		i++; j++;
	}
	for(k=0;k<z-1;k++)
	{
		for(n=0;n<z-1;n++)
		{
			if(cz[n]<cz[n+1])
			{
				mjz=cz[n+1];
				cz[n+1]=cz[n];
				cz[n]=mjz;
				mjx=cx[n+1];
				cx[n+1]=cx[n];
				cx[n]=mjx;
			}
		}
	}
	k=0;
	while(k<z)
	{
		printf("%d %d ", cx[k], cz[k]);
		k=k+1;
	}
	return 0;
}



